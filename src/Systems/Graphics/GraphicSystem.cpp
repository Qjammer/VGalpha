#include "./GraphicSystem.hpp"

GraphicSystem::GraphicSystem(ManagerInterfaceBundle _bndl):
	System(GRAPHICS, _bndl)
{

}

GraphicSystem::~GraphicSystem(){

}

int GraphicSystem::mainTask(){
	printf("MnGfxTsk!");
	std::list<std::function<int(void)>> lst;
	lst.push_back([this](){	this->scene_.rwindow_.clear();return 0;});
	lst.push_back([](){printf("SecGfxTsk!");return 0;});
	lst.push_back([this](){	this->scene_.rwindow_.display();return 0;});
	this->intBundle_.tskMgrI_->addTaskList(lst);
	return 0;
}
