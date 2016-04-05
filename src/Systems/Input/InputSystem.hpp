#pragma once

#include "../System.hpp"
#include "InputScene.hpp"

class InputSystem : public System{
public:
	InputSystem(ManagerInterfaceBundle);
	~InputSystem()=default;
	int mainTask();

	void loadScene(std::stringstream){};
	void saveScene(std::string){};
	void objectFactory(std::stringstream){};

protected:
	InputScene scene_;
};
