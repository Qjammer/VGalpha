#pragma once
#include <thread>
#include <vector>
#include <cstdio>
#include <atomic>

class ThreadPool {
public:

	ThreadPool(unsigned int);
	ThreadPool();
	~ThreadPool();
	bool getThreadStatus(unsigned int) const;
	void initThread(unsigned int,std::function<void(int)>);
	void stopThread(unsigned int);
	void joinThread(unsigned int);

protected:
	unsigned int threadCount_;
	std::vector<bool> active_;
	std::vector<std::shared_ptr<std::thread>> threads_;
	

};

inline bool ThreadPool::getThreadStatus(unsigned int _id) const{
	return this->active_[_id];
}
