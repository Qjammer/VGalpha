#pragma once

#include "../helixStructures.hpp"

class ObjectExtension {
public:
	ObjectExtension(EntityType _type, unsigned int _id);
	~ObjectExtension();

private:
	EntityType type_;
	unsigned int id_;
};
