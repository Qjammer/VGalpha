#include "./StateManager.hpp"

BasicRequest::BasicRequest(void*_par):param_(_par){

}

Change::Change(void* _par,std::weak_ptr<void> _obj):param_(_par),obj_(_obj){

}

bool operator<(const Change _l, const Change _r){
	return _l.param_<_r.param_;
}

StateManager::StateManager():
	Manager(STATE),
	requestMap_(),
	changeMap_()
{

}

StateManager::~StateManager(){

}

void StateManager::addChange(void* _par,std::weak_ptr<void> _obj){
	this->changeMap_.emplace(Change(_par,_obj),true);

}

void StateManager::addRequest(Change _target,std::shared_ptr<BasicRequest> _req){
	this->requestMap_.emplace(_target,_req);
}

void StateManager::checkRequestValidity(){
	for(auto it=this->requestMap_.begin();it!=this->requestMap_.end();++it){
		if(it->first.obj_.use_count()==0){
			this->requestMap_.erase(it--);//This moves the iterator back BEFORE deleting it, but returns a copy of the previous object
		}
	}
}

void StateManager::shareChanges(){
	for(auto it=this->requestMap_.begin();it!=this->requestMap_.end();++it){
		if(this->changeMap_.find(it->first)!=this->changeMap_.end()){//We don't need checking if the value is true, since it CAN ONLY BE TRUE
			it->second->setData();
		}
	}
}

void StateManager::clearChanges(){
	this->changeMap_.clear();
}
