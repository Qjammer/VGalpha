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
	Scheduler(int _threads);

	~Scheduler();

	void infiniteLoop(const unsigned int);
	void addManager(std::weak_ptr<ManagerInterface> mngr);

	void initThreadLoop(const unsigned int);
	void stopThreadLoop(const unsigned int);

	void initAllThreads();
	void stopAllThreads();
	void joinAllThreads();

	enum SCH_ERR:int{
		NO_ERR,
		PHONY_TASK
	};

protected:
	void fillMainQueue();
	int callMainTask();
	int callExpandedTask();

	void pushMainTask(const std::function<std::list<std::function<int(void)>>(void)>&);
	void pushMainTaskFromManager(std::weak_ptr<ManagerInterface> mngr);

	std::list<std::function<std::list<std::function<int(void)>>(void)>> mainTasks_;
	std::mutex mainQueueMutex_;

	std::list<std::function<int(void)>> expandedTasks_;
	std::mutex expandedQueueMutex_;

	std::vector<std::weak_ptr<ManagerInterface>> managers_;

	std::mutex refillMutex_;
	std::atomic<bool> emptyExpandedQueue_;
	std::atomic<bool> emptyMainQueue_;
	std::atomic<bool> running_;

};
