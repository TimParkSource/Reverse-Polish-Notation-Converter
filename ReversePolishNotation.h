#include <string> 
using namespace std;

/**
*Class <code>ReversePolishNotation</code> accepts a user inputted
*infix expression which must be parenthetically balanced and outputs 
*its postfix form. Postfix form is easier to evaluate as it needs no
*parenthesis.
*/
class ReversePolishNotation
{
private:
	/**
	*The field inputString will be the user inputted string for the 
	*infix expression.
	*/
	string inputString;
	/**
	*The field outputString will be the form converted to postfix
	*outputted for the user.
	*/
	string outputString;
	/**
	*The function priority takes an operator character as an input and 
	*returns the integer indicating the priority for that operator. C++
	*operator priority chart is followed in the function design.
	*@param character s is the operator in the infix expression.
	*@return the priority number for the operator based on C++ operator 
	*precedence.
	*/
	int priority(char s);
public:
	/**
	*The default and explicit constructor.
	*@param input has the default value of null string, and explicit value of 
	*user inputted infix expression.
	*@param output has a default value of null string or any user inputted value.
	*/
	ReversePolishNotation(const string input="",
		const string output="");
	/**
	*Default destructor.
	*/
	~ReversePolishNotation();
	/**
	*Accessor function to get the inputted string. 
	*@returns the inputString member of class <code>ReversePolishNotation</code>
	*/
	const string getInput() const;
	/**
	*Sets the data member inputString to the value passed to the function.
	*@param input is the new value of the data member inputString.
	*/
	void setInput(const string input);
	/**
	*Accessor function to get the output. 
	*@returns the outputString member of class <code>ReversePolishNotation</code>
	*/
	const string getOutput() const;
	/**
	*Sets the data member outputString to the value passed to the function.
	*@param input is the new value of the data member outputString.
	*/
	void setOutput(const string output);
	/**
	*The function convert takes the inputtted infix expression as a STL
	*string and generates its postfix form and stores the result in the
	*data member outputString.
	*/
	void convert();
};
