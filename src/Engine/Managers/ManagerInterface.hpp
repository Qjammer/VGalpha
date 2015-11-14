#pragma once

#include "Manager.hpp"
#include <list>
#include <functional>

class ManagerInterface{
public:
	//Methods ONLY
	ManagerInterface();
	~ManagerInterface();


protected:
	//Variables (obv)
	Manager* mngr_;

};