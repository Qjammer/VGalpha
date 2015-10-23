#pragma once

#include "ObjectExtension.hpp"
#include "SFML/Graphics.hpp"

class GraphicObjectExtension : public ObjectExtension
{
public:
	GraphicObjectExtension(unsigned int _id);
	~GraphicObjectExtension();
	sf::Sprite getSprite ();
	unsigned int setTexture();

protected:
	sf::Sprite sprite_;
};
