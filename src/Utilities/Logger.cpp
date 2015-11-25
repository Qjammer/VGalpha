#include "./Logger.hpp"

Logger::Logger(std::string _fileDir,bool _logStatus,bool _consoleStatus):
	fileOutputDir_(_fileDir),
	fileOutputStream_(_fileDir,std::ofstream::out|std::ofstream::app),
	date_(""),
	logStatus_(_logStatus),
	consoleStatus_(_consoleStatus),
	tempString_("")
{

}

Logger::Logger():Logger(DEFAULT_LOGGER_OUTPUT,LOGGER_STATUS,CONSOLE_STATUS){

}

Logger::~Logger(){

}

void Logger::logString(std::string _type, std::string _message){
	this->tempStringStream_.str(std::string());
	this->tempStringStream_.clear();
	this->tempStringStream_<<this->getTimestamp()<<" "<<_type<<": "<<_message<<std::endl;
	if(this->logStatus_){
		this->fileOutputStream_<<this->tempStringStream_.str();
	}
	if(this->consoleStatus_){
		*(this->consoleStream_.lock())<<this->tempStringStream_.str();
	}
}

void Logger::logError(std::string _message){
	this->logString("Error",_message);
}

void Logger::logWarning(std::string _message){
	this->logString("Warning",_message);
}

std::string Logger::getTimestamp(){
	time(&(this->timer));
	this->date_=ctime(&(this->timer));
	this->date_.pop_back();
	return this->date_;
}

Logger LoggerInstance;
