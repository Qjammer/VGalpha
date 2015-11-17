#pragma once

#include <vector>
#include <mutex>
#include <list>

class Manager
{
public:
	enum MNGR_TYPE {
		TASK,
		STATE,
		SERVICE,
		ENVIRONMENT,
		PLATFORM
	};
	//Methods ONLY
	Manager(MNGR_TYPE);
	~Manager();
	const MNGR_TYPE getType();
	

protected:
	MNGR_TYPE mngr_type_;
};
