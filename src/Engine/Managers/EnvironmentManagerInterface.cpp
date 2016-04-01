
#include "./EnvironmentManagerInterface.hpp"

EnvironmentManagerInterface::EnvironmentManagerInterface(std::shared_ptr<EnvironmentManager> _mngr) :
	ManagerInterface(_mngr)
{

}

EnvironmentManagerInterface::~EnvironmentManagerInterface()
{

}

std::shared_ptr<sf::Texture> EnvironmentManagerInterface::loadTexture(std::string _fileName)
{
	return this->getInstance()->loadTexture(_fileName);
}
