#pragma once

#include "./MgrBundle.hpp"

struct ManagerInterfaceBundle{
public:
	ManagerInterfaceBundle(ManagerBundle);
	~ManagerInterfaceBundle();

	std::shared_ptr<TaskManagerInterface> tskMgrI_;
	std::shared_ptr<StateManagerInterface> sttMgrI_;
	std::shared_ptr<ServiceManagerInterface> srvMgrI_;
	std::shared_ptr<EnvironmentManagerInterface> envMgrI_;
	std::shared_ptr<PlatformManagerInterface> pltMgrI_;
};
