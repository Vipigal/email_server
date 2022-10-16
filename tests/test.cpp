#include "inbox.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Inbox* teste= new Inbox();
	Email* pri0= new Email("pri 0");
	Email* pri2 = new Email("pri 2");
	Email* pri= new Email("primeiro");
	Email* sec=new Email("segundo");
	// teste->add(pri2,2);
	// teste->add(pri0,0);
	teste->add(pri,9);
	teste->add(sec,9);
	try{
		for(int i=0;i<2;i++){
			//cout<<teste->getSize()<<endl;
			Email* received=teste->read();
			cout<<received->getMessage()<<endl;

		}
	}catch(const char* error){
		cout<<error<<endl;
	}


	return 0;
}
