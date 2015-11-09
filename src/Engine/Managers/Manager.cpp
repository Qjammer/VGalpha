#include "Manager.hpp"

Manager::Manager(unsigned int _entrancePoints)
{
	for (unsigned int i = 0; i < _entrancePoints; i++)
	{
		this->mutexVector_.emplace_back(void);
	}
}

Manager::~Manager()
{

}
