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
	virtual void loadScene(std::stringstream)=0;
	virtual void saveScene(std::string)=0;
	virtual void objectFactory(std::stringstream)=0;
	EntityType getType() const;
protected:
	EntityType type_;
	ManagerInterfaceBundle intBundle_;
	std::list<std::function<void(void)>> taskList_;
};
