#pragma once

class ManagerInterface{
public:
	ManagerInterface();
	~ManagerInterface();

	virtual std::list<std::function<void(void)>>& mainTask();

};