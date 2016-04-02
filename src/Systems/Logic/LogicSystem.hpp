#pragma once

#include "../System.hpp"
#include "./LogicScene.hpp"

class LogicSystem : public System{
public:
	LogicSystem(ManagerInterfaceBundle);
	~LogicSystem();
	int mainTask(std::weak_ptr<TaskManagerInterface>);

protected:
	LogicScene scene_;
};
