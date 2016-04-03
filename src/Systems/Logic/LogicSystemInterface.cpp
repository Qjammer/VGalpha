#include "./LogicSystemInterface.hpp"

LogicSystemInterface::LogicSystemInterface(std::weak_ptr<LogicSystem> _sys):
	SystemInterface(_sys)
{

}
LogicSystemInterface::~LogicSystemInterface(){

}
