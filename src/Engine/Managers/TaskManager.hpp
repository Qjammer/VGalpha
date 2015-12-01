#pragma once
#include <mutex>
#include <condition_variable>

#include "./Manager.hpp"
#include "./ThreadPool/ThreadPool.hpp"
#include "../../Utilities/Logger.hpp"

class System;

class TaskManager: public Manager, public ThreadPool{
public:
	TaskManager(unsigned int _threads);
	TaskManager();
	~TaskManager();

	void mainProcess();

	void addTask(std::function<int(void)>);
	void addTaskList(std::list<std::function<int(void)>>);
	void initThreadLoop(unsigned int);
	void wakeUpandJoinThread(unsigned int);
	void wakeUpandJoinAll();
	void markAllActive();
protected:

	void threadLoop(unsigned int);

	int callTask(unsigned int);

	void makeThreadActive(unsigned int);
	void makeThreadIdle(unsigned int);
	void markThreadIdle(unsigned int);

	void markAllIdle();
	void markStartActive();

	std::mutex queueMtx_;
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
