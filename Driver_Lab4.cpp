#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "PostFixEval.h"
//#include "Stack.h"
//#include "ReversePolishNotation.h"
//#include "TokenizerParser.h"

/***********************************************************
Name: Timothy Park
Email: timothy_park@elcamino.edu
Assignment #4
Operating System: Windows 7
Complier Used: Visual Studio 2012/13
Date Ran Successfully Last Time: 10/27/14
***********************************************************/

int maintest();
int main()
{
	maintest();

	bool done = false;
	PostFixEval P;
	string original;

	cout<< "Please type the name of the file to which results are to be written to: ";
	string OutputFileName;
	cin.sync();
	getline(cin, OutputFileName);
	ofstream out;
	out.open(OutputFileName);
	
	if (!out)
	{
		cout<<"Failed to create output file.\n";
	}

	while (!done)
	{
		cout << "Please enter the infix expression, which must be parenthetically balanced and\n"
			<< "must be enclosed in square brackets.The parsing algorithm only works if more\n"
			<< "than one space is left between the characters in the inputted expression.\n"
			<< "The evaluated value for a numeric expression will only be a floating point value." << endl;
		getline(cin, original);


		cout << "Press 2 to print the results to both screen and data file:\n"
			<< "Press 3 to print the results to data file only:\n"
			<< "Press 4 to print the results to screen only:\n";
		int choice;
		cin >> choice;
		P = PostFixEval(original, false);
		P.findValue();

		if (choice == 2){
			P.print(out);
			P.print(cout);
			cout<<"More data? Enter 0 to continue and 1 to exit: ";
			cin >> done;
		}
		else if (choice == 3){
			P.print(out);
			cout << "More data? Enter 0 to continue and 1 to exit: ";
			cin >> done;
		}
		else if (choice == 4){
			P.print(cout);
			cout << "More data? Enter 0 to continue and 1 to exit: ";
			cin >> done;
		}
		else
		{
			cout << "The menu choice " << choice << " is not yet implemented.\n";
		}
		cin.ignore();
	}

	out.close();
	system("pause");
	return 0;
}

int maintest()
{
	PostFixEval P;
	P = PostFixEval("[ ( 3 + 4 ) / ( 9 - 10 ) ] ", false);
	P.findValue();
	P.print(cout);

	PostFixEval P1;
	P1 = PostFixEval("[ ( 4 + a ) / ( 9 - 10 ) ] ", false);
	P1.findValue();
	P1.print(cout);

	return 0;
}


