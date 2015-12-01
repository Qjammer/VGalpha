#include "./ManagerInterface.hpp"

ManagerInterface::ManagerInterface(std::shared_ptr<Manager> _mngr) :
	mngr_(_mngr)
{

}

ManagerInterface::~ManagerInterface()
{
	
}
