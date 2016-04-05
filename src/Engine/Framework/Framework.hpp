#pragma once

#include <atomic>

#include "./Scheduler/Scheduler.hpp"
#include "./UEntities/UScene.hpp"


class Framework{
public:
	Framework()=delete;
	Framework(ManagerInterfaceBundle, std::vector<std::weak_ptr<SystemInterface>>);
	~Framework();

	void gameLoop();
	void addSystems(std::vector<std::weak_ptr<SystemInterface>>);


protected:
	std::atomic<bool>& getStatus();
	std::atomic<bool> active_;
	Scheduler scheduler_;

	ManagerInterfaceBundle mgrBundle_;

	std::shared_ptr<UScene> scene_;

};
