#pragma once
#include <memory>
#include "System.hpp"
#include "helixStructures.hpp"


class SystemInterface
{
public:
	SystemInterface();
	SystemInterface(System*, std::weak_ptr<TaskManagerInterface>);
	~SystemInterface();
	int mainTask();

	const EntityType& getType() const;
protected:
	std::shared_ptr<System> system_;
	std::weak_ptr<TaskManagerInterface> taskManager_;
};
