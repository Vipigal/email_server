#ifndef USER_H
#define USER_H

#include <string>
#include "inbox.hpp"

class User{
	//Classe para o usuario do servidor.
	//Possui uma inbox e um identificador.
	public:
		//Cria um usuario novo
		//Cria uma inbox e seta seu identificador
		User(int identificador);

		//adiciona um email a inbox deste usuario
		void addEmail(Email* email);

		//retorna o id deste usuario
		int getId() const;

		//le o primeiro email na fila de inbox deste usuario
		void readEmail();

		//desaloca a memoria alocada para este usuario
		~User();

	private:
		int id;
		Inbox* inbox;
};


struct No{
	User* user;
	No* next;
};


class UserList{
	//Lista encadeada de usuarios para controle geral de adicao/remocao
	public:
		//cria uma lista de usuarios nova
		UserList();

		//retorna se a lista esta vazia (true) ou nao (false)
		bool empty();

		//Insere um usuario na lista (sempre no final)
		void insert(User* user);

		//remove um usuario da lista
		void remove(int id);

		//printa na saida padrao o email de maior prioridade do usuario com o id passado no parametro
		void printEmail(int id);

		//adiciona um email na inbox do usuario com id passado no parametro
		void addEmail(int id, Email* email);

		//desaloca a memoria da lista, apagando todos os usuarios.
		~UserList();


	private:
		No* first;
		No* last;
		int size;
		
};


#endif