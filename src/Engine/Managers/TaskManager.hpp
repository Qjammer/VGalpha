#pragma once
#include <mutex>
#include <atomic>
#include <thread>
#include <condition_variable>
#include <iostream>

#include "./Manager.hpp"
#include "../../Utilities/Logger.hpp"

class System;

class TaskManager: public Manager{
public:
	TaskManager(unsigned int _threads);
	TaskManager();
	~TaskManager();

	void mainProcess();

	void addTask(std::function<int(void)>);
	void addTaskList(std::list<std::function<int(void)>>);

	void initThreadLoop(unsigned int);
	void wakeUpandStopThread(unsigned int);
	void wakeUpandStopAll();
	void joinThreads();
	//Threadpool methods

	bool getThreadStatus(unsigned int) const;

protected:

	void stopThread(unsigned int);
	void joinThread(unsigned int);

	void threadLoop(unsigned int);

	int callTask(unsigned int);

	void markThreadRunning(unsigned int);
	void markAllRunning();

	void idleThread(unsigned int);
	void markThreadIdle(unsigned int);

	void signalAllIdle();
	void joinAll();

	unsigned int getCores() const;

	//Threadpool members
	std::vector<std::atomic<bool>> active_;
	unsigned int threadCount_;

	std::mutex queueMtx_;
	std::list<std::function<int(void)>> taskQueue_;

	std::condition_variable areAllIdleCV_;//Condition variable for working threads
	std::mutex areAllIdleMtx_;
	std::atomic<bool> areAllIdle_;

	std::condition_variable proceedMainCV_;//Condition variable for main thread call for execution
	std::mutex proceedMainMtx_;
	std::atomic<bool> proceedMain_;

	std::atomic<unsigned int> runningThreads_;
	std::vector<std::atomic<bool>> isThreadRunning_;

	std::vector<std::shared_ptr<std::thread>> threads_;
};

inline bool TaskManager::getThreadStatus(unsigned int _id) const{
	return this->active_[_id];
}



