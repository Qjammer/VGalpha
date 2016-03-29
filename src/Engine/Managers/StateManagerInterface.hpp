#pragma once

#include "./StateManager.hpp"
#include "./ManagerInterface.hpp"

class StateManagerInterface: public ManagerInterface<StateManager>{
public:
	StateManagerInterface(std::shared_ptr<StateManager>);
	~StateManagerInterface();
};
