#pragma once

#include "../EntityExtensions/ObjectExtension.hpp"

class LogicObject : public ObjectExtension{
	LogicObject(unsigned int);
	virtual ~LogicObject()=default;

	virtual int doStuff(){return 1;};
};
