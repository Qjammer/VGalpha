#pragma once

#include "Manager.hpp"
#include "SFML\Graphics.hpp"
#include <string>
#include <list>
#include <unordered_map>

class EnvironmentManager : public Manager
{
public:
	EnvironmentManager();
	~EnvironmentManager();

	bool isTextureFileLoaded(std::string _fileName);
	
	//File Overload
	std::shared_ptr<sf::Texture> loadTexture(std::string _fileName);

	void processCache();

protected:
	std::unordered_map<std::string, std::pair<std::shared_ptr<sf::Texture>, unsigned int>>::const_iterator getTextureIterator(std::string _fileName);


	std::unordered_map<std::string, std::pair<std::shared_ptr<sf::Texture>, unsigned int>>  texturePtrMap_;
	std::shared_ptr<sf::Texture> errorTexture_;

	unsigned int cacheTickCounter;
	unsigned int cacheTickCheck;
	unsigned int cacheTickMax;
};