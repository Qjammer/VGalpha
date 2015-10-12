#pragma once

class SceneExtension {
public:
	SceneExtension();
	~SceneExtension();

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
