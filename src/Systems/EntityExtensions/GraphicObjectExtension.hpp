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

	// Set and get functions. Nothing really hard. MAY HAVE TO BE PROTECTED
	void setSprite(sf::Sprite _sprite);
	void setTexture(sf::Texture _text);
	void setTexture(std::string _fileDir);
	void setSpriteRect(sf::IntRect _rect);
	void setSpriteColor(sf::Color _color);
	void setSpritePosition (float _x, float _y);
	void setSpritePosition (sf::Vector2f _vect);
	void setSpriteRotation (float _alpha_beta_theta_fi_rho_omega_epsilon);
	void setSpriteScale (float _x, float _y);
	void setSpriteScale (sf::Vector2f _vect);
	void setSpriteLocalOrigin (float _x, float _y);
	void setSpriteLocalOrigin (sf::Vector2f _vect);


	const sf::Sprite& getSprite ();
	std::shared_ptr<sf::Texture> getTexturePtr(std::string _fileDir);

	virtual void draw();
	virtual void onGraphicTick();
	virtual void updateData(int _flag, void* _data);

protected:
	std::shared_ptr<sf::Texture> texture_;
	sf::Sprite sprite_;
};

// "La arena se compacta a base de compactarla" - Nacho "Dorito" Velasco, 2016