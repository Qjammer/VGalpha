#include "./EnvironmentManager.hpp"

EnvironmentManager::EnvironmentManager():
	Manager(ENVIRONMENT),
	errorTexture_(new sf::Texture)
{

}

EnvironmentManager::~EnvironmentManager()
{

}

std::shared_ptr<sf::Texture> EnvironmentManager::loadTexture(std::string _fileName)
{
	auto __it(this->texturePtrMap_.find(_fileName));

	if (__it != this->texturePtrMap_.end())
	{
		return __it->second;
	}
	else
	{
		std::shared_ptr<sf::Texture> __texture (new sf::Texture);
		if (!__texture->loadFromFile(_fileName))
		{
			return this->errorTexture_;
		}
		else
		{
			this->texturePtrMap_.insert(std::pair<std::string, std::shared_ptr<sf::Texture>>(_fileName, std::shared_ptr<sf::Texture>(__texture)));
			return __texture;
		}
	}
}

//OUT_OF_RANGE ALERT
void EnvironmentManager::processCache()
{
	for (auto __it = this->texturePtrMap_.begin(); __it!=this->texturePtrMap_.end(); __it++)
	{
		if (__it->second.unique())
		{
			__it = this->texturePtrMap_.erase(__it);
			if (__it == this->texturePtrMap_.end())
			{
				break;
			}
		}
	}
}
