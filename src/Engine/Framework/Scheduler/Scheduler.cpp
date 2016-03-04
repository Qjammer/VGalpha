#include "Scheduler.hpp"

Scheduler::Scheduler(){

}

Scheduler::~Scheduler(){

}

void Scheduler::Execute(){

	//1.Determine systems to execute
	std::list<std::weak_ptr<SystemInterface>> viable(this->viableSystems());

	//2.Send such systems to the tasker by adding their main task to the queue
	std::list<std::function<int(void)>> viableTasks;
	for(auto it=viable.begin();it!=viable.end();++it){
		viableTasks.push_back(std::bind(&SystemInterface::mainTask,it->lock()));
	}
	auto tskmgr(taskManager_.lock()->getInstance());
	tskmgr->addTaskList(viableTasks);
	//3.Wait for completion
	taskManager_.lock()->mainProcess();
}

std::list<std::weak_ptr<SystemInterface>> Scheduler::viableSystems(){
	return std::list<std::weak_ptr<SystemInterface>>();
}
