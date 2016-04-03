#pragma once

#include "../System.hpp"
#include "./LogicScene.hpp"

class LogicSystem : public System{
public:
	LogicSystem(ManagerInterfaceBundle);
	~LogicSystem();
	int mainTask();

	void loadScene(std::stringstream){};
	void saveScene(std::string){};
	void objectFactory(std::stringstream){};

protected:
	LogicScene scene_;
};
