#include "inbox.hpp"
#include <iostream>

Inbox::Inbox(){
	size=0;
	first=new Cell{nullptr, nullptr};
}

bool Inbox::empty(){
	return !size;
}

void Inbox::clean(){
	Cell* p;
	p=first->next;
	while(p!=nullptr){
		first->next=p->next;
		delete p;
		p=first->next;
	}
	size=0;
}

//adiciona um email na fila, de acordo com sua prioridade
void Inbox::add(Email* email, int pri){
	//seta o rank do email
	email->setRank(pri);

	if(empty()){
		first=new Cell{email,nullptr};
		size++;
		return;
	}

	Cell* iterator=first;
	while(iterator->key->getRank()>=pri){
		if(iterator->next==nullptr){//caso o elemento seja o ultimo da fila
			iterator->next=new Cell{email,nullptr};
			size++;
			return;
		}
		else{
			if(iterator->next->key->getRank()>pri){
				iterator=iterator->next;
			}
			else{
				iterator->next=new Cell{email,iterator->next};
				size++;
				return;
			}
		}
	}
	first=new Cell{email,first};
	size++;
}

Email* Inbox::read(){
	if(empty()){
		throw "A caixa de entrada esta vazia!";
	}
	Email* aux;
	Cell* p;

	aux=first->key;
	p=first;
	first=first->next;

	delete p;
	--size;
	return aux;

}

int Inbox::getSize() const {
	return size;
}


Inbox::~Inbox(){
	clean();
	delete first;
}