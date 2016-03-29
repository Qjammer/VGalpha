#include "./GraphicSystemInterface.hpp"

GraphicSystemInterface::GraphicSystemInterface(std::weak_ptr<GraphicSystem> _sys, std::weak_ptr<TaskManagerInterface> _tsk):
	SystemInterface(_sys,_tsk)
{

}
GraphicSystemInterface::~GraphicSystemInterface(){

}
