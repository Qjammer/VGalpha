#include "./StateManager.hpp"

StateManager::StateManager():
	Manager(STATE),
	requestMap_(),
	mutexVector_(TaskManager::getCores()),
	changeMapVector_(TaskManager::getCores())
{

}

StateManager::~StateManager(){

}

void StateManager::addChange(std::shared_ptr<BaseChange> _change,int _thread){
	this->changeMapVector_[_thread].emplace(_change,true);
}

void StateManager::addChange(std::shared_ptr<BaseChange> _change){
	unsigned int i=0;
	while(true){
		if(this->mutexVector_[i].try_lock()){
			this->addChange(_change,i);
			return;
		}
		i=(i+1)%this->mutexVector_.size();
	}

}

void StateManager::addRequest(std::shared_ptr<BaseChange> _target,std::shared_ptr<BaseRequest> _req){
	this->requestMap_.emplace(_target,_req);
}

void StateManager::checkRequestValidity(){
	for(auto it=this->requestMap_.begin();it!=this->requestMap_.end();++it){
		if(!it->first->getValidity()){
			this->requestMap_.erase(it--);//This moves the iterator back BEFORE deleting it, but returns a copy of the previous object
		}
	}
}

void StateManager::aggregateChanges(){
	for(unsigned int i=0;i<this->changeMapVector_.size();++i){
		this->changeMap_.insert(this->changeMapVector_[i].begin(),this->changeMapVector_[i].end());
		this->changeMapVector_[i].clear();
	}
}

void StateManager::transferChanges(){
	this->checkRequestValidity();
	this->aggregateChanges();
	for(auto it=this->requestMap_.begin();it!=this->requestMap_.end();++it){
		if(this->changeMap_.find(it->first)!=this->changeMap_.end()){//We don't need checking if the value is true, since only changes done this tick should be in here
			it->second->transferData();
		}
	}
	this->clearChanges();
}

void StateManager::clearChanges(){
	this->changeMap_.clear();
}
