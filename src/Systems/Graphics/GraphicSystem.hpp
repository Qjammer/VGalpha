#pragma once

#include <SFML/Graphics.hpp>
#include "../System.hpp"
#include "./GraphicObject.hpp"


class GraphicSystem: public System{
public:
	GraphicSystem(ManagerInterfaceBundle);
	~GraphicSystem();
	int mainTask();

protected:
	sf::RenderWindow rwindow_;
};
