#include "ThreadPool.hpp"

ThreadPool::ThreadPool(){
	this->active_.resize(1);
	this->active_[0]=true;
}

ThreadPool::~ThreadPool(){
	
}
