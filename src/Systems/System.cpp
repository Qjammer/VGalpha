#include "System.hpp"

System::System()
{

}

System::System(EntityType _type):type_(_type)
{

}

System::~System()
{

}

const EntityType& System::getType() const{
	return this->type_;
}