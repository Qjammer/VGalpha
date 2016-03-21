#pragma once

#include <list>
#include <memory>

#include "../EntityExtensions/SceneExtension.hpp"
#include "./LogicObject.hpp"

class LogicScene : public SceneExtension{
public:
	LogicScene();
	~LogicScene();
private:
	std::list<std::shared_ptr<LogicObject>> objects_;
};
