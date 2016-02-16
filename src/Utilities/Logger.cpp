#include "./Logger.hpp"

Logger::Logger(std::string _fileDir,bool _logStatus,bool _consoleStatus,std::weak_ptr<std::stringstream> _console):
	fileOutputDir_(_fileDir),
	fileOutputStream_(_fileDir,std::ofstream::out | std::ofstream::app),
	date_(std::string()),
	logStatus_(_logStatus),
	consoleStatus_(_consoleStatus),
	consoleStream_(_console),
	tempString_(std::string())
{

}

std::shared_ptr<std::stringstream> consoleStream(new std::stringstream());//TODO:  THis is temporary, as soon as we get a console it should construct from there
Logger::Logger():Logger(DEFAULT_LOGGER_OUTPUT,LOGGER_STATUS,CONSOLE_STATUS,consoleStream){

}

Logger::~Logger(){

}

void Logger::logString(std::string _message){
	std::string tstring(this->getTimestamp()+" "+_message+"\n");
	if(this->logStatus_){
		this->fileOutputStream_<<tstring;
		this->fileOutputStream_.flush();
	}
	if(this->consoleStatus_){
		*(this->consoleStream_.lock())<<tstring;
	}
}

void Logger::logError(std::string _message){
	this->logString("Error: "+_message);
}

void Logger::logWarning(std::string _message){
	this->logString("Warning: "+_message);
}

void Logger::logMessage(std::string _message){
	this->logString(_message);
}

std::string Logger::getTimestamp(){
	time(&(this->timer));
	std::string tdate(ctime(&(this->timer)));
	tdate.pop_back();
	return tdate;
}

Logger LoggerInstance;
