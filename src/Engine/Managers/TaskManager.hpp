#pragma once
#include <mutex>
#include <condition_variable>

#include "./Manager.hpp"
#include "./ThreadPool/ThreadPool.hpp"

class System;

class TaskManager: public Manager, public ThreadPool{
public:
	TaskManager(int _threads);
	TaskManager();
	~TaskManager();

	int threadLoop(int);
	void markAllIdle();
	void markStartActive();
	void addTask(std::function<int(void)>);

protected:

	void makeThreadIdle(int);
	void makeThreadActive(int);

	std::mutex queueMutex_;
	std::list<std::function<int(void)>> taskQueue_;

	std::condition_variable areAllIdleCV_;//Condition variable for working threads
	std::mutex areAllIdleMtx_;
	std::atomic<bool> areAllIdle_;

	std::condition_variable proceedMainCV_;//Condition variable for main thread call for execution
	std::mutex proceedMainMtx_;
	std::atomic<bool> proceedMain_;

	std::vector<std::weak_ptr<System>> systems_;
	std::atomic<unsigned int> activeThreads_;
	std::vector<bool> isThreadActive_;
};