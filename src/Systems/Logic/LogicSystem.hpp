#pragma once

#include "../System.hpp"

class LogicSystem : public System{
public:
	LogicSystem();
	~LogicSystem();
	int mainTask(std::weak_ptr<TaskManagerInterface>);

protected:
	LogicScene scene_;
};
