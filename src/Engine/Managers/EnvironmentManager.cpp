#include "EnvironmentManager.hpp"

EnvironmentManager::EnvironmentManager() : Manager(ENVIRONMENT), errorTexture_(new sf::Texture), 
cacheTickCounter(0), cacheTickCheck(1*600), cacheTickMax(3*600)
{

}

EnvironmentManager::~EnvironmentManager()
{

}

bool EnvironmentManager::isTextureFileLoaded(std::string _fileName)
{
	if (getTextureIterator(_fileName) == this->texturePtrMap_.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::shared_ptr<sf::Texture> EnvironmentManager::loadTexture(std::string _fileName)
{
	std::unordered_map<std::string, std::pair<std::shared_ptr<sf::Texture>, unsigned int>>::iterator __it;
	__it = this->texturePtrMap_.find(_fileName);

	if (__it != this->texturePtrMap_.end())
	{
		return __it._Ptr->_Myval.second.first;
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
			this->texturePtrMap_.insert(std::pair<std::string, std::pair<std::shared_ptr<sf::Texture>, unsigned int>>(_fileName, std::pair<std::shared_ptr<sf::Texture>,unsigned int>(__texture, 0)));
			return __texture;
		}
	}
}

std::unordered_map<std::string, std::pair<std::shared_ptr<sf::Texture>,unsigned int>>::const_iterator EnvironmentManager::getTextureIterator(std::string _fileName)
{
	return this->texturePtrMap_.find(_fileName);
}

void EnvironmentManager::processCache()
{
	if (this->cacheTickCounter >= this->cacheTickCheck)
	{
		for (auto __it(this->texturePtrMap_.begin()); __it != this->texturePtrMap_.end(); __it++)
		{
			if (__it->second.first.unique())
			{
				__it->second.second += cacheTickCheck;
				if (__it->second.second >= this->cacheTickMax)
				{
					this->texturePtrMap_.erase(__it);
				}
			}
			else
			{
				__it->second.second = 0;
			}
		}
	}
	else
	{
		this->cacheTickCounter++;
	}
}
