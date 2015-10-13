#pragma once

class Scheduler {
public:
	Scheduler();
	Scheduler(const Scheduler&);

	~Scheduler();
	Scheduler& operator = (const Scheduler&);
private:
	int threadCount;

};
