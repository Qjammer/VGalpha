#pragma once

#include "./GraphicSystem.hpp"
#include "../SystemInterface.hpp"

class GraphicSystemInterface: public SystemInterface{
public:
	GraphicSystemInterface(std::weak_ptr<GraphicSystem>);
	~GraphicSystemInterface();
};
