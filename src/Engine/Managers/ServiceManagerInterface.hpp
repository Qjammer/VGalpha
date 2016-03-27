#pragma once

#include <memory>

#include "./ServiceManager.hpp"
#include "./ManagerInterface.hpp"

class ServiceManagerInterface: public ManagerInterface<ServiceManager>{
public:
	ServiceManagerInterface(std::shared_ptr<ServiceManager>);
	~ServiceManagerInterface();
};
