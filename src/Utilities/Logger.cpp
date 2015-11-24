#include "./Logger.hpp"

Logger::Logger(std::string _fileDir,bool _status):
	fileOutputDir_(_fileDir),
	fileOutputStream_(_fileDir,std::ofstream::out|std::ofstream::app),
	date_(""),
	logStatus_(_status)
{

}

Logger::Logger():Logger(DEFAULT_LOGGER_OUTPUT,LOGGER_STATUS){

}

Logger::~Logger(){

}

void Logger::logString(std::string _type, std::string _message){
	if(this->logStatus_){
		this->fileOutputStream_<<this->getTimestamp()<<" "<<_type<<": "<<_message<<std::endl;
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
