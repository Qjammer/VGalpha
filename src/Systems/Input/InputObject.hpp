#pragma once

#include <vector>

#include <SFML/Window/Event.hpp>

#include "../EntityExtensions/ObjectExtension.hpp"

class InputObject : public ObjectExtension{
public:
	InputObject(unsigned int);
	virtual ~InputObject()=default;

	virtual int getInput(){return 1;};
};


class EventHandlerObject: public InputObject{
public:
	void processEvents();

	bool getClosedEvent();
	bool closed_;

	bool getLostFocusEvent();
	bool lostFocus_;

	bool getGainedFocusEvent(){return this->gainedFocus_;}
	bool gainedFocus_;

	sf::Event::SizeEvent getResizedEvent(){return this->sizeEvent_;}
	sf::Event::SizeEvent sizeEvent_;

	std::vector<sf::Event::KeyEvent> getKeyEvent(){return this->keyEvents_;}
	std::vector<sf::Event::KeyEvent> keyEvents_;

	sf::Event::TextEvent getTextEvent(){return this->textEvent_;}
	sf::Event::TextEvent textEvent_;

	sf::Event::MouseMoveEvent getMouseMoveEvent(){return this->mouseMoveEvent_;}
	sf::Event::MouseMoveEvent mouseMoveEvent_;

	sf::Event::MouseButtonEvent getMouseButtonEvent(){return this->mouseButtonEvent_;}
	sf::Event::MouseButtonEvent mouseButtonEvent_;

	sf::Event::MouseWheelEvent getMouseWheelEvent(){return this->mouseWheelEvent_;}
	sf::Event::MouseWheelEvent mouseWheelEvent_;

	sf::Event::JoystickMoveEvent getJoystickMoveEvent(){return this->joystickMoveEvent_;}
	sf::Event::JoystickMoveEvent joystickMoveEvent_;

	sf::Event::JoystickButtonEvent getJoystickButtonEvent(){return this->joystickButtonEvent_;}
	sf::Event::JoystickButtonEvent joystickButtonEvent_;

	sf::Event::JoystickConnectEvent getJoystickConnectEvent(){return this->joystickConnectEvent_;}
	sf::Event::JoystickConnectEvent joystickConnectEvent_;

};
