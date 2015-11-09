#pragma once
#include <list>
#include <functional>

class ManagerInterface{
public:
	ManagerInterface();
	~ManagerInterface();

	virtual std::list<std::function<void(void)>> mainTask()=0;

};