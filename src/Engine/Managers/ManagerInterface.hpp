#pragma once

#include "Manager.hpp"
#include <list>
#include <functional>
#include <memory>

class ManagerInterface{
public:
	//Methods ONLY
	ManagerInterface();
	~ManagerInterface();


protected:
	//Variables (obv)
	std::shared_ptr<Manager> mngr_;

};