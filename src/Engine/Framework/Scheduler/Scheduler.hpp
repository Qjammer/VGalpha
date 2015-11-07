#pragma once
#include <functional>
#include <algorithm>
#include <atomic>
#include <memory>
#include <mutex>
#include <list>
#include <vector>
#include <condition_variable>
#include <iostream>

#include "ThreadPool/ThreadPool.hpp"
#include "../../Managers/ManagerInterface.hpp"

class Scheduler : public ThreadPool {
public:
	Scheduler();

	~Scheduler();

	void infiniteLoop(const unsigned int);
	void addManager(std::weak_ptr<ManagerInterface> mngr);

protected:
	void fillMainQueue();
	void callMainTask();
	void callExpandedTask();

	void pushMainTask(const std::function<std::list<std::function<void(void)>>(void)>&);
	void pushMainTaskFromManager(std::weak_ptr<ManagerInterface> mngr);

	std::list<std::function<std::list<std::function<void(void)>>(void)>> mainTasks_;
	std::mutex mainQueueMutex_;

	std::list<std::function<void(void)>> expandedTasks_;
	std::mutex expandedQueueMutex_;

	std::vector<std::weak_ptr<ManagerInterface>> managers_;
	unsigned int threadCount_;
	std::mutex refillMutex_;
	std::atomic<bool> emptyQueue_;
	std::atomic<bool> refillingQueue_;
	std::condition_variable emptyQcv;
	std::atomic<bool> running_;

};
