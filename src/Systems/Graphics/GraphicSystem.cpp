#include "./GraphicSystem.hpp"

GraphicSystem::GraphicSystem(ManagerInterfaceBundle _bndl):
	System(GRAPHICS, _bndl),
	rwindow_(sf::VideoMode(1280,720),"Title")
{

}

GraphicSystem::~GraphicSystem(){

}

int GraphicSystem::mainTask(){
	printf("MnGfxTsk!");
	std::list<std::function<int(void)>> lst;
	lst.push_back([this](){	this->rwindow_.clear();return 0;});
	lst.push_back([](){printf("SecGfxTsk!");return 0;});
	lst.push_back([this](){	this->rwindow_.display();return 0;});
	this->intBundle_.tskMgrI_->addTaskList(lst);
	return 0;
}
