#include <iostream>
#include <list>

int main(){

	std::list<int> lst;
	for(int i=0;i<10;++i){
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<&*lst.begin()<<" "<<&*lst.end();
	std::cout<<std::endl;


	return 1;
}
