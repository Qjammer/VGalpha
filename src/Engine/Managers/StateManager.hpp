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

template<typename OBJS,typename SEN,typename OBJR,typename REC>//All template parameters should be deduced from the constructor
class Request: public BaseRequest{
public:
	Request(
		    OBJS(SEN::*_getter)(void),
		    std::weak_ptr<SEN> _sender,
		    void(REC::*_setter)(OBJR),
		    std::weak_ptr<REC> _receiver):
		getter_(_getter),
		sender_(_sender),
		setter_(_setter),
		receiver_(_receiver)
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
		(this->receiver_.lock().get()->*setter_)(OBJR((this->sender_.lock().get()->*getter_)()));
	}

	OBJS(SEN::*getter_)(void);
	std::weak_ptr<SEN> sender_;

	void(REC::*setter_)(OBJR);
	std::weak_ptr<REC> receiver_;
};


class BaseChange{
public:
	virtual void* getSenderPointer()=0;
	virtual void* getGetterPointer()=0;
	virtual bool getValidity()=0;
};

template<typename OBJS,typename SEN>
class Change:public BaseChange{
public:
	Change(OBJS(SEN::*_getter)(void),std::weak_ptr<SEN> _sender):
		getter_(_getter),
		sender_(_sender)
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

	OBJS(SEN::*getter_)(void);
	std::weak_ptr<SEN> sender_;
};

template<typename O1, typename S1, typename O2, typename S2>
bool operator<(const Change<O1,S1> _l, const Change<O2,S2> _r);

template<typename OS1,typename S1,typename OS2,typename S2,typename OR2,typename R2>
bool operator==(const Change<OS1,S1> _l,const Request<OS2,S2,OR2,R2> _r);

class StateManager: public Manager {
public:
	StateManager();
	~StateManager();

	template<typename OBJS, typename SEN>
	void addChange(std::shared_ptr<Change<OBJS,SEN>>);

	void addRequest(std::shared_ptr<BaseChange>,std::shared_ptr<BaseRequest>);

	template<typename OBJS,typename SEN,typename OBJR, typename REC>
	void addRequest(OBJS(SEN::*_getter)(void),
		            std::weak_ptr<SEN> _sender,
		            void(REC::*_setter)(OBJR),
		            std::weak_ptr<REC> _receiver){
		this->addRequest(
			std::make_shared<Change<OBJS,SEN>>(_getter,_sender),
			std::make_shared<Request<OBJS,SEN,OBJR,REC>>(_getter,_sender,_setter,_receiver));
	}

protected:
	void checkRequestValidity();
	void transferChanges();

	void clearChanges();

	std::multimap<std::shared_ptr<BaseChange>,std::shared_ptr<BaseRequest>> requestMap_;
	std::map<std::shared_ptr<BaseChange>,bool> changeMap_;

};
