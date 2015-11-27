#include "./TaskManager.hpp"

TaskManager::TaskManager(unsigned int _threads):
	Manager(Manager::MNGR_TYPE::TASK),
	ThreadPool(_threads),
	areAllIdle_(true),
	proceedMain_(true),
	activeThreads_(0),
	isThreadActive_(_threads,false)
{
	for(unsigned int i=0;i<this->threadCount_;++i){
		this->initThreadLoop(i);
	}
}

TaskManager::TaskManager():TaskManager(1)
{

}

TaskManager::~TaskManager()
{
	this->wakeUpandJoinAll();
}

void TaskManager::mainTask(){
	this->markStartActive();
	{
	std::unique_lock<std::mutex> lk(this->queueMtx_);
	while(!this->proceedMain_){
		this->proceedMainCV_.wait(lk);
	}
	}
}

void TaskManager::initThreadLoop(unsigned int _thread){
	this->makeThreadActive(_thread);
	this->initThread(_thread,std::bind(&TaskManager::threadLoop,this,std::placeholders::_1));
}

void TaskManager::threadLoop(unsigned int _thread){
	printf("Starting loop, thread %i\n",_thread);
	while(this->getThreadStatus(_thread)){
		this->callTask(_thread);
		this->makeThreadIdle(_thread);
	}
	printf("Out of the loop, thread %i\n",_thread);
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
	printf("calling task,thread:%u\n",_thread);
	{
	std::unique_lock<std::mutex> lk(this->queueMtx_);
	printf("queue size:%i\n",this->taskQueue_.size());
	if(this->taskQueue_.empty()){
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
		printf("Sleeping thread %u\n",_thread);
		this->areAllIdleCV_.wait(lk);
		printf("Waking up thread %u\n",_thread);
	}
	}
}

void TaskManager::markThreadIdle(unsigned int _thread){
	if(this->isThreadActive_[_thread]==true){
		this->isThreadActive_[_thread]=false;
		if(--(this->activeThreads_)==0){
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
		this->areAllIdle_=true;
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
		this->areAllIdleCV_.notify_all();
	} else {
		printf("Some threads are still running:%u threads\n",this->activeThreads_.load());
	}
}

void TaskManager::wakeUpandJoinThread(unsigned int _thread){
	this->stopThread(_thread);
	this->makeThreadActive(_thread);
	this->areAllIdleCV_.notify_all();
	this->joinThread(_thread);
}

void TaskManager::wakeUpandJoinAll(){
	unsigned int i;
	for(i=0;i<threadCount_;++i){
		this->stopThread(i);
	}
	for(i=0;i<threadCount_;++i){
		this->makeThreadActive(i);
	}
	this->areAllIdleCV_.notify_all();
	for(i=0;i<threadCount_;++i){
		this->joinThread(i);
	}
}
