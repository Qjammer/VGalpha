#include "GraphicObjectExtension.hpp"
#include "SFML/Graphics.hpp"

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

unsigned int GraphicObjectExtension::setTexture ()
{
	//has to communicate with texture manager, inc soon
	return 1;
}
