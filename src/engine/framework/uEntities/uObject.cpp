#include "uObject.hpp"

UObject::UObject(){

}

UObject::~UObject(){

}

void UObject::registerExtension(const std::shared_ptr<Object>& ptr){
	this->extensions_.insert(ptr);
}

void UObject::unregisterExtension(const std::shared_ptr<Object>& ptr){
	this->extensions_.erase(ptr);
}