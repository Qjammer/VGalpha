#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include <chrono>
#include "./Systems/SystemInterface.hpp"
#include "./Engine/Managers/TaskManagerInterface.hpp"
#include "./Utilities/Logger.hpp"

class testSystem:public System{
public:
	testSystem(){};
	~testSystem(){};
	int mainTask(std::weak_ptr<TaskManagerInterface> taskManager_){
		printf("Main Task!\n");
		taskManager_.lock()->addTaskList(std::list<std::function<int(void)>>(10,[](){printf("Secondary Task!\n");return 0;}));
		return 0;
	}
};

class testSystemInterface:public SystemInterface{
public:
	testSystemInterface(std::weak_ptr<TaskManagerInterface> _tskmgr):SystemInterface(new testSystem(),_tskmgr){

	}
};

int main(){
	std::shared_ptr<TaskManagerInterface> tskmgr(std::make_shared<TaskManagerInterface>(2));
	testSystemInterface interf(tskmgr);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	tskmgr->addTask(std::bind(&testSystemInterface::mainTask,interf));
	tskmgr->addTask(std::bind(&testSystemInterface::mainTask,interf));
	//tskmgr->instance_->beginCycle();
	tskmgr->mainProcess();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	tskmgr->instance_->wakeUpandStopAll();
	tskmgr->instance_->joinThreads();
	return 1;
}
