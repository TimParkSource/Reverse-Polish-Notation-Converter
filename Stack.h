#include "StackInterface.h"

const int MAX = 100;

class Stack :public StackInterface
{
private:
int top_position;
ItemType items[MAX];
public:
	void push (ItemType item);
	void pop( );
	ItemType top( ) const;
	bool isEmpty() const;
	bool isFull() const;
	Stack();
	~Stack();
};