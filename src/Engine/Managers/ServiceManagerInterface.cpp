#include "ServiceManagerInterface.hpp"

ServiceManagerInterface::ServiceManagerInterface(std::shared_ptr<ServiceManager> _srv):
	ManagerInterface(_srv)
{

}


ServiceManagerInterface::~ServiceManagerInterface(){}
