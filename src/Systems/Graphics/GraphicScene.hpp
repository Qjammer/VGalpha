#pragma once

#include "./GraphicObject.hpp"
#include "../EntityExtensions/SceneExtension.hpp"

class GraphicScene:public SceneExtension{
public:
	GraphicScene();
	sf::RenderWindow rwindow_;
	std::vector<std::shared_ptr<GraphicObject>> objects_;
};
