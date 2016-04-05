#include "./InputSystem.hpp"

InputSystem::InputSystem(ManagerInterfaceBundle _bndl):
	System(EntityType::INPUT,_bndl)
{

}


int InputSystem::mainTask(){
	printf("MnLgcTsk!");
	this->intBundle_.tskMgrI_->addTaskList(std::list<std::function<int(void)>>(500,[](){printf("SecLgcTsk!");return 0;}));
	return 0;
}
