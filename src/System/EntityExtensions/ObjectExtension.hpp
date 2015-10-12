#pragma once

class ObjectExtension {
public:
	ObjectExtension();
	~ObjectExtension();

private:
	enum Type {
		GRAPHICS,
		PHYSICS,
		INPUT,
		AI,
		AUDIO
	};
	Type type_;
	unsigned int id_;
};
