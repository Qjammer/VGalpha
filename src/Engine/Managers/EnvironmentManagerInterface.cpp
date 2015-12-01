
#include "./EnvironmentManagerInterface.hpp"

EnvironmentManagerInterface::EnvironmentManagerInterface(std::shared_ptr<EnvironmentManager> _mngr) : 
	ManagerInterface(_mngr),
	instance_ (_mngr)
{

}

EnvironmentManagerInterface::~EnvironmentManagerInterface()
{

}

bool EnvironmentManagerInterface::isTextureFileLoaded(std::string _fileName)
{
	return this->instance_->isTextureFileLoaded(_fileName);
}

std::shared_ptr<sf::Texture> EnvironmentManagerInterface::loadTexture(std::string _fileName)
{
	return this->instance_->loadTexture(_fileName);
}
