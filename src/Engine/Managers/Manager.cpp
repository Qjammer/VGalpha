#include "Manager.hpp"

Manager::Manager()
{
	this->taskList_.push_back(this->updateTaskList);
}

Manager::~Manager()
{

}

std::list<std::function<int(void)>> Manager::getTaskList()
{
	return this->taskList_;
}

int Manager::updateTaskList()
{
	return 1;
}