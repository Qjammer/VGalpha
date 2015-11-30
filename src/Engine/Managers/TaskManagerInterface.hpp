#pragma once
#include "./TaskManager.hpp"

class TaskManagerInterface{
public:
	TaskManagerInterface(unsigned int);
	TaskManagerInterface();
	~TaskManagerInterface();
	void mainProcess();
	void addTask(std::function<int(void)>);
	void addTaskList(std::list<std::function<int(void)>>);
//protected:
	std::shared_ptr<TaskManager> instance_;
protected:
};
