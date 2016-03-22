#pragma once

#include "Manager.hpp"
#include <list>
#include <functional>
#include <memory>

template<typename MType=Manager>
class ManagerInterface{
public:

	ManagerInterface(std::shared_ptr<MType> _mngr);
	~ManagerInterface();
	std::shared_ptr<MType> getInstance();

protected:

	std::weak_ptr<MType> instance_;

};

template<typename MType>
ManagerInterface<MType>::ManagerInterface(std::shared_ptr<MType> _mngr) :
	instance_(_mngr)
{

}

template<typename MType>
ManagerInterface<MType>::~ManagerInterface()
{

}

template<typename MType>
std::shared_ptr<MType> ManagerInterface<MType>::getInstance()
{
	return this->instance_.lock();
}
