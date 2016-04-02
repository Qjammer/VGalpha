#pragma once
#include <functional>
#include <list>
#include <memory>

#include "helixStructures.hpp"
#include "../Engine/Managers/IntBundle.hpp"

class System
{
public:
	friend class SystemInterface;
	System(EntityType,ManagerInterfaceBundle);
	~System();
	virtual int mainTask()=0;
	EntityType getType() const;
protected:
	EntityType type_;
	ManagerInterfaceBundle intBundle_;
	std::list<std::function<void(void)>> taskList_;
};
