#include "./LogicSystem.hpp"

LogicSystem::LogicSystem(ManagerInterfaceBundle _bndl):
	System(EntityType::LOGIC,_bndl)
{

}

LogicSystem::~LogicSystem(){

}

int LogicSystem::mainTask(){
	printf("MnLgcTsk!");
	this->intBundle_.tskMgrI_->addTaskList(std::list<std::function<int(void)>>(500,[](){printf("SecLgcTsk!");return 0;}));
	return 0;
}
