#include "./Engine.hpp"

Engine::Engine(
               std::shared_ptr<TaskManager> _tsk,
               std::shared_ptr<StateManager> _stt,
               std::shared_ptr<ServiceManager> _srv,
               std::shared_ptr<EnvironmentManager> _env,
               std::shared_ptr<PlatformManager> _plt,
               std::vector<std::weak_ptr<SystemInterface>> _sys):

	framework_(std::weak_ptr<TaskManager>(_tsk),_sys),

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

	systems_(_sys)
{

}

void Engine::gameLoop(){
	this->framework_.gameLoop();
}
