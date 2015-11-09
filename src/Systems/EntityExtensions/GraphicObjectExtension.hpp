#pragma once

#include <memory>
#include "ObjectExtension.hpp"
#include <SFML/Graphics.hpp> // HAPPINESS

class GraphicObjectExtension : public ObjectExtension
{
public:
	GraphicObjectExtension(unsigned int _id);
	~GraphicObjectExtension();

	// Set and get functions. Nothing really hard
	sf::Sprite& getSprite ();
	unsigned int setTexture(std::string _fileDir);
	std::shared_ptr<sf::Texture> getTexture();

	

protected:
	std::shared_ptr<sf::Texture> texture_;
	sf::Sprite sprite_;
};
