#pragma once
#include <thread>
#include <vector>

class ThreadPool {
public:
	ThreadPool();
	~ThreadPool();

private:
	std::vector<std::thread> threads_;

};
