#pragma once
#include <chrono>
#include <memory>
#include "../../Managers/TaskManager.hpp"


class Scheduler {
public:
	Scheduler();
	~Scheduler();
protected:

	void Execute();
	std::atomic<bool> active;
	unsigned int ticksPerCycle;
	unsigned int unusedTicks;
	std::chrono::duration<unsigned int,std::milli> tick_;
	std::vector<std::weak_ptr<System>> systems_;
	std::weak_ptr<TaskManager> taskManager_;
};
