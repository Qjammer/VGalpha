#include "GraphicObjectExtension.hpp"

GraphicObjectExtension::GraphicObjectExtension (unsigned int _id)  : ObjectExtension(EntityType::GRAPHICS, _id)
{
	this->sprite_ = sf::Sprite ();
}

GraphicObjectExtension::~GraphicObjectExtension ()
{
	
}

sf::Sprite GraphicObjectExtension::getSprite ()
{
	return this->sprite_;
}

unsigned int GraphicObjectExtension::setTexture (std::string _fileName)
{
	//has to communicate with texture manager, inc soon
	return 0;
}

std::shared_ptr<sf::Texture> GraphicObjectExtension::getTexture()
{
	return this->texture_;
}
