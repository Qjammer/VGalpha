#pragma once

#include <atomic>

#include "./Scheduler/Scheduler.hpp"
#include "./UEntities/UScene.hpp"


class Framework{
public:

	Framework(std::weak_ptr<TaskManager>, std::vector<std::weak_ptr<SystemInterface>>);
	~Framework();

	void gameLoop();


protected:
	std::atomic<bool>& getStatus();
	std::atomic<bool> active_;
	Scheduler scheduler_;

	std::shared_ptr<UScene> scene_;

};
