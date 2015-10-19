#pragma once
#include <functional>
#include <algorithm>
#include <atomic>
#include <memory>
#include <mutex>
#include <list>
#include <vector>

#include "ThreadPool/ThreadPool.hpp"
#include "../../../Systems/SystemInterface.hpp"

class Scheduler : private ThreadPool {
public:
	Scheduler();

	~Scheduler();
	void getMainTasks();

	void infiniteLoop();

private:
	void pushMainTask(std::function<std::list<std::function<void(void)>>(void)>);
	void pushMainTaskFromSystem(std::weak_ptr<SystemInterface> Sys);
	std::mutex queueMutex_;
	std::vector<std::weak_ptr<SystemInterface>> systems_;
	std::list<std::function<std::list<std::function<void(void)>>(void)>> mainTasks_;
	std::atomic <char> remainingMainTasks_;
	std::list<std::function<void(void)>> expandedTasks_;
	std::atomic <int> remainingExpandedTasks_;
	unsigned int threadCount_;
	std::atomic<char> idleThreads_; 

};
