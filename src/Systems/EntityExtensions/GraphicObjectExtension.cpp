#include "GraphicObjectExtension.hpp"


GraphicObjectExtension::GraphicObjectExtension (unsigned int _id)  : ObjectExtension(EntityType::GRAPHICS, _id),sprite_()
{

}

GraphicObjectExtension::~GraphicObjectExtension ()
{
	
}

sf::Sprite GraphicObjectExtension::getSprite ()
{
	return this->sprite_;
}

std::weak_ptr<sf::Texture> GraphicObjectExtension::getTexturePtr(std::string _fileDir)
{
	return std::weak_ptr<sf::Texture> ();
}