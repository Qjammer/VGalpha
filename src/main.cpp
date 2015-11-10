#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include "./Engine/Managers/ManagerInterface.hpp"
#include "./Engine/Framework/Scheduler/Scheduler.hpp"

#include <chrono>

class testManagerInterface : public ManagerInterface{
	static std::atomic<int> i;
	Scheduler& sch;
	std::function<void(void)> randomTask=[&](){
		for(int j=0; j<10000;j++){
			j++;
			j--;
		}
		if((++(this->i)%10)==0){
			printf("%i ",i.load());
		}
	};
public:
	testManagerInterface(Scheduler& _sch):sch(_sch){};
	virtual std::list<std::function<void(void)>> mainTask(){
		std::list<std::function<void(void)>> rList(25,this->randomTask);
		if(this->i>3000){
			rList.push_back([this](){this->sch.stopAllThreads();});
		}
		return rList;
	};

};

std::atomic<int> testManagerInterface::i;

int main(){
	Scheduler schedulerInstance(3);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::shared_ptr<ManagerInterface> tstMngr(new testManagerInterface(schedulerInstance));
	schedulerInstance.addManager(tstMngr);
	schedulerInstance.initAllThreads();
	schedulerInstance.joinAllThreads();

	return 1;
}
