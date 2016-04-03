#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include "./Systems/Graphics/GraphicSystemInterface.hpp"
#include "./Systems/Logic/LogicSystemInterface.hpp"
#include "./Engine/Managers/IntBundle.hpp"
#include "./Utilities/Logger.hpp"
#include "./Engine/Engine.hpp"

#include <X11/Xlib.h>

class testSystem:public System{
public:
	testSystem(ManagerInterfaceBundle _bndl):System(INPUT,_bndl){};
	~testSystem(){};
	int mainTask(){
		printf("MnTsk!");
		this->intBundle_.tskMgrI_->addTaskList(std::list<std::function<int(void)>>(500,[](){printf("SecTsk!");return 0;}));
		return 0;
	}

	void loadScene(std::stringstream){};
	void saveScene(std::string){};
	void objectFactory(std::stringstream){};
};

class testSystemInterface:public SystemInterface{
public:
	testSystemInterface(std::weak_ptr<testSystem> _sys):
		SystemInterface(_sys)
	{

	}
};

int main(){
	XInitThreads();

	ManagerBundle mgrBundle;
	ManagerInterfaceBundle intBundle(mgrBundle);

	Engine engine(intBundle);

	std::vector<std::weak_ptr<SystemInterface>> vect;

	std::shared_ptr<testSystem> tstSys(std::make_shared<testSystem>(intBundle));
	std::shared_ptr<SystemInterface> tstsysI(std::make_shared<testSystemInterface>(tstSys));
	vect.push_back(std::weak_ptr<SystemInterface>(tstsysI));

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
