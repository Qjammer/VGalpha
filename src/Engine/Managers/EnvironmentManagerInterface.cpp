
#include "./EnvironmentManagerInterface.hpp"

EnvironmentManagerInterface::EnvironmentManagerInterface(std::shared_ptr<EnvironmentManager> _mngr) :
	ManagerInterface(_mngr)
{

}

EnvironmentManagerInterface::~EnvironmentManagerInterface()
{

}

bool EnvironmentManagerInterface::isTextureFileLoaded(std::string _fileName)
{
	return this->getInstance()->isTextureFileLoaded(_fileName);
}

std::shared_ptr<sf::Texture> EnvironmentManagerInterface::loadTexture(std::string _fileName)
{
	return this->getInstance()->loadTexture(_fileName);
}
