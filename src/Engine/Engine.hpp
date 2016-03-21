#pragma once

#include "./Framework/Framework.hpp"
#include "./Managers/TaskManagerInterface.hpp"
#include "./Managers/StateManager.hpp"
class ServiceManager;
#include "./Managers/EnvironmentManagerInterface.hpp"
class PlatformManager;

class Engine {
public:
	Engine(
		std::shared_ptr<TaskManager>,
		std::shared_ptr<StateManager>,
		std::shared_ptr<ServiceManager>,
		std::shared_ptr<EnvironmentManager>,
		std::shared_ptr<PlatformManager>,
		std::vector<std::weak_ptr<SystemInterface>>);
	~Engine();
	void gameLoop();
protected:
	Framework framework_;

	std::weak_ptr<TaskManager> taskManager_;
	TaskManagerInterface taskManagerInterface_;

	std::weak_ptr<StateManager> stateManager_;

	std::weak_ptr<ServiceManager> serviceManager_;

	std::weak_ptr<EnvironmentManager> environmentManager_;
	EnvironmentManagerInterface environmentManagerInterface_;

	std::weak_ptr<PlatformManager> platformManager_;

	std::vector<std::weak_ptr<SystemInterface>> systems_;
};
