#pragma once
#include <list>
#include <memory>

class UObject;
class SceneExtension;

class UScene {
public:
	UScene();
	~UScene();
	void registerExtension(const std::shared_ptr<SceneExtension>&);
	void unregisterExtension(const std::shared_ptr<SceneExtension>&);

	void registerUObject(const std::shared_ptr<UObject>&);
	void unregisterUObject(const std::shared_ptr<UObject>&);
	
private:
	std::list<std::shared_ptr<UObject>> uObjects_;
	std::list<std::shared_ptr<SceneExtension>> extensions_;


};
