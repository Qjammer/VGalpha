#pragma once
#include <memory>
#include "System.hpp"


class SystemInterface
{
public:
	SystemInterface();
	~SystemInterface();
	virtual std::list<std::function<void(void)>>& mainTask();
private:
	std::shared_ptr<System> system_;
};
