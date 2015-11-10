#pragma once
#include <memory>
#include "System.hpp"
#include "helixStructures.hpp"


class SystemInterface
{
public:
	SystemInterface();
	SystemInterface(EntityType _type);
	~SystemInterface();
	virtual std::list<std::function<void(void)>>& mainTask();

	const EntityType& getType() const;
protected:
	std::shared_ptr<System> system_;
};
