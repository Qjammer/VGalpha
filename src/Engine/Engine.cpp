#include "./Engine.hpp"

Engine::Engine(ManagerInterfaceBundle& _mgrBundle):
	mgrBundle_(_mgrBundle),
	framework_(_mgrBundle,std::vector<std::weak_ptr<SystemInterface>>()),
	systems_(std::vector<std::weak_ptr<SystemInterface>>())
{

}

Engine::~Engine(){

}

void Engine::addSystemVector(std::vector<std::weak_ptr<SystemInterface>> _sys){
	this->systems_.insert(this->systems_.end(),_sys.begin(),_sys.end());
	this->framework_.addSystems(_sys);
}

void Engine::gameLoop(){
	this->framework_.gameLoop();
}
