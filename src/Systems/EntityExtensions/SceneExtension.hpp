#pragma once

#include "../helixStructures.hpp"

class SceneExtension {
public:
	SceneExtension(EntityType);
	~SceneExtension();

private:
	EntityType type_;
	unsigned int id_;
};
