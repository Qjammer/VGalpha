#pragma once

#include <vector>
#include <mutex>
#include <list>

class Manager
{
public:
	//Methods ONLY
	Manager();
	~Manager();
	std::list<std::function<int(void)>> getTaskList();

protected:
	//Methods
	virtual int updateTaskList();

	//Variables
	std::list<std::function<int(void)>> taskList_;
};
