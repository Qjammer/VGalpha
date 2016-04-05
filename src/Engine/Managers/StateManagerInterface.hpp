#pragma once

#include "./StateManager.hpp"
#include "./ManagerInterface.hpp"

class StateManagerInterface: public ManagerInterface<StateManager>{
public:
	StateManagerInterface(std::shared_ptr<StateManager>);
	~StateManagerInterface();

	template<typename OBJS, typename SEN>
	void addChange(OBJS(SEN::*_getter)(void),std::weak_ptr<SEN> _sender){
		this->getInstance()->addChange(_getter,_sender);
	}
	template<typename OBJS,typename SEN,typename OBJR, typename REC>
	void addRequest(OBJS(SEN::*_getter)(void),
		            std::weak_ptr<SEN> _sender,
		            void(REC::*_setter)(OBJR),
		            std::weak_ptr<REC> _receiver){
		this->getInstance()->addRequest(_getter,_sender,_setter,_receiver);
	}
	void transferChanges(){
		this->getInstance()->transferChanges();
	}
};
