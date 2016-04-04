#include "./StateManager.hpp"

template<typename O1, typename S1, typename O2, typename S2>
bool operator<(const Change<O1,S1> _l, const Change<O2,S2> _r){//This needs to be reworked severely
	return _l.param_<_r.param_;
}

template<typename O1,typename S1,typename O2,typename S2,typename R2>
bool operator==(const Change<O1,S1> _l,const Request<O2,S2,R2> _r){
	return (_l.getSetterPointer()==_r.getSetterPointer())&&(_l.getSenderPointer()==_r.getSenderPointer());
}

StateManager::StateManager():
	Manager(STATE),
	requestMap_(),
	changeMap_()
{

}

StateManager::~StateManager(){

}

template<typename OBJ, typename SEN>
void StateManager::addChange(std::shared_ptr<Change<OBJ,SEN>> _change){
	this->changeMap_.emplace(_change,true);

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

void StateManager::transferChanges(){
	for(auto it=this->requestMap_.begin();it!=this->requestMap_.end();++it){
		if(this->changeMap_.find(it->first)!=this->changeMap_.end()){//We don't need checking if the value is true, since it CAN ONLY BE TRUE
			it->second->transferData();
		}
	}
}

void StateManager::clearChanges(){
	this->changeMap_.clear();
}
