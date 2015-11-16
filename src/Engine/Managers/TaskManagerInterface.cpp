#include "./TaskManagerInterface.hpp"

TaskManagerInterface::TaskManagerInterface(int _thr):instance_(new TaskManager(_thr)){
	
}

TaskManagerInterface::TaskManagerInterface():TaskManagerInterface(1){
	
}

TaskManagerInterface::~TaskManagerInterface(){
	
}

void TaskManagerInterface::addTask(std::function<int(void)> tsk){
	this->instance_->addTask(tsk);
}
void TaskManagerInterface::addTaskList(std::list<std::function<int(void)>> tsklst){
	this->instance_->addTaskList(tsklst);
}