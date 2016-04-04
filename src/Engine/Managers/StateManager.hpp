#pragma once

#include <memory>
#include <map>

#include "Manager.hpp"

class BasicRequest{
public:
	BasicRequest(void*);
	virtual void setData()=0;
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

class Change{
public:
	Change(void*,std::weak_ptr<void>);
	void* param_;
	std::weak_ptr<void> obj_;
};

bool operator<(const Change _l, const Change _r);

class StateManager: public Manager {
public:
	StateManager();
	~StateManager();
	void addChange(void*,std::weak_ptr<void>);
	void addRequest(Change,std::shared_ptr<BasicRequest>);

	void checkValidity();
	void shareChanges();

	void clearChanges();


protected:
	std::multimap<Change,std::shared_ptr<BasicRequest>> requestMap_;
	std::map<Change,bool> changeMap_;

};
