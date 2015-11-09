#include <iostream>
#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include "./Engine/Managers/ManagerInterface.hpp"
#include "./Engine/Framework/Scheduler/Scheduler.hpp"

class testManagerInterface : public ManagerInterface{
	std::function<void(void)> randomTask=[](){static std::atomic<int> i;if((++i%100000)==0)(printf("%i ",i.load()));};

	virtual std::list<std::function<void(void)>> mainTask(){
		std::list<std::function<void(void)>> rList(10,this->randomTask);
		return rList;
	};

};

int main(){
	setbuf(stdout,NULL);
	Scheduler schedulerInstance;

	std::shared_ptr<ManagerInterface> tstMngr(new testManagerInterface);
	schedulerInstance.addManager(tstMngr);
	std::shared_ptr<std::thread> thread1(new std::thread([&](){schedulerInstance.infiniteLoop(1);}));
	schedulerInstance.infiniteLoop(0);

	for(int i=0;i<10;++i){
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;

	std::list<int> lst;
	std::cout<<&*lst.begin()<<" "<<&*lst.end();
	std::cout<<std::endl;

	thread1->join();
	return 1;
}
