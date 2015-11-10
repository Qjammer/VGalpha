#include "Scheduler.hpp"

Scheduler::Scheduler():Scheduler(1){
	
}

Scheduler::Scheduler(int _threads):ThreadPool(_threads),emptyExpandedQueue_(false),emptyMainQueue_(false),running_(true){
	
}


Scheduler::~Scheduler(){

}



void Scheduler::infiniteLoop(const unsigned int id){
	printf("entering infinite loop,thread:%i\n",id);
	std::unique_lock<std::mutex> lck(this->refillMutex_,std::defer_lock);//doesnt lock on construction
	while(this->getThreadStatus(id)){
		lck.lock();
		lck.unlock();
		if(this->emptyExpandedQueue_){
			lck.lock();
			if(this->emptyMainQueue_){
				this->fillMainQueue();
			}
			this->callMainTask();
			this->emptyExpandedQueue_=false;
			lck.unlock();
		}
		this->callExpandedTask();
	}
}

void Scheduler::addManager(std::weak_ptr<ManagerInterface> mngr){
	this->managers_.emplace(this->managers_.end(),mngr);
}

void Scheduler::initThreadLoop(const unsigned int _thread){
	this->initThread(_thread,[this](int _th){this->infiniteLoop(_th);});
}
void Scheduler::stopThreadLoop(const unsigned int _thread){
	this->stopThread(_thread);
}

void Scheduler::pushMainTask(const std::function<std::list<std::function<void(void)>>(void)>& mainTask){
	this->mainTasks_.push_back(mainTask);
}

void Scheduler::pushMainTaskFromManager(std::weak_ptr<ManagerInterface> mngr){
	this->pushMainTask(std::function<std::list<std::function<void(void)>>(void)>(std::bind(&ManagerInterface::mainTask,mngr.lock().get())));
}

void Scheduler::fillMainQueue(){
	std::lock_guard<std::mutex> lock(this->mainQueueMutex_);
	for(unsigned int i=0;i<this->managers_.size();i++){
		this->pushMainTaskFromManager(this->managers_[i]);
	}
}

void Scheduler::callMainTask(){
	std::function<std::list<std::function<void(void)>>(void)> task;
	{
	std::lock_guard<std::mutex> lock(this->mainQueueMutex_);
	if(this->mainTasks_.size()!=0){
		task=*(this->mainTasks_.begin());
		this->mainTasks_.pop_front();
	} else {
		this->emptyMainQueue_=true;
		task=[](){return std::list<std::function<void(void)>>();};
	}
	}

	{
	std::lock_guard<std::mutex> lock(this->expandedQueueMutex_);
	this->expandedTasks_.splice(this->expandedTasks_.begin(),task());
	}
}

void Scheduler::callExpandedTask(){
	std::function<void(void)> task;
	{
	std::lock_guard<std::mutex> lock(this->expandedQueueMutex_);
	if(this->expandedTasks_.size()!=0){
	task=*(this->expandedTasks_.begin());
	this->expandedTasks_.pop_front();
	} else {
		this->emptyExpandedQueue_=true;
		task=[](){};
	}
	}
	task();
}
