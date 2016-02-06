#include "ThreadPool.hpp"


ThreadPool::ThreadPool(unsigned int _threads, std::function<void(int)> f):
	threadCount_(_threads),
	active_(_threads,true),
	threads_(_threads,std::shared_ptr<std::thread>())
{
	for(unsigned int i=0;i<_threads;++i){
		this->threads_[i]=std::make_shared<std::thread>(f,i);
	}
	LoggerInstance.logMessage("End of ThreadPool Constructor");
}

ThreadPool::~ThreadPool()
{

}

void ThreadPool::joinThreads(){
	LoggerInstance.logMessage("Joining or detaching threads");
	for(unsigned int i=0;i<threadCount_;++i){
		if(this->threads_[i]->joinable()){
			this->threads_[i]->join();
		} else {
			this->threads_[i]->detach();
		}
	}
}

void ThreadPool::initThread(unsigned int _thread,std::function<void(int)> _func){
	if(this->active_[_thread]==true){
		LoggerInstance.logMessage("Initializing already active thread");
		this->stopThread(_thread);
		this->joinThread(_thread);
	}
	this->active_[_thread]=true;
	printf("starting thread %i\n",_thread);
	this->threads_[_thread]=(std::shared_ptr<std::thread>(new std::thread(_func,_thread)));
}

void ThreadPool::stopThread(unsigned int _thread){
	LoggerInstance.logMessage(concatenate("Stopping thread",_thread));
	this->active_[_thread]=false;
}

void ThreadPool::joinThread(unsigned int _thread){
	LoggerInstance.logMessage(concatenate("Joining Thread ",_thread));
	this->threads_[_thread]->join();
}

