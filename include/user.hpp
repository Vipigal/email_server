#ifndef USER_H
#define USER_H

#include <string>
#include "inbox.hpp"

class User{
	public:
		User(int identificador);

		void addEmail(Email* email);

		int getId() const;

		void readEmail();

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
	public:
		UserList();

		bool empty();
		//Insere sempre no final
		void insert(User* user);

		void remove(int id);

		void printEmail(int id);

		void addEmail(int id, Email* email);


	private:
		No* first;
		No* last;
		int size;
		
};


#endif