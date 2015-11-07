#include "Scheduler.hpp"

Scheduler::Scheduler(){
	this->emptyQueue_=false;
}

Scheduler::~Scheduler(){

}

void Scheduler::addManager(std::weak_ptr<ManagerInterface> mngr){
	this->managers_.emplace(this->managers_.end(),mngr);
}

void Scheduler::infiniteLoop(const unsigned int id){
	while(this->getThreadStatus(id)){
		//condition variable if queue is empty
		{
		std::unique_lock<std::mutex> lck(this->refillMutex_);
		while(this->emptyQueue_){
			this->emptyQcv.wait(lck);
		}
		}
		if(this->expandedTasks_.size()==0){
			//lock condition variable
			std::unique_lock<std::mutex> lck(this->refillMutex_);
			this->emptyQueue_=true;

			if(this->mainTasks_.size()==0){
				this->fillMainQueue();
			}
			this->callMainTask();

			//notify all condition variable
			this->emptyQueue_=false;
			this->emptyQcv.notify_all();
			
		} else {
			this->callExpandedTask();
		}
	}

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
	task=*(this->mainTasks_.begin());
	this->mainTasks_.pop_front();
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
	task=*(this->expandedTasks_.begin());
	this->expandedTasks_.pop_front();
	}
	task();
}
