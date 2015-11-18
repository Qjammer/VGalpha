#include "Manager.hpp"

Manager::Manager(Manager::MNGR_TYPE _type):mngr_type_(_type)
{

}

Manager::~Manager()
{

}

const Manager::MNGR_TYPE Manager::getType() const{
	return this->mngr_type_;
}

