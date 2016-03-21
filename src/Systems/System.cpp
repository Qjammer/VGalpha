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

EntityType System::getType() const{
	return this->type_;
}
