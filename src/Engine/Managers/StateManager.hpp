#pragma once

#include <memory>
#include <map>
#include <iostream>

#include "Manager.hpp"

class BaseRequest{
public:
	virtual void transferData()=0;
	virtual void* getSenderPointer()=0;
	virtual void* getGetterPointer()=0;
};

template<typename OBJ,typename SEN,typename REC>//All template parameters should be deduced from the constructor
class Request: public BaseRequest{
public:
	Request(
		    std::weak_ptr<REC> _receiver,
		    void(REC::*_setter)(OBJ),
		    std::weak_ptr<SEN> _sender,
		    OBJ(SEN::*_getter)(void)):
		receiver_(_receiver),
		setter_(_setter),
		sender_(_sender),
		getter_(_getter)
	{

	}

	void* getSenderPointer(){
		return this->sender_.lock().get();
	}

	void* getGetterPointer(){
		return (void*)this->getter_;
	}

	void transferData(){
		//Fuck these motherfuckin function pointers in this motherfuckin state manager!!
		(this->receiver_.lock().get()->*setter_)((this->sender_.lock().get()->*getter_)());
	}

	std::weak_ptr<REC> receiver_;
	void(REC::*setter_)(OBJ);

	std::weak_ptr<SEN> sender_;
	OBJ(SEN::*getter_)(void);

};


class BaseChange{
public:
	virtual void* getSenderPointer()=0;
	virtual void* getGetterPointer()=0;
	virtual bool getValidity()=0;
};

template<typename OBJ,typename SEN>
class Change:public BaseChange{
public:
	Change(std::weak_ptr<SEN> _sender,OBJ(SEN::*_getter)(void)):
		sender_(_sender),
		getter_(_getter)
	{

	}

	void* getSenderPointer(){
		return this->sender_.lock().get();
	}

	void* getGetterPointer(){
		return (void*)this->getter_;
	}
	bool getValidity(){
		return !this->sender_.expired();
	}

	std::weak_ptr<SEN> sender_;
	OBJ(SEN::*getter_)(void);
};

template<typename O1, typename S1, typename O2, typename S2>
bool operator<(const Change<O1,S1> _l, const Change<O2,S2> _r);

template<typename O1,typename S1,typename O2,typename S2,typename R2>
bool operator==(const Change<O1,S1> _l,const Request<O2,S2,R2> _r);

class StateManager: public Manager {
public:
	StateManager();
	~StateManager();

	template<typename OBJ, typename SEN>
	void addChange(std::shared_ptr<Change<OBJ,SEN>>);

	void addRequest(std::shared_ptr<BaseChange>,std::shared_ptr<BaseRequest>);
	template<typename OBJ,typename SEN, typename REC>
	void addRequest(std::weak_ptr<REC> _receiver,void(REC::*_setter)(OBJ),std::weak_ptr<SEN> _sender,OBJ(SEN::*_getter)(void)){
		this->addRequest(std::shared_ptr<Change<OBJ,SEN>>(_sender,_getter),std::make_shared<Request<OBJ,SEN,REC>>(_receiver,_setter,_sender,_getter));
	}

protected:
	void checkRequestValidity();
	void transferChanges();

	void clearChanges();

	std::multimap<std::shared_ptr<BaseChange>,std::shared_ptr<BaseRequest>> requestMap_;
	std::map<std::shared_ptr<BaseChange>,bool> changeMap_;

};
