#include "./TaskManagerInterface.hpp"




TaskManagerInterface::TaskManagerInterface(std::shared_ptr<TaskManager>& _tsk):ManagerInterface(_tsk){

}



TaskManagerInterface::~TaskManagerInterface(){

}

void TaskManagerInterface::mainProcess(){
	this->getInstance()->mainProcess();
}

// std::shared_ptr<TaskManager> TaskManagerInterface::getInstance(){
// 	return this->instance_.lock();
// }

void TaskManagerInterface::addTask(std::function<int(void)> tsk){
	this->getInstance()->addTask(tsk);
}
void TaskManagerInterface::addTaskList(std::list<std::function<int(void)>> tsklst){
	this->getInstance()->addTaskList(tsklst);
}
