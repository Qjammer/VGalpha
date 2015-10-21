#pragma once

#include "../helixStructures.hpp"

class ObjectExtension {
public:
	ObjectExtension();
	~ObjectExtension();

private:
	EntityType type_;
	unsigned int id_;
};
