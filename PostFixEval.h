#pragma once
#ifndef PostFixEval_H
#define PostFixEval_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "Stack.h"
#include "ReversePolishNotation.h"
#include "TokenizerParser.h"
using namespace std;

/***********************************************************
Name: Timothy Park
Email: timothy_park@elcamino.edu
Assignment #4
Operating System: Windows 7
Complier Used: Visual Studio 2012/13
Date Ran Successfully Last Time: 10/27/14
***********************************************************/

class PostFixEval
{
protected:	
	string Expression;
	bool numeric;
	double value;
	double evaluate();
	bool isNumeric();
public:
	PostFixEval(string Exp = "", bool numeric1 = false);
	void findValue();
	void print (ostream & out) const;
};

#endif