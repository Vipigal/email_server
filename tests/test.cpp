#include "inbox.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Inbox* teste= new Inbox();
	Email* novo= new Email("teste1");
	teste->add(novo,1);
	Email* received=teste->read();
	cout<<received->getMessage()<<endl;


	return 0;
}
