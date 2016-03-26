#include "ReversePolishNotation.h"
#include "Stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//-----------------------------------------
ReversePolishNotation::ReversePolishNotation(
	const string input, const string output):
inputString(input), outputString(output)
{

}
//----------------------------------------
ReversePolishNotation::~ReversePolishNotation()
{

}
//---------------------------------------------
const string ReversePolishNotation::getInput() const
{
	return inputString;
}
//------------------------------------------------
void ReversePolishNotation::setInput(const string input)
{
	inputString = input;
}
//-------------------------------------------------
const string ReversePolishNotation::getOutput() const
{
	return outputString;
}
//---------------------------------------------------
void ReversePolishNotation::setOutput(const string output)
{
	outputString = output;
}
//----------------------------------------------------
int ReversePolishNotation::priority(char s)
{
	
	  int operatorPriority = -1;

	  if (s=='[')
		 operatorPriority = 0;
	  else if (s=='(')
		 operatorPriority = 1;
	  else if (s=='+')
		 operatorPriority = 2;
	  else if (s=='-')
		 operatorPriority = 2;
	  else if (s=='*')
		 operatorPriority = 3;
	  else if (s=='/')
		 operatorPriority = 3;
	  else if (s=='^')
		 operatorPriority = 4;

	  return(operatorPriority);
}
//---------------------------------------
void ReversePolishNotation::convert()
{
	Stack myStack;
	char nextCharacter =' ';
	char topOfStack=' ';
	
	  for (int i = 0;i<inputString.length();i++) 
	  {
		 nextCharacter = inputString[i];
		 if (nextCharacter==')') 
		 {
			topOfStack = (myStack.top()).Character;
			myStack.pop();
			while (!(topOfStack=='(')) 
			{
				outputString+=" ";
			   outputString += topOfStack;
			   topOfStack = (myStack.top()).Character;
			   myStack.pop();
			}
		 } 
		 else if (nextCharacter==']') 
		 {
			topOfStack = (myStack.top()).Character;
			myStack.pop();
			while (!(topOfStack=='[')) 
			{
			   outputString+=" ";
			   outputString += topOfStack;
			   topOfStack = (myStack.top()).Character;
			   myStack.pop();
			}
		 } 
		 else if (nextCharacter=='(' || nextCharacter=='[') 
		 {
			 ItemType data;
			 data.Character = nextCharacter;
			myStack.push(data);
		 } 
		 else if (nextCharacter=='+' || nextCharacter=='-' ||
					nextCharacter=='*' || nextCharacter=='/' ||
					nextCharacter=='^') 
		 {
			topOfStack = (myStack.top()).Character;
			while (priority(nextCharacter) <= priority(topOfStack)) 
			{
			   topOfStack = (myStack.top()).Character;
			   myStack.pop();
			   outputString+=" ";
			   outputString += topOfStack;
			   topOfStack = (myStack.top()).Character;
			}
			ItemType data;
			data.Character = nextCharacter;
			myStack.push(data);
		 } 
		 else //This executes only when an alphanumeric character is encountered
		 {
			if (!isdigit(int(nextCharacter)))
			{
				outputString=outputString + " ";
				outputString += nextCharacter;
				outputString=outputString + " ";
			}
			else
				outputString += nextCharacter;

		 }             
	  }
   }
