#include "./IntBundle.hpp"

ManagerInterfaceBundle::ManagerInterfaceBundle(ManagerBundle _mgrB):
	tskMgrI_(_mgrB.tskMgrI_),
	sttMgrI_(_mgrB.sttMgrI_),
	srvMgrI_(_mgrB.srvMgrI_),
	envMgrI_(_mgrB.envMgrI_),
	pltMgrI_(_mgrB.pltMgrI_)
{

}

ManagerInterfaceBundle::~ManagerInterfaceBundle(){

}
