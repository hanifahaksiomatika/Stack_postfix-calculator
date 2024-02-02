#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool Operator(const string & input);
void performOp(const string & input, stack<double> & calcStack);

int main()
{
	cout << "Welcome to the Postfix Calculator\n" << endl;
	
	stack<double>calcStack;
	string input;
	
	while (true)
	{
		cout<<"";
		cin>>input;
		
		double num;
		if(stringstream(input) >> num)
		{
			calcStack.push(num);
		}
		else if(Operator(input))
		{
			performOp(input, calcStack);
		}
		else if(input == "q", "Q")
		{
			return 0;
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}
}

bool Operator(const string & input)
{
	string op[] = {"-", "+", "*", "/"};
	
	for(int i = 0; i < 10; ++i)
	{
		if(input == op[i])
		{
			return true;
		}
	}
	return false;
}

void performOp(const string & input, stack<double> & calcStack)
{
	double A, B, result;
	
	B = calcStack.top();
	calcStack.pop();
	
	A = calcStack.top();
	calcStack.pop();
	
	if(input == "-")
	{
		result = A - B;
	}
	else if(input == "+")
	{
		result = A + B;
	}
	else if(input == "*")
	{
		result = A * B;
	}
	else
	{
		result = A / B;
	}
	cout << result << endl;
	calcStack.push(result);
}

