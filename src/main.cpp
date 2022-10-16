#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "user.hpp"


int main(int argc, char const *argv[]){
	
	std::ifstream input("input.txt");
	std::string buffer;

	if(!input){
		std::cerr<<"Nao foi possivel abrir o arquivo de input!"<<std::endl;
		return -1;
	}

	//User* users;

	while(getline(input,buffer)){ //le uma string do arquivo de comandos
		std::stringstream s(buffer);
		std::string command;
		int id;
		//salva o comando e o id referente ao usuario
		s>>command>>id;
		//separa os comandos por casos: Entrega, Consulta, Cadastra e Remove
		if(command=="ENTREGA"){
			int pri;
			s>>pri;
			std::string word, message{};
			while(s>>word && word!= "FIM"){
				message+= word;
				message+= " ";
			}
			std::cout<<command<<" "<<id<<" "<<pri<<" "<<message<<std::endl;
		}
		if(command=="CADASTRA"){
			new User(id);
		}
		


	}

	



	input.close();


	return 0;
}
