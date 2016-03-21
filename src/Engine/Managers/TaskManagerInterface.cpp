#include "./TaskManagerInterface.hpp"

TaskManagerInterface::TaskManagerInterface(unsigned int _thr):instance_(std::make_shared<TaskManager>(_thr)){

}


TaskManagerInterface::TaskManagerInterface(std::shared_ptr<TaskManager> _tsk):instance_(_tsk){

}

TaskManagerInterface::TaskManagerInterface():TaskManagerInterface(std::make_shared<TaskManager>()){

}

TaskManagerInterface::~TaskManagerInterface(){

}

void TaskManagerInterface::mainProcess(){
	this->getInstance()->mainProcess();
}

std::shared_ptr<TaskManager> TaskManagerInterface::getInstance(){
	return this->instance_.lock();
}

void TaskManagerInterface::addTask(std::function<int(void)> tsk){
	this->getInstance()->addTask(tsk);
}
void TaskManagerInterface::addTaskList(std::list<std::function<int(void)>> tsklst){
	this->getInstance()->addTaskList(tsklst);
}
