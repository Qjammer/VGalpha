#pragma once

#include "./LogicSystem.hpp"
#include "../SystemInterface.hpp"

class LogicSystemInterface: public SystemInterface{
public:
	LogicSystemInterface(std::weak_ptr<LogicSystem>);
	~LogicSystemInterface();
};
