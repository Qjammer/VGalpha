#pragma once
#include <functional>
#include <list>
#include <memory>

#include "helixStructures.hpp"
class TaskManagerInterface;

class System
{
public:
	friend class SystemInterface;
	System();
	System(EntityType _type);
	~System();
	virtual int mainTask(std::weak_ptr<TaskManagerInterface>)=0;
	const EntityType& getType() const;
protected:
	EntityType type_;
	std::list<std::function<void(void)>> taskList_;
};
