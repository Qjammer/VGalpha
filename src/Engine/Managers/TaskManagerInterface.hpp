#pragma once
#include "./ManagerInterface.hpp"
#include "./TaskManager.hpp"

class TaskManagerInterface:public ManagerInterface<TaskManager>{
public:
	TaskManagerInterface(unsigned int);
	TaskManagerInterface(std::shared_ptr<TaskManager>);
	TaskManagerInterface();
	~TaskManagerInterface();
	void mainProcess();
	void addTask(std::function<int(void)>);
	void addTaskList(std::list<std::function<int(void)>>);
protected:

};
