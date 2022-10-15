#include "email.hpp"

struct Cell{
	Email* key;
	Cell* next;
};

//a classe inbox sera implementada como uma fila (FIFO)
class Inbox{
	public:
		//Cria uma instancia nova de caixa de entrada
		//Seta o tamanho como 0 e os atributos como nullptr
		//Seta a ultima celula como igual a primeira
		Inbox();

		//retorna se a fila esta vazia (true) ou nao (false)
		bool empty();

		//limpa a fila inteira, deletando todas as instancias de celulas (emails)
		void clean();

		//adiciona um email novo a fila, na ultima posicao
		void add(Email* email, int pri);

		//retorna o email da primeira posicao e o retira da fila
		//o topo da fila agora eh o proximo email a ser lido e o email eh deletado.
		Email* read();

		int getSize() const;

		//desaloca a memoria da caixa de entrada, apagando todos os seus emails
		virtual ~Inbox();

	private:
		Cell* first;
		Cell* last;
		int size;
};