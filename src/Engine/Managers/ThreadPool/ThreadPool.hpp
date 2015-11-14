#pragma once
#include <thread>
#include <vector>
#include <cstdio>
#include <atomic>

class ThreadPool {
public:
	ThreadPool(int);
	ThreadPool();
	~ThreadPool();
	bool getThreadStatus(const unsigned int) const;
	void initThread(const unsigned int,std::function<void(int)>);
	void stopThread(const unsigned int);
	void joinThread(const unsigned int);

protected:
	unsigned int threadCount_;
	std::vector<bool> active_;
	std::vector<std::shared_ptr<std::thread>> threads_;
	

};

inline bool ThreadPool::getThreadStatus(const unsigned int id) const{
	return this->active_[id];
}