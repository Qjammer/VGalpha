#include "./LogicSystem.hpp"

LogicSystem::LogicSystem():
	System(EntityType::LOGIC)
{

}

LogicSystem::~LogicSystem(){

}

int LogicSystem::mainTask(std::weak_ptr<TaskManagerInterface>){
	return 0;
}
