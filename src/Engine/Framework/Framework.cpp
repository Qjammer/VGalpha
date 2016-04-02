#include "./Framework.hpp"

Framework::Framework(ManagerInterfaceBundle _intBundle, std::vector<std::weak_ptr<SystemInterface>> _systems):
	active_(true),
	scheduler_(_intBundle,_systems)
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

void Framework::addSystems(std::vector<std::weak_ptr<SystemInterface>> _sys){
	this->scheduler_.addSystems(_sys);

}
std::atomic<bool>& Framework::getStatus(){
	return this->active_;
}
