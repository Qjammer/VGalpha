#pragma once

#include "./Framework/Framework.hpp"
#include "./Managers/MgrBundle.hpp"

class Engine {
public:
	Engine(
		std::shared_ptr<TaskManager>,
		std::shared_ptr<StateManager>,
		std::shared_ptr<ServiceManager>,
		std::shared_ptr<EnvironmentManager>,
		std::shared_ptr<PlatformManager>);
	Engine(ManagerBundle&);
	~Engine();
	void addSystemVector(std::vector<std::weak_ptr<SystemInterface>>);
	void gameLoop();
protected:
	Framework framework_;

	std::weak_ptr<TaskManager> taskManager_;
	TaskManagerInterface taskManagerInterface_;

	std::weak_ptr<StateManager> stateManager_;
	StateManagerInterface stateManagerInterface_;

	std::weak_ptr<ServiceManager> serviceManager_;
	ServiceManagerInterface serviceManagerInterface_;

	std::weak_ptr<EnvironmentManager> environmentManager_;
	EnvironmentManagerInterface environmentManagerInterface_;

	std::weak_ptr<PlatformManager> platformManager_;
	PlatformManagerInterface platformManagerInterface_;

	std::vector<std::weak_ptr<SystemInterface>> systems_;
};
