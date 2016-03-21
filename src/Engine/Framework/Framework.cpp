#include "./Framework.hpp"

Framework::Framework(std::weak_ptr<TaskManagerInterface> _tskmgr, std::vector<std::weak_ptr<SystemInterface>> _systems):
	scheduler_(_tskmgr,_systems)
{

}

Framework::~Framework(){

}

void Framework::gameLoop(){
	while(this->getStatus()){
		//1.Process Window Messages

		//2.Call Scheduler
		this->scheduler_.Execute();

		//3.Distribute Changes

	}
}

std::atomic<bool>& Framework::getStatus(){
	return this->active_;
}
