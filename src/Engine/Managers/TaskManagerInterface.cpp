#include "./TaskManagerInterface.hpp"

TaskManagerInterface::TaskManagerInterface(unsigned int _thr):instance_(std::make_shared<TaskManager>(_thr)){

}

TaskManagerInterface::TaskManagerInterface():instance_(std::make_shared<TaskManager>()){

}

TaskManagerInterface::~TaskManagerInterface(){

}

void TaskManagerInterface::mainProcess(){
	this->instance_->mainProcess();
}

std::shared_ptr<TaskManager> TaskManagerInterface::getInstance(){
	return this->instance_;
}

void TaskManagerInterface::addTask(std::function<int(void)> tsk){
	this->instance_->addTask(tsk);
}
void TaskManagerInterface::addTaskList(std::list<std::function<int(void)>> tsklst){
	this->instance_->addTaskList(tsklst);
}
