#include "UObject.hpp"

UObject::UObject(){

}

UObject::~UObject(){

}

void UObject::registerExtension(const std::shared_ptr<ObjectExtension>& ptr){
	this->extensions_.push_back(ptr);
}

void UObject::unregisterExtension(const std::shared_ptr<ObjectExtension>& ptr){
	this->extensions_.remove(ptr);
}