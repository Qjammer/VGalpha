#include "Scheduler.hpp"

Scheduler::Scheduler(){

}

Scheduler::~Scheduler(){

}

void Scheduler::getMainTasks(){
	for_each(this->managers_.begin(),this->managers_.end(),std::bind(&Scheduler::pushMainTaskFromManager,this,std::placeholders::_1));

}

void Scheduler::infiniteLoop(){

}

void Scheduler::pushMainTaskFromManager(std::weak_ptr<ManagerInterface> mngr){
	this->pushMainTask(std::function<std::list<std::function<void(void)>>(void)>(std::bind(&ManagerInterface::mainTask,mngr.lock().get())));
}

void Scheduler::pushMainTask(std::function<std::list<std::function<void(void)>>(void)> mainTask){
	this->mainTasks_.push_back(mainTask);
}