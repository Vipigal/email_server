#include <iostream>
#include <fstream>
#include <string>
#include "user.hpp"



int main(int argc, char const *argv[]){
	
	std::ifstream input("input.txt");
	std::string buffer;

	while(getline(input,buffer)){
		
		std::cout<<buffer<<std::endl;

	}

	User* users;



	input.close();


	return 0;
}
