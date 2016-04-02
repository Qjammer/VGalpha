#pragma once
#include "./ManagerInterface.hpp"
#include "./TaskManager.hpp"

class TaskManagerInterface:public ManagerInterface<TaskManager>{
public:
	TaskManagerInterface(std::shared_ptr<TaskManager>&);
	TaskManagerInterface()=delete;
	~TaskManagerInterface();
	void mainProcess();
	void addTask(std::function<int(void)>);
	void addTaskList(std::list<std::function<int(void)>>);
protected:

};
