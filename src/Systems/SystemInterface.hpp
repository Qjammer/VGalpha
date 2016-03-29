#pragma once
#include <memory>
#include "System.hpp"
#include "helixStructures.hpp"


class SystemInterface
{
public:
	SystemInterface();
	SystemInterface(std::weak_ptr<System>, std::weak_ptr<TaskManagerInterface>);
	~SystemInterface();
	int mainTask();

	EntityType getType() const;
protected:
	std::weak_ptr<System> system_;
	std::weak_ptr<TaskManagerInterface> taskManager_;
};
