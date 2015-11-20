#include "./Logger.hpp"

Logger::Logger(std::string _fileDir):
	fileOutputDir_(_fileDir),
	fileOutputStream_(_fileDir,std::ofstream::out|std::ofstream::app)
{

}

Logger::Logger():Logger(DEFAULT_LOGGER_OUTPUT){

}

Logger::~Logger(){

}


void Logger::logString(std::string _type, std::string _message){
	this->fileOutputStream_<<this->getTimestamp()<<" "<<_type<<": "<<_message<<std::endl;
}

void Logger::logError(std::string _message){
	this->logString("Error",_message);
}
void Logger::logWarning(std::string _message){
	this->logString("Warning",_message);
}

std::string Logger::getTimestamp(){
	time(&(this->timer));
	return ctime(&(this->timer));
}

Logger LoggerInstance;