#include "GraphicObject.hpp"


GraphicObject::GraphicObject(unsigned int _id):
	ObjectExtension(EntityType::GRAPHICS, _id),
	sprite_()
{

}

GraphicObject::~GraphicObject()
{

}

void GraphicObject::setSprite(sf::Sprite _sprite)
{
	this->sprite_ = _sprite;
}

void GraphicObject::setTexture(sf::Texture _text)
{
	this->texture_ = (std::shared_ptr<sf::Texture>)&_text;
	this->sprite_.setTexture(_text, true);
}

void GraphicObject::setTexture(std::string _fileDir)
{
	this->texture_ = getTexturePtr(_fileDir);
	this->sprite_.setTexture(*this->texture_ , true);
}

void GraphicObject::setSpriteRect(sf::IntRect _rect)
{
	this->sprite_.setTextureRect(_rect);
}

void GraphicObject::setSpriteColor (sf::Color _color)
{
	this->sprite_.setColor (_color);
}

void GraphicObject::setSpritePosition (float _x, float _y)
{
	this->sprite_.setPosition(_x, _y);
}

void GraphicObject::setSpritePosition (sf::Vector2f _vect)
{
	this->sprite_.setPosition (_vect);
}

void GraphicObject::setSpriteRotation (float _alpha_beta_theta_fi_rho_omega_epsilon)
{
	this->sprite_.setRotation(_alpha_beta_theta_fi_rho_omega_epsilon);
}

void GraphicObject::setSpriteScale (float _x, float _y)
{
	this->sprite_.setScale (_x, _y);
}

void GraphicObject::setSpriteScale (sf::Vector2f _vect)
{
	this->sprite_.setScale (_vect);
}

void GraphicObject::setSpriteLocalOrigin (float _x, float _y)
{
	this->sprite_.setOrigin (_x, _y);
}

void GraphicObject::setSpriteLocalOrigin (sf::Vector2f _vect)
{
	this->sprite_.setOrigin (_vect);
}

const sf::Sprite& GraphicObject::getSprite ()
{
	return this->sprite_;
}

std::shared_ptr<sf::Texture> GraphicObject::getTexturePtr(std::string _fileDir)
{
	return std::shared_ptr<sf::Texture> ();
}

// "A ella le gusta la gasolina. Dale gasolina" - Jesucristo, 25 d.C
