#include "Systems/EntityExtensions/GraphicObjectExtension.hpp"


/* TR4C3S 0F R4M1R0'S T35T
#include <list>
#include <functional>
#include <memory>
#include <cstdio>
#include <chrono>
#include <iostream>
#include "./Systems/SystemInterface.hpp"
#include "./Engine/Managers/TaskManagerInterface.hpp"
#include "./Utilities/Logger.hpp"
#include "./Engine/Engine.hpp"


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
*/

int main()
{


	return 1;
}
