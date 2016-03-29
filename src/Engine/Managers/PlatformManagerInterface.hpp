#pragma once

#include "./PlatformManager.hpp"
#include "./ManagerInterface.hpp"

class PlatformManagerInterface: public ManagerInterface<PlatformManager>{
public:
	PlatformManagerInterface(std::shared_ptr<PlatformManager>);
	~PlatformManagerInterface();
};
