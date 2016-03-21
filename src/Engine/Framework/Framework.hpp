#pragma once

#include <atomic>

#include "./Scheduler/Scheduler.hpp"
#include "./UEntities/UScene.hpp"


class Framework{
public:

	Framework(std::weak_ptr<TaskManagerInterface>, std::vector<std::weak_ptr<SystemInterface>>);
	~Framework();

	void gameLoop();


protected:
	std::atomic<bool> getStatus();
	std::atomic<bool> active;
	Scheduler scheduler_;

	std::vector<std::shared_ptr<UScene>> scenes_;

};
