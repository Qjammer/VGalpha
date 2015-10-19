#include "Scheduler.hpp"

Scheduler::Scheduler(){

}

Scheduler::~Scheduler(){

}

void Scheduler::getMainTasks(){
	for_each(this->systems_.begin(),this->systems_.end(),std::bind(&Scheduler::pushMainTaskFromSystem,this,std::placeholders::_1));

}

void Scheduler::infiniteLoop(){

}

void Scheduler::pushMainTaskFromSystem(std::weak_ptr<SystemInterface> Sys){
	this->pushMainTask(std::function<std::list<std::function<void(void)>>(void)>(std::bind(&SystemInterface::mainTask,Sys.lock().get())));
}

void Scheduler::pushMainTask(std::function<std::list<std::function<void(void)>>(void)> mainTask){
	this->mainTasks_.push_back(mainTask);
}