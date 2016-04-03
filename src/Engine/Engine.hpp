#pragma once

#include "./Framework/Framework.hpp"
#include "./Managers/MgrBundle.hpp"

class Engine {
public:
	Engine()=delete;
	Engine(ManagerInterfaceBundle&);
	~Engine();
	void addSystemVector(std::vector<std::weak_ptr<SystemInterface>>);
	void gameLoop();
protected:
	ManagerInterfaceBundle mgrBundle_;

	Framework framework_;

	std::vector<std::weak_ptr<SystemInterface>> systems_;
};
