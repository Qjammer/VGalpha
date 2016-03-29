#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include <chrono>
#include <iostream>
#include "./Systems/SystemInterface.hpp"
#include "./Systems/Graphics/GraphicSystemInterface.hpp"
#include "./Engine/Managers/TaskManagerInterface.hpp"
#include "./Utilities/Logger.hpp"
#include "./Engine/Engine.hpp"

#include <X11/Xlib.h>

class testSystem:public System{
public:
	testSystem(){};
	~testSystem(){};
	int mainTask(std::weak_ptr<TaskManagerInterface> taskManager_){
		printf("MnTsk!");
		taskManager_.lock()->addTaskList(std::list<std::function<int(void)>>(500,[](){printf("SecTsk!");return 0;}));
		return 0;
	}
};

class testSystemInterface:public SystemInterface{
public:
	testSystemInterface(std::weak_ptr<testSystem> _sys,std::weak_ptr<TaskManagerInterface> _tskmgr):
		SystemInterface(_sys,_tskmgr)
	{

	}
};

int main(){
	XInitThreads();
	std::shared_ptr<TaskManager> tskmgr(std::make_shared<TaskManager>());
	std::shared_ptr<TaskManagerInterface> tskmgrI(std::make_shared<TaskManagerInterface>(tskmgr));

	std::vector<std::weak_ptr<SystemInterface>> vect;

	std::shared_ptr<testSystem> tstSys(std::make_shared<testSystem>());
	std::shared_ptr<SystemInterface> tstsysI(std::make_shared<testSystemInterface>(tstSys,tskmgrI));
	vect.push_back(std::weak_ptr<SystemInterface>(tstsysI));

	std::shared_ptr<GraphicSystem> gsys(std::make_shared<GraphicSystem>());
	std::shared_ptr<SystemInterface> gsysI(std::make_shared<GraphicSystemInterface>(gsys,tskmgrI));
	vect.push_back(std::weak_ptr<SystemInterface>(gsysI));

	Framework frmwrk(tskmgr,vect);
	frmwrk.gameLoop();

	tskmgr->wakeUpandStopAll();
	tskmgr->joinThreads();
	return 1;
}
