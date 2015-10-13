#pragma once
#include <list>
#include <memory>

class ObjectExtension;

class UObject {
public:
	UObject();
	~UObject();
	void registerExtension(const std::shared_ptr<ObjectExtension>&);
	void unregisterExtension(const std::shared_ptr<ObjectExtension>&);

private:
	unsigned int id_;
	std::list< std::shared_ptr<ObjectExtension> > extensions_;

};
