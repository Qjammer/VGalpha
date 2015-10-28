#pragma once
#include <thread>
#include <vector>

class ThreadPool {
public:
	ThreadPool();
	~ThreadPool();
	bool getThreadStatus(const unsigned int) const;

protected:
	std::vector<std::thread> threads_;
	std::vector<bool> active_;

};

inline bool ThreadPool::getThreadStatus(const unsigned int id) const{
	return this->active_[id];
}