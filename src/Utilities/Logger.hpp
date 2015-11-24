#pragma once
#include <ctime>
#include <fstream>

#define DEFAULT_LOGGER_OUTPUT "./log.log"
#define LOGGER_STATUS true

class Logger {
public:
	Logger(std::string,bool);
	Logger();
	~Logger();
	void logError(std::string);
	void logWarning(std::string);
	std::string getTimestamp();

protected:
	void logString(std::string,std::string);
	std::string fileOutputDir_;
	std::ofstream fileOutputStream_;
	time_t timer;
	std::string date_;
	bool logStatus_;
};

extern Logger LoggerInstance;
