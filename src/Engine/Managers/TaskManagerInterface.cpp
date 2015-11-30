#include "./TaskManagerInterface.hpp"

TaskManagerInterface::TaskManagerInterface(unsigned int _thr):instance_(std::make_shared<TaskManager>(_thr)){
	
}

TaskManagerInterface::TaskManagerInterface():TaskManagerInterface(1){
	
}

TaskManagerInterface::~TaskManagerInterface(){
	
}

void TaskManagerInterface::mainProcess(){
	this->instance_->mainProcess();
}

void TaskManagerInterface::addTask(std::function<int(void)> tsk){
	this->instance_->addTask(tsk);
}
void TaskManagerInterface::addTaskList(std::list<std::function<int(void)>> tsklst){
	this->instance_->addTaskList(tsklst);
}