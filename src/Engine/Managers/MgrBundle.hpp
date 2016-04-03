#pragma once
#include <memory>

#include "./TaskManagerInterface.hpp"
#include "./StateManagerInterface.hpp"
#include "./ServiceManagerInterface.hpp"
#include "./EnvironmentManagerInterface.hpp"
#include "./PlatformManagerInterface.hpp"

struct ManagerBundle{
public:
	ManagerBundle();
	~ManagerBundle();
	std::shared_ptr<TaskManager> tskMgr_;
	std::shared_ptr<TaskManagerInterface> tskMgrI_;

	std::shared_ptr<StateManager> sttMgr_;
	std::shared_ptr<StateManagerInterface> sttMgrI_;

	std::shared_ptr<ServiceManager> srvMgr_;
	std::shared_ptr<ServiceManagerInterface> srvMgrI_;

	std::shared_ptr<EnvironmentManager> envMgr_;
	std::shared_ptr<EnvironmentManagerInterface> envMgrI_;

	std::shared_ptr<PlatformManager> pltMgr_;
	std::shared_ptr<PlatformManagerInterface> pltMgrI_;

};
