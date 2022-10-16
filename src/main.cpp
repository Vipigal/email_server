#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "user.hpp"
#include "msgassert.h"


int main(int argc, char const *argv[]){

	std::string filename;
	for(int i=1;i<argc;i++){
		if(argv[i]==std::string("-i"))
			filename=argv[i+1];
	}

	std::ifstream input(filename);
	erroAssert(input,"Nao foi possivel abrir o arquivo de input! Favor inserir entrada valida com flag -i");
	
	std::string buffer;

	UserList* userList = new UserList;

	while(getline(input,buffer)){ //le uma string do arquivo de comandos
		std::stringstream s(buffer);
		std::string command;
		int id;
		//salva o comando e o id referente ao usuario
		s>>command>>id;

		//separa os comandos por casos: Entrega, Consulta, Cadastra e Remove
		if(command=="CADASTRA"){
			User* newUser = new User(id);
			userList->insert(newUser);
		}

		if(command=="CONSULTA"){
			userList->printEmail(id);
		}

		if(command=="ENTREGA"){
			int pri;
			s>>pri;
			std::string word, message{};
			while(s>>word && word!= "FIM"){
				message+= word;
				message+= " ";
			}
			Email* novoEmail=new Email(message);
			novoEmail->setRank(pri);
			userList->addEmail(id,novoEmail);
		}

		if(command=="REMOVE"){
			userList->remove(id);
		}

	}

	



	input.close();


	return 0;
}
