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
		lck.lock();//Stop before they know their status
		lck.unlock();
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

void Scheduler::initAllThreads(){
	auto initAll([this](){
		std::lock_guard<std::mutex>(this->refillMutex_);
		for(unsigned int i=1;i<this->threadCount_;i++){
			this->initThreadLoop(i);
		}
		return 0;
	});
	{
	std::lock_guard<std::mutex>(this->expandedQueueMutex_);
	this->expandedTasks_.push_back(initAll);
	}
	this->initThreadLoop(0);
}
void Scheduler::stopAllThreads(){
	auto stopAll([this](){
		std::lock_guard<std::mutex>(this->refillMutex_);
		for(unsigned int i=this->threadCount_-1;i>0;i--){
			this->stopThreadLoop(i);
		}
		this->stopThreadLoop(0);
		return 0;

	});
	{
	std::lock_guard<std::mutex>(this->expandedQueueMutex_);
	this->expandedTasks_.push_back(stopAll);
	}

}

void Scheduler::joinAllThreads(){
	for(unsigned int i=this->threadCount_-1;i>0;--i){
		this->joinThread(i);
	}
}

void Scheduler::pushMainTask(const std::function<std::list<std::function<int(void)>>(void)>& mainTask){
	this->mainTasks_.push_back(mainTask);
}

void Scheduler::pushMainTaskFromManager(std::weak_ptr<ManagerInterface> mngr){
	this->pushMainTask(std::function<std::list<std::function<int(void)>>(void)>(std::bind(&ManagerInterface::mainTask,mngr.lock().get())));
}

void Scheduler::fillMainQueue(){
	std::lock_guard<std::mutex> lock(this->mainQueueMutex_);
	for(unsigned int i=0;i<this->managers_.size();i++){
		this->pushMainTaskFromManager(this->managers_[i]);
	}
}

int Scheduler::callMainTask(){
	std::function<std::list<std::function<int(void)>>(void)> task;
	Scheduler::SCH_ERR ret;
	{
	std::lock_guard<std::mutex> lock(this->mainQueueMutex_);
	if(this->mainTasks_.size()!=0){
		task=*(this->mainTasks_.begin());
		this->mainTasks_.pop_front();
		ret=Scheduler::SCH_ERR::NO_ERR;
	} else {
		this->emptyMainQueue_=true;
		task=[](){return std::list<std::function<int(void)>>();};
		ret=Scheduler::SCH_ERR::PHONY_TASK;
	}
	}

	{
	std::lock_guard<std::mutex> lock(this->expandedQueueMutex_);
	this->expandedTasks_.splice(this->expandedTasks_.begin(),task());
	}
	return ret;
}

int Scheduler::callExpandedTask(){
	std::function<int(void)> task;
	{
	std::lock_guard<std::mutex> lock(this->expandedQueueMutex_);
	if(this->expandedTasks_.size()!=0){
	task=*(this->expandedTasks_.begin());
	this->expandedTasks_.pop_front();
	} else {
		this->emptyExpandedQueue_=true;
		task=[](){return Scheduler::SCH_ERR::PHONY_TASK;};
	}
	}
	return task();
}
