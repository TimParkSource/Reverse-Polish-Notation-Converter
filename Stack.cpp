#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
	top_position = -1;
}
//-------------------------------
Stack::~Stack()
{

}
//-----------------------------------
bool Stack::isEmpty() const
{
	return (top_position == -1);
}
//------------------------------------
bool Stack::isFull() const
{
	return (top_position == MAX-1);
}
//-----------------------------------
ItemType Stack::top() const
{
	if(isEmpty())
	{
		cerr<<"The stack is empty. Returned value not reliable.\n";
		ItemType data = ItemType();
		return data;
	}
	else
		return items[top_position];
}
//------------------------------------
void Stack::pop()
{
	if(isEmpty())
	{
		cerr<<"The stack is empty.\n";
		return;
	}
	else
		top_position--;
}
//------------------------------------------
void Stack::push(ItemType newItem)
{
	if(isFull())
	{
		cerr<<"The stack is full. The item is not added.\n";
		return;
	}
	else
	{
		top_position++;
		items[top_position] = newItem;
	}
}
//-------------------------------------------------

