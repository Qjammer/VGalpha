#include "./LogicSystem.hpp"

LogicSystem::LogicSystem(ManagerInterfaceBundle _bndl):
	System(EntityType::LOGIC,_bndl)
{

}

LogicSystem::~LogicSystem(){

}

int LogicSystem::mainTask(std::weak_ptr<TaskManagerInterface>){
	return 0;
}
