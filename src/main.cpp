#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include "./Engine/Managers/ManagerInterface.hpp"
#include "./Engine/Framework/Scheduler/Scheduler.hpp"

#include <chrono>

class testManagerInterface : public ManagerInterface{
	std::function<void(void)> randomTask=[](){static std::atomic<int> i;if((++i%100000)==0)(printf("%i ",i.load()));};

	virtual std::list<std::function<void(void)>> mainTask(){
		std::list<std::function<void(void)>> rList(10,this->randomTask);
		return rList;
	};

};

int main(){
	Scheduler schedulerInstance(3);

	std::shared_ptr<ManagerInterface> tstMngr(new testManagerInterface);
	schedulerInstance.addManager(tstMngr);
	schedulerInstance.initThreadLoop(2);
	schedulerInstance.initThreadLoop(1);
	//schedulerInstance.initThreadLoop(0);
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	schedulerInstance.stopThreadLoop(2);
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	schedulerInstance.stopThreadLoop(1);
	return 1;
}
