#include "./Engine.hpp"

Engine::Engine(
               std::shared_ptr<TaskManager> _tsk,
               std::shared_ptr<StateManager> _stt,
               std::shared_ptr<ServiceManager> _srv,
               std::shared_ptr<EnvironmentManager> _env,
               std::shared_ptr<PlatformManager> _plt):

	framework_(std::weak_ptr<TaskManager>(_tsk),std::vector<std::weak_ptr<SystemInterface>>()),

	taskManager_(_tsk),
	taskManagerInterface_(_tsk),

	stateManager_(_stt),
	stateManagerInterface_(_stt),

	serviceManager_(_srv),
	serviceManagerInterface_(_srv),

	environmentManager_(_env),
	environmentManagerInterface_(_env),

	platformManager_(_plt),
	platformManagerInterface_(_plt),

	systems_(std::vector<std::weak_ptr<SystemInterface>>())
{

}

Engine::Engine(ManagerBundle& _mgrBundle):
	Engine(
		_mgrBundle.tskMgr_,
		_mgrBundle.sttMgr_,
		_mgrBundle.srvMgr_,
		_mgrBundle.envMgr_,
		_mgrBundle.pltMgr_)
	{

}

Engine::~Engine(){

}

void Engine::addSystemVector(std::vector<std::weak_ptr<SystemInterface>> _sys){
	this->systems_.insert(this->systems_.end(),_sys.begin(),_sys.end());
}

void Engine::gameLoop(){
	this->framework_.gameLoop();
}
