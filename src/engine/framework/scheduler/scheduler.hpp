#pragma once

class Scheduler {
public:
	Scheduler();
	Scheduler(const Scheduler&);//Copy constructor. Should not really be used

	~Scheduler();
	Scheduler& operator = (const Scheduler&);
private:
	int threadCount;

};

