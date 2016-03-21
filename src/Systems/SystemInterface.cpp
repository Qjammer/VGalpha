#include "SystemInterface.hpp"

SystemInterface::SystemInterface(System* _system, std::weak_ptr<TaskManagerInterface> _tskmngrintf):system_(_system),taskManager_(_tskmngrintf)
{

}


SystemInterface::~SystemInterface()
{

}

int SystemInterface::mainTask(){
	return this->system_->mainTask(this->taskManager_);
}

EntityType SystemInterface::getType() const{
	return this->system_->getType();
}
