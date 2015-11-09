#pragma once

#include <vector>
#include <mutex>

class Manager
{
public:
	Manager(unsigned int _entrancePoints);
	~Manager();
	virtual void generalProcedure()=0;

protected:
	
};
