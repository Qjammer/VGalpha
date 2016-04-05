#pragma once

#include <list>
#include <memory>
#include <SFML/Window/Keyboard.hpp>

#include "../EntityExtensions/SceneExtension.hpp"
#include "InputObject.hpp"

class InputScene : public SceneExtension{
public:
	InputScene();
	~InputScene()=default;
	bool isKeyPressed(sf::Keyboard::Key);
protected:
	std::list<std::shared_ptr<InputObject>> objects_;
};
