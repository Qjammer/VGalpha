#include "SystemInterface.hpp"

SystemInterface::SystemInterface(std::weak_ptr<System> _system, std::weak_ptr<TaskManagerInterface> _tskmngrI):system_(_system),taskManager_(_tskmngrI)
{

}


SystemInterface::~SystemInterface()
{

}

int SystemInterface::mainTask(){
	return this->system_.lock()->mainTask(this->taskManager_);
}

EntityType SystemInterface::getType() const{
	return this->system_.lock()->getType();
}
