#include "ThreadPool.hpp"

ThreadPool::ThreadPool():ThreadPool(1)
{

}

ThreadPool::ThreadPool(int _threads):threadCount_(_threads),active_(_threads,false),threads_(_threads)
{

}

void ThreadPool::initThread(const unsigned int _thread,std::function<void(int)> _func){
	if(this->active_[_thread]==true){
		this->stopThread(_thread);
	}
	this->active_[_thread]=true;
	printf("starting thread %i\n",_thread);
	if(_thread==0){
		_func(_thread);
	} else {
		this->threads_[_thread]=(std::shared_ptr<std::thread>(new std::thread(_func,_thread)));
	}
}

void ThreadPool::stopThread(const unsigned int _thread){
	printf("stopping thread %i\n",_thread);
	this->active_[_thread]=false;
}

void ThreadPool::joinThread(const unsigned int _thread){
	if(_thread==0){
		printf("You tried joining the main thread, moron\n");
	} else {
		printf("Joining thread %i\n",_thread);
		this->threads_[_thread]->join();
	}
}

ThreadPool::~ThreadPool()
{
	
}
