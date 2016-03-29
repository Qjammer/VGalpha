#include "GraphicObjectExtension.hpp"


GraphicObjectExtension::GraphicObjectExtension (unsigned int _id)  : ObjectExtension(EntityType::GRAPHICS, _id),sprite_()
{

}

GraphicObjectExtension::~GraphicObjectExtension ()
{
	
}

void GraphicObjectExtension::setSprite(sf::Sprite _sprite)
{
	this->sprite_ = _sprite;
}

void GraphicObjectExtension::setTexture(std::string _fileDir)
{
	this->sprite_.setTexture(getTexturePtr(_fileDir), true);
}

void GraphicObjectExtension::setRect(sf::IntRect _rect)
{
	this->sprite_.setTextureRect(_rect);
}

sf::Sprite GraphicObjectExtension::getSprite ()
{
	return this->sprite_;
}

std::shared_ptr<sf::Texture> GraphicObjectExtension::getTexturePtr(std::string _fileDir)
{
	return std::shared_ptr<sf::Texture> ();
}