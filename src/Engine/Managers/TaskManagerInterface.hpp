#pragma once
#include "./TaskManager.hpp"

class TaskManagerInterface{
public:
	TaskManagerInterface(unsigned int);
	TaskManagerInterface(std::shared_ptr<TaskManager>);
	TaskManagerInterface();
	~TaskManagerInterface();
	void mainProcess();
	void addTask(std::function<int(void)>);
	void addTaskList(std::list<std::function<int(void)>>);
	std::shared_ptr<TaskManager> getInstance();
protected:
	std::weak_ptr<TaskManager> instance_;
};
