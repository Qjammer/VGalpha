#include "GraphicObject.hpp"


GraphicObject::GraphicObject (unsigned int _id)  : ObjectExtension(EntityType::GRAPHICS, _id),sprite_()
{

}

GraphicObject::~GraphicObject ()
{

}

sf::Sprite GraphicObject::getSprite ()
{
	return this->sprite_;
}

std::weak_ptr<sf::Texture> GraphicObject::getTexturePtr(std::string _fileDir)
{
	return std::weak_ptr<sf::Texture> ();
}
