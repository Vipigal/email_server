#include <email.hpp>

struct Cell{
	Email key;
	Cell* next;
};

//a classe inbox sera implementada como uma fila (FIFO)
class Inbox{
	public:
		Inbox(){
			size=0;
			first=new Cell;
			last=first;
		}


	private:
		Cell* first;
		Cell* last;
		int size;
};