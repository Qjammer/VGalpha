#include "./TaskManager.hpp"

TaskManager::TaskManager(unsigned int _threads):
	Manager(Manager::MNGR_TYPE::TASK),

	threadCount_(_threads),

	active_(_threads),
	statusMtx_(),

	taskQueue_(0),
	queueMtx_(),

	threadCV_(),
	mainCV_(),
	mainMtx_(),

	proceedMain_(true),

	isThreadRunning_(_threads),
	activityMtx_(),

	threads_(_threads,std::shared_ptr<std::thread>())
{
	for(unsigned int i=0;i<_threads;++i){
		this->setThreadStatus(i,true);//INIT active_
		this->setThreadActivity(i,false);
		this->threads_[i]=std::make_shared<std::thread>(std::bind(&TaskManager::threadLoop,this,i));
	}
}

TaskManager::TaskManager():TaskManager(TaskManager::getCores())
{

}

TaskManager::~TaskManager()
{

}

void TaskManager::mainProcess(){
	if(this->countActive()!=0){
		LoggerInstance.logWarning(concatenate("Some threads are still running: ",this->countActive()));
	}
	this->proceedMain_=false;
	this->markAllRunning();
	this->threadCV_.notify_all();

	LoggerInstance.logMessage("Main Thread Stopping");
	{
	std::unique_lock<std::mutex> lk(this->mainMtx_);
	while(!this->proceedMain_){
		this->mainCV_.wait(lk);
	}
	}
	LoggerInstance.logMessage("Main Thread Proceeding");
}

void TaskManager::threadLoop(unsigned int _thread){
	LoggerInstance.logMessage(concatenate("Starting loop, thread ",_thread));
	do {
		this->callTask(_thread);
		this->idleThread(_thread);
	} while(this->getThreadStatus(_thread));
	LoggerInstance.logMessage(concatenate("Exiting loop, thread ",_thread));
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
	{
	std::unique_lock<std::mutex> lk(this->queueMtx_);
	if(this->taskQueue_.empty()){
		this->markThreadIdle(_thread);
		task=[](){return 1;};
	} else {
		if(this->countActive()!=this->threadCount_){
			this->markAllRunning();
			this->threadCV_.notify_all();
		}
		task=this->taskQueue_.front();
		this->taskQueue_.pop_front();
		}
	}
	return task();
}

void TaskManager::idleThread(unsigned int _thread){
	{
	std::unique_lock<std::mutex> lk(this->mainMtx_);
	while(this->getThreadActivity(_thread)==false){
		if(this->countActive()==0){
			this->signalAllIdle();
		}
		LoggerInstance.logMessage(concatenate("Sleeping thread: ",_thread));
		this->threadCV_.wait(lk);
		LoggerInstance.logMessage(concatenate("Waking up thread: ",_thread));
	}
	}
}

void TaskManager::markThreadIdle(unsigned int _thread){
	if(this->getThreadActivity(_thread)==true){
		this->setThreadActivity(_thread,false);
	} else {
		LoggerInstance.logWarning(concatenate("Thread ",_thread," already idle"));
	}
}

void TaskManager::signalAllIdle(){
	if(this->countActive()==0){
		this->proceedMain_=true;
		this->mainCV_.notify_all();
	} else {
		LoggerInstance.logWarning(concatenate("Not all threads are idle"));
	}
}

void TaskManager::markThreadRunning(unsigned int _thread){
	if(this->getThreadActivity(_thread)==false){
		this->setThreadActivity(_thread,true);
	} else {
		LoggerInstance.logWarning(concatenate("Thread ",_thread," already running"));
	}
}

void TaskManager::markAllRunning(){
	for(unsigned int i=0;i<this->threadCount_;++i){
		this->markThreadRunning(i);
	}
}

void TaskManager::wakeUpandStopThread(unsigned int _thread){
	this->stopThread(_thread);
	this->markThreadRunning(_thread);
	this->threadCV_.notify_all();
}

void TaskManager::wakeUpandStopAll(){
	if(this->countActive()!=0){
		LoggerInstance.logWarning(concatenate("Trying to wake up non idle threads: ",this->countActive()));
	}

	unsigned int i;
	for(i=0;i<threadCount_;++i){
		this->stopThread(i);
	}
	for(i=0;i<threadCount_;++i){
		this->markThreadRunning(i);
	}
	this->threadCV_.notify_all();
}

unsigned int TaskManager::countActive(){
	unsigned int c=0;
	{
	std::unique_lock<std::recursive_mutex> lk(this->activityMtx_);
	for (unsigned int i=0; i<this->threadCount_; ++i){
		if (this->getThreadActivity(i)){
			++c;
		}
	}
	}
	return c;
}

unsigned int TaskManager::getCores(){
	unsigned int cores=std::thread::hardware_concurrency();
	LoggerInstance.logMessage(concatenate("Detected ",cores," cores."));
	if (cores<1){
		LoggerInstance.logMessage("Defaulting to 1 core");
		return 1;
	}
	return cores;
}

void TaskManager::stopThread(unsigned int _thread){
	LoggerInstance.logMessage(concatenate("Stopping thread ",_thread));
	this->setThreadStatus(_thread,false);
}

void TaskManager::joinThread(unsigned int _thread){
	LoggerInstance.logMessage(concatenate("Joining Thread ",_thread));
	if(this->threads_[_thread]->joinable()){
		this->threads_[_thread]->join();
	} else {
		this->threads_[_thread]->detach();
	}
}

void TaskManager::joinThreads(){
	LoggerInstance.logMessage("Joining or detaching threads");
	for(unsigned int i=0;i<threadCount_;++i){
		this->joinThread(i);
	}
}
