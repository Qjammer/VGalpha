#include <list>
#include <string>
#include <fstream>
#include <regex>
#include <iostream>
#include <sstream>

#define OBJPATH "../obj/"

std::string removePath(std::string nm);

class file{
public:
	file(std::string fnm):filename(fnm){}
	std::string filename;


	std::string printRule(){
		std::string ret(OBJPATH);
		system(("g++ -std=c++14 -MM "+this->filename+" >> temp.txt").c_str());
		std::ifstream dStream("temp.txt");
		std::string filesText((std::istreambuf_iterator<char>(dStream))
			                 ,(std::istreambuf_iterator<char>()));
		system("rm temp.txt");
		filesText+=("\t$(CC) $(CFLAGS) "+this->filename+" $(FFLAGS)\n");
		return ret+filesText;

	}
};

std::string createMakefile(std::list<file> files){
	std::stringstream strm;
	strm<<"CC = g++\nDEBUG = -g\nCFLAGS = -Wall -pedantic -pthread -std=c++11 -c $(DEBUG)\nLFLAGS = -Wall $(DEBUG) -pthread\nFFLAGS = -o $@\nLIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio\nEXEC = game\n\n";

	for(auto it=files.begin();it!=files.end();it++){
		strm<<it->printRule()<<std::endl<<std::endl;
	}

	strm<<"clean:\n\trm ../obj/*.o\n../obj/:\n\tmkdir ../obj/\nOBJDIR:|../obj/\n\n";
	strm<<"$(EXEC): OBJDIR ";
	for(auto it=files.begin();it!=files.end();it++){
		std::string WOPath(removePath(it->filename));
		strm<<OBJPATH<<std::string(WOPath.begin(),WOPath.end()-3)+"o ";
		if(it!=--files.end()){
			strm<<"\\"<<std::endl;
		} else {
			strm<<std::endl;
		}
	}
	strm<<"\t$(CC) $(LFLAGS) -o $(EXEC) ../obj/*.o $(LIBS)\n";
	strm<<"\n\n.DEFAULT_GOAL:=$(EXEC)\n";
	strm<<"\n.PHONY:clean OBJDIR\n";
	return strm.str();
}


std::string removePath(std::string nm){
	std::string::iterator it(nm.end());
	for(;*it!='/';it--){
		if(it==nm.begin()){
			return nm;
		}
	}
	return std::string(it+1,nm.end());

}

int main(){
	system("find -type f>>temp.txt");
	std::ifstream tStream("./temp.txt");
	std::string filesText((std::istreambuf_iterator<char>(tStream))
		                 ,(std::istreambuf_iterator<char>()));
	system("rm temp.txt");

	std::stringstream strm;
	strm<<filesText;

	std::list<file> files;
	while(!strm.eof()){
		std::string nm;
		getline(strm,nm);
		if(nm.begin()!= nm.end()){
			if(std::string(nm.end()-4,nm.end())==".cpp"){
				files.push_back(file(nm));
			}
		}
	}
	std::ofstream make("makefile",std::ofstream::trunc);
	make<<createMakefile(files);
	// std::cout<<createMakefile(files);
}
