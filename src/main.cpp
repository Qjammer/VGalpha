#include <vector>
#include <memory>

#include "./Systems/Graphics/GraphicSystemInterface.hpp"
#include "./Systems/Logic/LogicSystemInterface.hpp"
#include "./Engine/Managers/IntBundle.hpp"
#include "./Utilities/Logger.hpp"
#include "./Engine/Engine.hpp"

#include <X11/Xlib.h>

int TheOneTrueMain(){
	XInitThreads();

	ManagerBundle mgrBundle;
	ManagerInterfaceBundle intBundle(mgrBundle);

	Engine engine(intBundle);

	std::vector<std::weak_ptr<SystemInterface>> vect;

	std::shared_ptr<GraphicSystem> gSys(std::make_shared<GraphicSystem>(intBundle));
	std::shared_ptr<SystemInterface> gSysI(std::make_shared<GraphicSystemInterface>(gSys));
	vect.push_back(std::weak_ptr<SystemInterface>(gSysI));

	std::shared_ptr<LogicSystem> lSys(std::make_shared<LogicSystem>(intBundle));
	std::shared_ptr<SystemInterface> lSysI(std::make_shared<LogicSystemInterface>(lSys));
	vect.push_back(std::weak_ptr<SystemInterface>(lSysI));

	engine.addSystemVector(vect);

	engine.gameLoop();

	mgrBundle.tskMgr_->wakeUpandStopAll();
	mgrBundle.tskMgr_->joinThreads();
	return 1;
}


int main()
{
	TheOneTrueMain();
	return 1;
}



