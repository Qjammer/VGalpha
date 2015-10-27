#pragma once
#include <functional>
#include <algorithm>
#include <atomic>
#include <memory>
#include <mutex>
#include <list>
#include <vector>
#include <condition_variable>

#include "ThreadPool/ThreadPool.hpp"
#include "../../Managers/ManagerInterface.hpp"

class Scheduler : private ThreadPool {
public:
	Scheduler();

	~Scheduler();

	void infiniteLoop();

private:
	void fillMainQueue();
	void callMainTask();
	void callExpandedTask();

	void pushMainTask(std::function<std::list<std::function<void(void)>>(void)>);
	void pushMainTaskFromManager(std::weak_ptr<ManagerInterface> mngr);

	std::list<std::function<std::list<std::function<void(void)>>(void)>> mainTasks_;
	std::mutex mainQueueMutex_;

	std::list<std::function<void(void)>> expandedTasks_;
	std::mutex expandedQueueMutex_;

	std::vector<std::weak_ptr<ManagerInterface>> managers_;
	unsigned int threadCount_;
	std::mutex refillMutex_;
	std::atomic<bool> emptyQueue_;
	std::condition_variable emptyQcv;
	std::atomic<bool> running_;

};
