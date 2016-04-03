#include "System.hpp"

System::System(EntityType _type, ManagerInterfaceBundle _intBundle):type_(_type),intBundle_(_intBundle)
{

}

System::~System()
{

}

EntityType System::getType() const{
	return this->type_;
}
