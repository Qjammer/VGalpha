#pragma once

#include "../helixStructures.hpp"

class SceneExtension {
public:
	SceneExtension();
	~SceneExtension();

private:
	EntityType type_;
	unsigned int id_;
};
