#include "./ManagerInterface.hpp"

ManagerInterface::ManagerInterface(Manager* _mngr)
{

}

ManagerInterface::~ManagerInterface()
{
	
}

std::list<std::function<int(void)>> ManagerInterface::getTaskListFromMngr()
{
	return this->mngr_->getTaskList();
}


