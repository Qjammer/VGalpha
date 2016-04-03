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

	void wakeUpandStopThread(unsigned int);
	void wakeUpandStopAll();
	void joinThreads();
	//Threadpool methods

	bool getThreadStatus(unsigned int);
	void setThreadStatus(unsigned int, bool);

	bool getThreadActivity(unsigned int);
	void setThreadActivity(unsigned int, bool);
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

	unsigned int getCores() const;

	unsigned int countActive();

	unsigned int threadCount_;

	std::vector<std::atomic<bool>> active_;
	std::mutex statusMtx_;

	std::list<std::function<int(void)>> taskQueue_;
	std::mutex queueMtx_;

	std::condition_variable threadCV_;//Condition variable for working threads
	std::condition_variable mainCV_;//Condition variable for main thread call for execution
	std::mutex mainMtx_;

	std::atomic<bool> proceedMain_;

	std::vector<std::atomic<bool>> isThreadRunning_;
	std::recursive_mutex activityMtx_;

	std::vector<std::shared_ptr<std::thread>> threads_;
};

inline bool TaskManager::getThreadStatus(unsigned int _thread){
	std::unique_lock<std::mutex> lk(this->statusMtx_);
	return this->active_[_thread];
}

inline void TaskManager::setThreadStatus(unsigned int _thread, bool _st){
	std::unique_lock<std::mutex> lk(this->statusMtx_);
	this->active_[_thread]=_st;
}

inline bool TaskManager::getThreadActivity(unsigned int _thread){
	std::unique_lock<std::recursive_mutex> lk(this->activityMtx_);
	return this->isThreadRunning_[_thread];
}

inline void TaskManager::setThreadActivity(unsigned int _thread, bool _st){
	std::unique_lock<std::recursive_mutex> lk(this->activityMtx_);
	this->isThreadRunning_[_thread]=_st;
}


