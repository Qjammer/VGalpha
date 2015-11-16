#include "./TaskManager.hpp"

TaskManager::TaskManager(unsigned int _threads):
	Manager(Manager::MNGR_TYPE::TASK),
	ThreadPool(_threads),
	areAllIdle_(true),
	proceedMain_(true),
	activeThreads_(0),
	isThreadActive_(_threads,false)

{

}

TaskManager::TaskManager():TaskManager(1)
{

}

TaskManager::~TaskManager()
{

}

void TaskManager::initThreadLoop(unsigned int _thread){
	this->makeThreadActive(_thread);
	this->initThread(_thread,std::bind(&TaskManager::threadLoop,this,std::placeholders::_1));
	
}

void TaskManager::threadLoop(unsigned int _thread){
	while(this->getThreadStatus(_thread)){
		this->callTask(_thread);
		this->makeThreadIdle(_thread);
	}
	this->markThreadIdle(_thread);
}

void TaskManager::addTask(std::function<int(void)> _task){
	std::unique_lock<std::mutex> lk(this->queueMtx_);
	this->taskQueue_.push_back(_task);
}
void TaskManager::addTaskList(std::list<std::function<int(void)>> _list){
	std::unique_lock<std::mutex> lk(this->queueMtx_);
	this->taskQueue_.splice(this->taskQueue_.end(),_list);
}



int TaskManager::callTask(unsigned int _thread){
	std::function<int(void)> task;
	printf("calling task\n");
	{
	std::unique_lock<std::mutex> lk(this->queueMtx_);
	printf("queue size:%i\n",this->taskQueue_.size());
	if(this->taskQueue_.empty()){
		printf("Mark Thread Idle\n");
		this->markThreadIdle(_thread);
		task=[](){return 1;};
	} else {
	task=this->taskQueue_.front();
	this->taskQueue_.pop_front();
	}
	}
	return task();
}

void TaskManager::makeThreadIdle(unsigned int _thread){
	{
		std::unique_lock<std::mutex> lk(this->areAllIdleMtx_);
		while(this->areAllIdle_||!(this->isThreadActive_[_thread])){

			printf("inside this big while\n");
			printf(this->isThreadActive_[_thread] ? "true\n":"false\n");
			printf(this->areAllIdle_ ? "true\n":"false\n");
			this->areAllIdleCV_.wait(lk);
			printf("Woken up\n");
		}
	}
}

void TaskManager::markThreadIdle(unsigned int _thread){
	if(this->isThreadActive_[_thread]==true){
	this->isThreadActive_[_thread]=false;
		if(--(this->activeThreads_)==0){
			printf("markAllIdle\n");
			this->markAllIdle();
		}
	} else {
		printf("Thread already Idle\n");
	}
}

void TaskManager::makeThreadActive(unsigned int _thread){
	++(this->activeThreads_);
	this->isThreadActive_[_thread]=true;
	this->areAllIdle_=false;
}

void TaskManager::markAllIdle(){
	if(this->activeThreads_==0){
		this->proceedMain_=true;
		this->proceedMainCV_.notify_all();
	} else {
		printf("Not all threads are idle\n");
	}
}

void TaskManager::markStartActive(){
	if(this->activeThreads_==0){
		this->proceedMain_=false;
		for(unsigned int i=0;i<this->threadCount_;++i){
			this->makeThreadActive(i);
		}

		printf("NotifyCV\n");
		this->areAllIdleCV_.notify_all();
	} else {
		printf("Some threads are still running:%u\n",this->activeThreads_.load());
	}

}

void TaskManager::wakeUpandJoinThread(unsigned int _thread){
	this->stopThread(_thread);
	this->makeThreadActive(_thread);
	this->areAllIdleCV_.notify_all();
	this->joinThread(_thread);
}
