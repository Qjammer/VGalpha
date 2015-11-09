#pragma once
#include <functional>
#include <list>

#include "helixStructures.hpp"


class System
{
public:
	friend class SystemInterface;
	System();
	System(EntityType _type);
	~System();
	virtual std::list<std::function<void(void)>>& mainTask()=0;//Returns sub-tasks
	const EntityType& getType() const;
protected:
	EntityType type_;
	std::list<std::function<void(void)>> taskList_;
};
