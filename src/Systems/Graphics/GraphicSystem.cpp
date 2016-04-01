#include "./GraphicSystem.hpp"

GraphicSystem::GraphicSystem():
	System(GRAPHICS),
	rwindow_(sf::VideoMode(1280,720),"Title")
{

}

GraphicSystem::~GraphicSystem(){

}

int GraphicSystem::mainTask(std::weak_ptr<TaskManagerInterface> _tskmgr){
	printf("MnGfxTsk!");
	std::list<std::function<int(void)>> lst;
	lst.push_back([this](){	this->rwindow_.clear();return 0;});
	lst.push_back([](){printf("SecGfxTsk!");return 0;});
	lst.push_back([this](){	this->rwindow_.display();return 0;});
	_tskmgr.lock()->addTaskList(lst);
	return 0;
}
