#include <iostream>
#include <fstream>
#include <string>
#include "user.hpp"



int main(int argc, char const *argv[]){
	
	std::ifstream input("input.txt");
	std::string buffer;

	User* users;

	while(getline(input,buffer)){
		
		
		if(buffer.find("CADASTRA")!=std::string::npos){
			//A posicao [9] da string sempre sera o ID do usuario
			
			std::cout<<buffer[9]<<std::endl;
		}

	}

	



	input.close();


	return 0;
}
