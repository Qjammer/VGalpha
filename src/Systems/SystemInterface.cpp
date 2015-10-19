#include "SystemInterface.hpp"

SystemInterface::SystemInterface()
{

}

SystemInterface::~SystemInterface()
{

}

std::list<std::function<void(void)>>& SystemInterface::mainTask(){
	return this->system_->mainTask();
}