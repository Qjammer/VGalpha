#pragma once

class Object {
public:
	Object();
	~Object();

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
