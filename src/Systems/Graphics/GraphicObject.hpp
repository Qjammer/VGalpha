#pragma once

#include <memory>
#include <string>
#include "../EntityExtensions/ObjectExtension.hpp"
#include <SFML/Graphics.hpp> // HAPPINESS

class GraphicObject: public ObjectExtension
{
public:
	GraphicObject(unsigned int _id);
	~GraphicObject();

	// Set and get functions. Nothing really hard
	sf::Sprite getSprite ();
	std::weak_ptr<sf::Texture> getTexturePtr(std::string _fileDir);



protected:
	std::weak_ptr<sf::Texture> texture_;
	sf::Sprite sprite_;
};
