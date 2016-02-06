#pragma once
#include <thread>
#include <vector>
#include <cstdio>
#include <atomic>
#include <functional>

#include "../../../Utilities/Logger.hpp"

class ThreadPool {
public:
	ThreadPool()=delete;
	ThreadPool(unsigned int,std::function<void(int)>);
	~ThreadPool();
	bool getThreadStatus(unsigned int) const;
	void initThread(unsigned int,std::function<void(int)>);
	void stopThread(unsigned int);
	void joinThread(unsigned int);
	void joinThreads();

protected:
	unsigned int threadCount_;
	std::vector<bool> active_;
	std::vector<std::shared_ptr<std::thread>> threads_;
};

inline bool ThreadPool::getThreadStatus(unsigned int _id) const{
	return this->active_[_id];
}
