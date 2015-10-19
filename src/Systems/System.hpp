#pragma once
#include <functional>
#include <list>


class System
{
public:
	friend class SystemInterface;
	System();
	~System();
	virtual std::list<std::function<void(void)>>& mainTask()=0;//Returns sub-tasks
};
