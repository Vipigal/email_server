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

//adiciona um email na fila, de acordo com sua prioridade
void Inbox::add(Email* email, int pri){
	//seta o rank do email
	email->setRank(pri);

	/*loop para posicionar o iterador na posicao anterior a que se deve inserir o email
	Se ha dois emails com prioridades 5 e 3, e se quer adicionar um com pri=4, o iterador sera parado na posicao do email com pri=5*/

	Cell* iterator;
	iterator=first;
	if(first->key!=nullptr){ //se a primeira chave eh nula, quer dizer que a inbox esta vazia, nenhum email foi adicionado ainda
		while(iterator->next->key->getRank() > pri && iterator->next!=nullptr){
			iterator=iterator->next;
		}
	}

	//cria uma nova celula com o email desejado, e a insere na posicao next do iterador.
	Cell* newCell = new Cell;
	newCell->key=email;
	newCell->next=iterator->next;
	iterator->next=newCell;
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