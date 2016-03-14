#include "Scheduler.hpp"

Scheduler::Scheduler(std::weak_ptr<TaskManagerInterface> _tskmgr, std::vector<std::weak_ptr<SystemInterface>> _sys):
	taskManager_(_tskmgr),
	systems_(_sys)
{

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
	taskManager_.lock()->addTaskList(viableTasks);

	//3.Wait for completion
	taskManager_.lock()->mainProcess();
}

std::list<std::weak_ptr<SystemInterface>> Scheduler::viableSystems(){//TODO: Make it actually intelligent. Right now it's returning all systems.
	return std::list<std::weak_ptr<SystemInterface>>(systems_.begin(),systems_.end());
}
