#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include <chrono>
#include <iostream>
#include "./Systems/SystemInterface.hpp"
#include "./Engine/Managers/TaskManagerInterface.hpp"
#include "./Utilities/Logger.hpp"
#include "./Engine/Framework/Scheduler/Scheduler.hpp"

class testSystem:public System{
public:
	testSystem(){};
	~testSystem(){};
	int mainTask(std::weak_ptr<TaskManagerInterface> taskManager_){
		printf("MnTsk!");
		taskManager_.lock()->addTaskList(std::list<std::function<int(void)>>(300,[](){printf("SecTsk!");return 0;}));
		return 0;
	}
};

class testSystemInterface:public SystemInterface{
public:
	testSystemInterface(std::weak_ptr<TaskManagerInterface> _tskmgr):SystemInterface(new testSystem(),_tskmgr){

	}
};

int main(){

	std::shared_ptr<TaskManagerInterface> tskmgr(std::make_shared<TaskManagerInterface>());
	std::shared_ptr<SystemInterface> sysInter(std::make_shared<testSystemInterface>(tskmgr));
	std::vector<std::weak_ptr<SystemInterface>> vect;
	vect.push_back(std::weak_ptr<SystemInterface>(sysInter));

	Scheduler testScheduler(std::weak_ptr<TaskManagerInterface>(tskmgr),vect);

	int cycles=200;

	auto t1=std::chrono::system_clock::now();
	for(int i=0;i<cycles;i++){
		testScheduler.Execute();
	}
	auto t2=std::chrono::system_clock::now();
	std::cout<<std::endl<<"Ideal:"<<(testScheduler.timePerTick_*cycles).count()<<" Real:"<<(t2-t1).count()<<std::endl;

	tskmgr->getInstance()->wakeUpandStopAll();
	tskmgr->getInstance()->joinThreads();
	return 1;
}
