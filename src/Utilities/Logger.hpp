#pragma once
#include <ctime>
#include <fstream>
#include <sstream>
#include <memory>

#define DEFAULT_LOGGER_OUTPUT "./log.log"
#define LOGGER_STATUS true
#define CONSOLE_STATUS false

class Logger {
public:
	Logger(std::string,bool,bool,std::weak_ptr<std::stringstream>);
	Logger();
	~Logger();
	void logError(std::string);
	void logWarning(std::string);
	void logMessage(std::string);
	std::string getTimestamp();

protected:
	void logString(std::string);
	std::string fileOutputDir_;
	std::ofstream fileOutputStream_;
	bool logStatus_;
	bool consoleStatus_;
	std::weak_ptr<std::stringstream> consoleStream_;
};

extern Logger LoggerInstance;

//ConcatenateTemplate should not be used, use concatenate(T...args)

template<typename S>
inline void concatenateTemplate(std::stringstream& ss, S s){
	ss<<s;
}

template<typename S,typename ...T>
inline void concatenateTemplate(std::stringstream& ss, S s,T... args){
	ss<<s;
	concatenateTemplate(ss,args...);
}


//IMPORTANT! ONLY USE WITH OBJECTS WITH OVERLOADED OPERATOR<<
template<typename ...T>
inline std::string concatenate(T...args){
	std::stringstream ss;
	concatenateTemplate(ss,args...);
	return ss.str();
}
