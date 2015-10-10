#pragma once
#include <memory>
#include <unordered_set>

class Object;

class UObject {
public:
	UObject();
	~UObject();
	void registerExtension(const std::shared_ptr<Object>&);
	void unregisterExtension(const std::shared_ptr<Object>&);

private:
	unsigned int id_;
	std::unordered_set< std::shared_ptr<Object> > extensions_;

};
