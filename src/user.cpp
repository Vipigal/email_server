#include "user.hpp"
#include <iostream>

//FUNCOES USER

User::User(int identificador){
	id=identificador;
	inbox=new Inbox;
}
void User::addEmail(Email* email){
	inbox->add(email);
}

int User::getId() const {
	return id;
}

void User::readEmail(){
	Email* received=inbox->read();
	if(received!=nullptr){
		std::cout<<"CONSULTA "<<id<<": "<<received->getMessage()<<std::endl;
	}else{
		std::cout<<"CONSULTA "<<id<<": "<<"CAIXA DE ENTRADA VAZIA"<<std::endl;
	}
}

User::~User(){
	delete inbox;
}

//FUNCOES USERLIST

UserList::UserList(){
	first=last=nullptr;
	size=0;
}
bool UserList::empty(){
	return !size;
}
//Insere sempre no final
void UserList::insert(User* user){
	if(empty()){
		
		first=new No{user,nullptr};
		
		last=first;
		size++;
		std::cout<<"OK: CONTA "<<user->getId()<<" CADASTRADA"<<std::endl;
		
		return;
	}
	//testa se o usuario ja esta cadastrado
	No* iterator=first;
	while(iterator->user->getId()!=user->getId()){
		iterator=iterator->next;
		if(iterator==nullptr){
			No* newNo=new No{user,nullptr};
			last->next=newNo;
			last=newNo;
			size++;
			std::cout<<"OK: CONTA "<<user->getId()<<" CADASTRADA"<<std::endl;
			return;
		}
	}
	
	std::cout<<"ERRO: CONTA "<<user->getId()<<" JA EXISTENTE"<<std::endl;
	return;

}
void UserList::remove(int id){
	if(empty()){
		std::cout<<"ERRO: CONTA "<<id<<" NAO EXISTE"<<std::endl;
		return;
	}
	No* iterator=first;
	while(iterator->user->getId()!=id){
		iterator=iterator->next;
		if(iterator==nullptr){
			std::cout<<"ERRO: CONTA "<<id<<" NAO EXISTE"<<std::endl;
			return;
		}

	}

	delete iterator->user;
	std::cout<<"OK: CONTA "<<id<<" REMOVIDA"<<std::endl;

}

void UserList::printEmail(int id){
	if(empty()){
		std::cout<<"ERRO: CONTA "<<id<<" NAO EXISTE"<<std::endl;
		return;
	}
	No* iterator=first;
	while(iterator->user->getId()!=id){
		iterator=iterator->next;
		if(iterator==nullptr){
			std::cout<<"ERRO: CONTA "<<id<<" NAO EXISTE"<<std::endl;
			return;
		}
	}

	iterator->user->readEmail();

}

void UserList::addEmail(int id, Email* email){
	No* iterator=first;
	while(iterator->user->getId()!=id){
		iterator=iterator->next;
		if(iterator==nullptr){
			std::cout<<"ERRO: CONTA "<<id<<" NAO EXISTE"<<std::endl;
			return;
		}
	}

	iterator->user->addEmail(email);
	std::cout<<"OK: MENSAGEM PARA "<<id<<" ENTREGUE"<<std::endl;
}

UserList::~UserList(){
	No* p;
	p=first;
	while(p!=nullptr){
		first->next=p->next;
		delete p;
		p=first->next;
	}
	delete first;
	delete last;
	size=0;
}


