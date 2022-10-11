#ifndef USER_H
#define USER_H

#include <string>
#include "inbox.hpp"

class User{
	public:
		User(int identificador){
			id=identificador;
			inbox=new Inbox;
		}

	private:
		int id;
		Inbox* inbox;
};

#endif