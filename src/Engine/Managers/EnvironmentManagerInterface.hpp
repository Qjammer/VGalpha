#pragma once

#include "./ManagerInterface.hpp"
#include "./EnvironmentManager.hpp"

class EnvironmentManagerInterface : public ManagerInterface<EnvironmentManager>
{
public:
	EnvironmentManagerInterface(std::shared_ptr<EnvironmentManager> _mngr);
	~EnvironmentManagerInterface();


	bool isTextureFileLoaded(std::string _fileName);

	//File Overload
	std::shared_ptr<sf::Texture> loadTexture(std::string _fileName);

protected:

};
