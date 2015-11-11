#pragma once

#include <memory>
#include <string>
#include "ObjectExtension.hpp"
#include <SFML/Graphics.hpp> // HAPPINESS

class GraphicObjectExtension : public ObjectExtension
{
public:
	GraphicObjectExtension(unsigned int _id);
	~GraphicObjectExtension();

	// Set and get functions. Nothing really hard
	sf::Sprite getSprite ();
	std::weak_ptr<sf::Texture> getTexturePtr(std::string _fileDir);

	

protected:
	std::weak_ptr<sf::Texture> texture_;
	sf::Sprite sprite_;
};
