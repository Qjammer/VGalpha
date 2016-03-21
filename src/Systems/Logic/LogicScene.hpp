#pragma once

#include "../EntityExtensions/SceneExtension.hpp"

class LogicScene : public SceneExtension{
public:
	LogicScene();
	~LogicScene();
private:
	std::list<std::shared_ptr<LogicObject>> objects_;
};
