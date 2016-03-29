#pragma once
#include <functional>
#include <list>
#include <memory>

#include "helixStructures.hpp"
#include "../Engine/Managers/TaskManagerInterface.hpp"

class System
{
public:
	friend class SystemInterface;
	System();
	System(EntityType _type);
	~System();
	virtual int mainTask(std::weak_ptr<TaskManagerInterface>)=0;
	EntityType getType() const;
protected:
	EntityType type_;
	std::list<std::function<void(void)>> taskList_;
};
