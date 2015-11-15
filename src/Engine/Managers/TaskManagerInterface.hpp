#pragma once
#include "./TaskManager.hpp"

class TaskManagerInterface{
public:
	TaskManagerInterface(int);
	TaskManagerInterface();
	~TaskManagerInterface();
	void addTask(std::function<int(void)>);
	void addTaskList(std::list<std::function<int(void)>>);
//protected:
	std::shared_ptr<TaskManager> instance_;
protected:
};
