#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "inbox.hpp";

class Usuario{
	public:
		Usuario(int identificador){
			id=identificador;
			inbox=new Inbox;
		}
	private:
		int id;
		Inbox* inbox;
};

#endif