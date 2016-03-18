#pragma once
#include <chrono>
#include <memory>
#include <iostream>
#include "../../Managers/TaskManagerInterface.hpp"
#include "../../../Systems/SystemInterface.hpp"
#include "../../../Utilities/Logger.hpp"


class Scheduler {
public:
	Scheduler(std::weak_ptr<TaskManagerInterface>, std::vector<std::weak_ptr<SystemInterface>>);
	~Scheduler();

	void Execute();

protected:
	std::list<std::weak_ptr<SystemInterface>> viableSystems();

	std::chrono::system_clock::duration timeSinceLastTick() const;
	std::chrono::system_clock::duration leftoverTickTime() const;
	void updateTimer();
	std::string clockUnits() const;

	std::atomic<bool> active_;

	std::chrono::system_clock::duration unusedTime_;//I presume the units of these are nanoseconds on my machine
	std::chrono::system_clock::duration timePerTick_;//It'd be nice to find a way to corroborate
	std::chrono::system_clock::time_point pastTick_;

	std::weak_ptr<TaskManagerInterface> taskManager_;
	std::vector<std::weak_ptr<SystemInterface>> systems_;
};
