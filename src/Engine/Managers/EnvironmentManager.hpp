#pragma once

#include "Manager.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include <unordered_map>
#include <memory>

class EnvironmentManager : public Manager
{
public:
	EnvironmentManager();
	~EnvironmentManager();
	
	//File Overload
	std::shared_ptr<sf::Texture> loadTexture(std::string _fileName);

	void cleanCache();

protected:
	
	std::unordered_map<std::string, std::shared_ptr<sf::Texture>>  texturePtrMap_;
	std::shared_ptr<sf::Texture> errorTexture_;
};
