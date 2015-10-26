#include "Scheduler.hpp"

Scheduler::Scheduler(){

}

Scheduler::~Scheduler(){

}

void Scheduler::infiniteLoop(){
	while(this->running_){
		//condition variable if queue is empty
		if(this->expandedTasks_.size()==0){
			//lock condition variable
			if(this->mainTasks_.size()==0){
				this->fillMainQueue();
			} else {
				this->callMainTask();
			}
			//notify all condition variable
		} else {
			this->callExpandedTask();
		}
	}

}

void Scheduler::pushMainTask(std::function<std::list<std::function<void(void)>>(void)> mainTask){
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