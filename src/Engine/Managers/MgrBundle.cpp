#include "./MgrBundle.hpp"

ManagerBundle::ManagerBundle():
	tskMgr_(std::make_shared<TaskManager>()),
	tskMgrI_(std::make_shared<TaskManagerInterface>(this->tskMgr_)),

	sttMgr_(std::make_shared<StateManager>()),
	sttMgrI_(std::make_shared<StateManagerInterface>(this->sttMgr_)),

	srvMgr_(std::make_shared<ServiceManager>()),
	srvMgrI_(std::make_shared<ServiceManagerInterface>(this->srvMgr_)),

	envMgr_(std::make_shared<EnvironmentManager>()),
	envMgrI_(std::make_shared<EnvironmentManagerInterface>(this->envMgr_)),

	pltMgr_(std::make_shared<PlatformManager>()),
	pltMgrI_(std::make_shared<PlatformManagerInterface>(this->pltMgr_))
{

}

ManagerBundle::~ManagerBundle(){

}
