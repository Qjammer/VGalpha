#include "SystemInterface.hpp"

SystemInterface::SystemInterface(std::weak_ptr<System> _system):system_(_system)
{

}


SystemInterface::~SystemInterface()
{

}

int SystemInterface::mainTask(){
	return this->system_.lock()->mainTask();
}

EntityType SystemInterface::getType() const{
	return this->system_.lock()->getType();
}
