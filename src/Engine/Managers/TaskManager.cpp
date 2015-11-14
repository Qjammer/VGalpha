#include "./TaskManager.hpp"

TaskManager::TaskManager(int _threads):
	Manager(Manager::MNGR_TYPE::TASK),
	ThreadPool(_threads),
	areAllIdle_(false),
	proceedMain_(true),
	activeThreads_(_threads),
	isThreadActive_(_threads,false)

{

}

TaskManager::~TaskManager()
{

}

void TaskManager::makeThreadIdle(int _thread){
	this->isThreadActive_[_thread]==false;
	if(--(this->activeThreads_)==0){
		this->markAllIdle();
	};
	{
		std::unique_lock<std::mutex> lk(this->areAllIdleMtx_);
		while(this->areAllIdle_||!this->isThreadActive_[_thread]){
			this->areAllIdleCV_.wait(lk);
		}
	}
}

void TaskManager::makeThreadActive(int _thread){
	++(this->activeThreads_);
	this->isThreadActive_[_thread]==true;
}

void TaskManager::markAllIdle(){
	//TODO:Everything
	if(this->activeThreads_==0){
		this->proceedMain_=true;
		proceedMainCV_.notify_all();
	} else {
		printf("Not all threads are idle\n");
	}
}

void TaskManager::markStartActive(){
	if(this->activeThreads_==0){
		this->proceedMain_=false;
		for(unsigned int i=0;i<this->threadCount_;i++){
			this->makeThreadActive(i);
		}
		this->areAllIdleCV_.notify_all();
	} else {
		printf("Some threads are still running\n");
	}

}

void TaskManager::addTask(std::function<int(void)> _task){
	std::unique_lock<std::mutex> (this->queueMutex_);
	//TODO:Everything

}