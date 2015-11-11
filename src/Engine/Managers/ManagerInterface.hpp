#pragma once

#include "Manager.hpp"
#include <list>
#include <functional>

class ManagerInterface{
public:
	//Methods ONLY
	ManagerInterface(Manager* _mngr);
	~ManagerInterface();

	std::list<std::function<int(void)>> getTaskListFromMngr();

protected:
	//Variables (obv)
	Manager* mngr_;
};