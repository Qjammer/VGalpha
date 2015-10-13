#include "UScene.hpp"

UScene::UScene(){

}

UScene::~UScene(){

}

void UScene::registerExtension(const std::shared_ptr<SceneExtension>& ptr){
	this->extensions_.push_back(ptr);
}

void UScene::unregisterExtension(const std::shared_ptr<SceneExtension>& ptr){
	this->extensions_.remove(ptr);
}

void UScene::registerUObject(const std::shared_ptr<UObject>& ptr){
	this->uObjects_.push_back(ptr);
}

void UScene::unregisterUObject(const std::shared_ptr<UObject>& ptr){
	this->uObjects_.remove(ptr);
}
