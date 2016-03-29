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
	void setSprite(sf::Sprite _sprite);

	void setTexture(std::string _fileDir);

	void setRect(sf::IntRect _rect);

	sf::Sprite getSprite ();
	std::shared_ptr<sf::Texture> getTexturePtr(std::string _fileDir);

	

protected:
	std::shared_ptr<sf::Texture> texture_;
	sf::Sprite sprite_;
};
