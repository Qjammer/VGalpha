#include <iostream>
#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include "./Engine/Managers/ManagerInterface.hpp"
#include "./Engine/Framework/Scheduler/Scheduler.hpp"

class testManagerInterface : public ManagerInterface{
	std::function<void(void)> randomTask=[](){static int i;printf("%i\n",i++);};

	virtual std::list<std::function<void(void)>> mainTask(){
		std::list<std::function<void(void)>> rList(10,this->randomTask);
		return rList;
	};

};

int main(){
	Scheduler schedulerInstance;

	std::shared_ptr<ManagerInterface> tstMngr(new testManagerInterface);
	schedulerInstance.addManager(tstMngr);


	for(int i=0;i<10;++i){
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;

	std::list<int> lst;
	std::cout<<&*lst.begin()<<" "<<&*lst.end();
	std::cout<<std::endl;


	return 1;
}
