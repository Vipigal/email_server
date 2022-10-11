#include "inbox.hpp"

Inbox::Inbox(){
	size=0;
	first=new Cell{.key=nullptr,.next=nullptr};
	last=first;
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
	last=first;
}

void Inbox::add(Email* email){
	Cell* newCell = new Cell;
	newCell->key=email;
	last->next=newCell;
	last=last->next;
	++size;

}

Email* Inbox::read(){
	if(empty()){
		throw "A caixa de entrada esta vazia!";
	}
	Email* aux;
	Cell* p;

	aux=first->next->key;
	p=first;
	first=first->next;

	delete p;
	--size;
	return aux;

}


Inbox::~Inbox(){
	clean();
	delete first;
}