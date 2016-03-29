#pragma once

#include <SFML/Graphics.hpp>

#include "../System.hpp"


class GraphicSystem: public System{
public:
	GraphicSystem();
	~GraphicSystem();
	int mainTask(std::weak_ptr<TaskManagerInterface>);

protected:
	sf::RenderWindow rwindow_;
};
