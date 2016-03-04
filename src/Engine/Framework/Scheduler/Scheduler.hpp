#pragma once
#include <chrono>
#include <memory>
#include "../../Managers/TaskManagerInterface.hpp"
#include "../../../Systems/SystemInterface.hpp"


class Scheduler {
public:
	Scheduler();
	~Scheduler();

	void Execute();

protected:
	std::list<std::weak_ptr<SystemInterface>> viableSystems();

	std::atomic<bool> active;
	unsigned int ticksPerCycle;
	unsigned int unusedTicks;
	std::chrono::duration<unsigned int,std::milli> tick_;
	std::vector<std::weak_ptr<SystemInterface>> systems_;
	std::weak_ptr<TaskManagerInterface> taskManager_;
};
