#include "PostFixEval.h"

/***********************************************************
Name: Timothy Park
Email: timothy_park@elcamino.edu
Assignment #4
Operating System: Windows 7
Complier Used: Visual Studio 2012/13
Date Ran Successfully Last Time: 10/27/14
***********************************************************/

PostFixEval::PostFixEval(string Exp, bool numeric1) 
{
	Expression = Exp;
	numeric = isNumeric();
}
double PostFixEval::evaluate() 
{
	string Str_Arr[MAX];
	Stack calcstack;
	int count = 0;
	TokenizerParser::getStringArray(Str_Arr,Expression,MAX,count);
	ItemType Before, Current, After;
	for(int index=0; index < count; index++)
	{
		if(Str_Arr[index] == "*")
		{
			Current = calcstack.top();
			calcstack.pop();
			Before = calcstack.top();
			calcstack.pop();
			After.Double = Before.Double * Current.Double; 
			calcstack.push(After);
		}
		else if(Str_Arr[index] == "+")
		{
			Current = calcstack.top();
			calcstack.pop();
			Before = calcstack.top();
			calcstack.pop();
			After.Double = Before.Double + Current.Double; 
			calcstack.push(After);
		}
		else if(Str_Arr[index] == "-")
		{
			Current = calcstack.top();
			calcstack.pop();
			Before = calcstack.top();
			calcstack.pop();
			After.Double = Before.Double - Current.Double; 
			calcstack.push(After);
		}
		else if(Str_Arr[index] == "/")
		{
			Current = calcstack.top();
			calcstack.pop();
			Before = calcstack.top();
			calcstack.pop();
			After.Double = Before.Double / Current.Double;  // i believe this is the right order
			calcstack.push(After);
		}
		else if(Str_Arr[index] == "^")
		{
			Current = calcstack.top();
			calcstack.pop();
			Before = calcstack.top();
			calcstack.pop();
			After.Double = pow(Before.Double, Current.Double);  // should work
			calcstack.push(After);
		}
		else
		{
			Current.Double = TokenizerParser::parseDouble(Str_Arr[index]);
			calcstack.push(Current);
		}
	}
	return After.Double;
	

}
void PostFixEval::findValue( )
{
	if(numeric)
	{
		value = evaluate();
	}
}
bool PostFixEval::isNumeric()
{
	ReversePolishNotation R;
	R = ReversePolishNotation(Expression,"");
	R.convert();
	Expression = R.getOutput();
	for(int i = 0; i< Expression.length(); i++)
	{
		if(isalpha(Expression[i]))
		{
			return false;     // loop stops if it ever hits a alpha
		}
	}
	return true;  // loop ends and returns true if no alpha is found
}
void PostFixEval::print(ostream & out) const
{
	out << fixed << showpoint << setprecision(2);
	out << "The postfix form of is: " << Expression << endl;
	if(!numeric)
	{
		out << "The infix expression you entered isn't pure numeric expression.\nNo computation of its value can be done." << endl;
	}
	else
	{
		out << "Computed value of this postfix expression is: " << value << endl;
	}
}
