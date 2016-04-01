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

void GraphicObjectExtension::setTexture(sf::Texture _text)
{
	this->texture_ = (std::shared_ptr<sf::Texture>)&_text;
	this->sprite_.setTexture(_text, true);
}

void GraphicObjectExtension::setTexture(std::string _fileDir)
{
	this->texture_ = getTexturePtr(_fileDir);
	this->sprite_.setTexture(*this->texture_ , true);
}

void GraphicObjectExtension::setSpriteRect(sf::IntRect _rect)
{
	this->sprite_.setTextureRect(_rect);
}

void GraphicObjectExtension::setSpriteColor (sf::Color _color)
{
	this->sprite_.setColor (_color);
}

void GraphicObjectExtension::setSpritePosition (float _x, float _y)
{
	this->sprite_.setPosition(_x, _y);
}

void GraphicObjectExtension::setSpritePosition (sf::Vector2f _vect)
{
	this->sprite_.setPosition (_vect);
}

void GraphicObjectExtension::setSpriteRotation (float _alpha_beta_theta_fi_rho_omega_epsilon)
{
	this->sprite_.setRotation(_alpha_beta_theta_fi_rho_omega_epsilon);
}

void GraphicObjectExtension::setSpriteScale (float _x, float _y)
{
	this->sprite_.setScale (_x, _y);
}

void GraphicObjectExtension::setSpriteScale (sf::Vector2f _vect)
{
	this->sprite_.setScale (_vect);
}

void GraphicObjectExtension::setSpriteLocalOrigin (float _x, float _y)
{
	this->sprite_.setOrigin (_x, _y);
}

void GraphicObjectExtension::setSpriteLocalOrigin (sf::Vector2f _vect)
{
	this->sprite_.setOrigin (_vect);	
}





const sf::Sprite& GraphicObjectExtension::getSprite ()
{
	return this->sprite_;
}

std::shared_ptr<sf::Texture> GraphicObjectExtension::getTexturePtr(std::string _fileDir)
{
	return std::shared_ptr<sf::Texture> ();
}

// "A ella le gusta la gasolina. Dale gasolina" - Jesucristo, 25 d.C