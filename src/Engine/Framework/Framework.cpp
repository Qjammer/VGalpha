#include "./Framework.hpp"

Framework::Framework(std::weak_ptr<TaskManager> _tskmgr, std::vector<std::weak_ptr<SystemInterface>> _systems):
	active_(true),
	scheduler_(_tskmgr,_systems)

{

}

Framework::~Framework(){

}

void Framework::gameLoop(){
	while(this->getStatus()){

		//1.Process Window Messages

		//2.Scheduler Execution
		this->scheduler_.Execute();

		//3.Distribute Changes

		//4. Check Execution Status (Change scene, quit, etc)

	}
}

std::atomic<bool>& Framework::getStatus(){
	return this->active_;
}
