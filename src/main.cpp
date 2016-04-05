#include <vector>
#include <memory>

#include "./Systems/Graphics/GraphicSystemInterface.hpp"
#include "./Systems/Logic/LogicSystemInterface.hpp"
#include "./Engine/Managers/IntBundle.hpp"
#include "./Utilities/Logger.hpp"
#include "./Engine/Engine.hpp"

#include <X11/Xlib.h>

int TheOneTrueMain(){
	XInitThreads();

	ManagerBundle mgrBundle;
	ManagerInterfaceBundle intBundle(mgrBundle);

	Engine engine(intBundle);

	std::vector<std::weak_ptr<SystemInterface>> vect;

	std::shared_ptr<GraphicSystem> gSys(std::make_shared<GraphicSystem>(intBundle));
	std::shared_ptr<SystemInterface> gSysI(std::make_shared<GraphicSystemInterface>(gSys));
	vect.push_back(std::weak_ptr<SystemInterface>(gSysI));

	std::shared_ptr<LogicSystem> lSys(std::make_shared<LogicSystem>(intBundle));
	std::shared_ptr<SystemInterface> lSysI(std::make_shared<LogicSystemInterface>(lSys));
	vect.push_back(std::weak_ptr<SystemInterface>(lSysI));

	engine.addSystemVector(vect);

	engine.gameLoop();

	mgrBundle.tskMgr_->wakeUpandStopAll();
	mgrBundle.tskMgr_->joinThreads();
	return 1;
}

class TestClass1{
public:
	TestClass1(float i):testObject_(i){}
	void setObject(float _obj){
		printf("called setter!\n");
		this->testObject_=_obj;
	}

	float getObject(){
		printf("called getter!\n");
		return this->testObject_;
	}

	float testObject_;
};

class TestClass2{
public:
	TestClass2(int i):testObject_(i){}
	void setObject(int _obj){
		printf("called setter!\n");
		printf("Pointer to %p\n",(void*)this);
		this->testObject_=_obj;
	}

	int getObject(){
		printf("called getter!\n");
		return this->testObject_;
	}

	int testObject_;
};


int main()
{
	std::shared_ptr<StateManager> sttMgrr(std::make_shared<StateManager>());
	StateManagerInterface sttMgr(sttMgrr);
	auto tObjGet(std::make_shared<TestClass1>(5.0f));
	auto tObjSet(std::make_shared<TestClass2>(1));
	sttMgr.addRequest(&TestClass1::getObject,std::weak_ptr<TestClass1>(tObjGet),&TestClass2::setObject,std::weak_ptr<TestClass2>(tObjSet));
	sttMgr.addChange(&TestClass1::getObject,std::weak_ptr<TestClass1>(tObjGet));

	printf("Sender Value Before Transfer:%f\nReceiver Value Before Transfer:%i\n",tObjGet->getObject(),tObjSet->getObject());
	// Change<float,TestClass1> change1(&TestClass1::getObject,tObjGet);
	// Request<float,TestClass1,int,TestClass2> req1(&TestClass1::getObject,tObjGet,&TestClass2::setObject,tObjSet);
	// req1.transferData();
	sttMgr.transferChanges();
	printf("%p\n",(void*)tObjSet.get());
	printf("Sender Value After Transfer:%f\nReceiver Value After Transfer:%i\n",tObjGet->getObject(),tObjSet->getObject());

	// TheOneTrueMain();
	return 1;
}



