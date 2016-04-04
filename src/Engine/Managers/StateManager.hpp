#pragma once

#include <memory>
#include <map>

#include "Manager.hpp"

typedef void* Change;

class BasicRequest{
public:
	BasicRequest(void* _par):param_(_par){}
	virtual void setData()=0;
	void* getParamVoidPtr(){return this->param_;};
	void* param_;
};

template<typename OBJ>
class Request:public BasicRequest{
public:
	Request(OBJ* _par, std::function<void(OBJ)> _func):BasicRequest(_par),setOBJ_(_func){}
	void setData(){
		this->setOBJ_(*static_cast<OBJ*>(this->param_));
	}
	std::function<void(void*)> setOBJ_;

};

class StateManager: public Manager {
public:
	StateManager();
	~StateManager();

	std::multimap<Change,std::shared_ptr<BasicRequest>> changeMap_;

};
