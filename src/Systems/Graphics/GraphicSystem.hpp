#pragma once

#include <SFML/Graphics.hpp>
#include "../System.hpp"
#include "./GraphicScene.hpp"


class GraphicSystem: public System{
public:
	GraphicSystem(ManagerInterfaceBundle);
	~GraphicSystem();
	int mainTask();

	void loadScene(std::stringstream){};
	void saveScene(std::string){};
	void objectFactory(std::stringstream){};

protected:
	GraphicScene scene_;
};
