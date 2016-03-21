#include "Scheduler.hpp"

Scheduler::Scheduler(std::weak_ptr<TaskManagerInterface> _tskmgr, std::vector<std::weak_ptr<SystemInterface>> _sys):
	active_(true),
	timePerTick_(std::chrono::milliseconds(17)),//Roughly 60fps
	unusedTime_(0),
	sleepTick_(std::chrono::system_clock::now()),
	pastTick_(std::chrono::system_clock::now()),
	taskManager_(_tskmgr),
	systems_(_sys)
{

}

Scheduler::~Scheduler(){

}

void Scheduler::Execute(){
	//0.Wait until last tick is finished
	this->updateTimer();
	if(this->unusedTime_.count()>0){
		this->sleepTick_=std::chrono::system_clock::now();
		std::this_thread::sleep_for(this->unusedTime_);
		this->unusedTime_+=this->sleepTick_-std::chrono::system_clock::now();//Difference between unused time and sleeping time
	} else {
		if(std::chrono::milliseconds(10)<-this->unusedTime_){
			LoggerInstance.logWarning("Clock is lagging by more than 10 ms");
		}
	}
	this->pastTick_=std::chrono::system_clock::now();
	//1.Determine systems to execute
	std::list<std::weak_ptr<SystemInterface>> viable(this->viableSystems());

	//2.Send such systems to the tasker by adding their main task to the queue
	std::list<std::function<int(void)>> viableTasks;
	for(auto it=viable.begin();it!=viable.end();++it){
		viableTasks.push_back(std::bind(&SystemInterface::mainTask,it->lock()));
	}
	taskManager_.lock()->addTaskList(viableTasks);

	//3.Wait for completion
	taskManager_.lock()->mainProcess();
}

std::list<std::weak_ptr<SystemInterface>> Scheduler::viableSystems(){//TODO: Make it actually intelligent. Right now it's returning all systems.
	return std::list<std::weak_ptr<SystemInterface>>(systems_.begin(),systems_.end());
}

std::chrono::system_clock::duration Scheduler::timeSinceLastTick() const{
	return std::chrono::system_clock::now()-this->pastTick_;
}

std::chrono::system_clock::duration Scheduler::leftoverTickTime() const{
	return this->timePerTick_-this->timeSinceLastTick();
}

void Scheduler::updateTimer(){
	this->unusedTime_+=this->leftoverTickTime();
	LoggerInstance.logMessage(concatenate(this->unusedTime_.count()));
}

std::string Scheduler::clockUnits() const{
	return concatenate(std::chrono::system_clock::duration::period::num,"/",std::chrono::system_clock::duration::period::den);
}
