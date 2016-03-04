#include "Scheduler.hpp"

Scheduler::Scheduler(){

}

Scheduler::~Scheduler(){

}

void Scheduler::Execute(){
	//1.Determine systems to execute

	//2.Send such systems to the tasker by adding their main task to the queue

	//3.Wait for completion
	taskManager_.lock()->mainProcess();
}
