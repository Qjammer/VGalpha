#pragma once
#include <chrono>
#include <fstream>

#define DEFAULT_LOGGER_OUTPUT "./log.log"



class Logger {
public:
	Logger(std::string);
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

};

extern Logger LoggerInstance;
