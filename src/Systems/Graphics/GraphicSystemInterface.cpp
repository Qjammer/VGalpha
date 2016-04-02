#include "./GraphicSystemInterface.hpp"

GraphicSystemInterface::GraphicSystemInterface(std::weak_ptr<GraphicSystem> _sys):
	SystemInterface(_sys)
{

}
GraphicSystemInterface::~GraphicSystemInterface(){

}
