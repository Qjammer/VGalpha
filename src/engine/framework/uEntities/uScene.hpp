#pragma once

class UScene {
public:
	UScene();
	~UScene();

private:
	std::list<std::shared_ptr<UObject>> uObjects_;

};
