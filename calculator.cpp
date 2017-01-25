#include <iostream>
#include <string>
#include <math.h>
using namespace std;

double doOperation(char operation, double firstArg, double secondArg);
bool divByZero(char op, double secondArg);
bool invalidOperator(char op);

int main()	{
	char check = 'y';
	char error = 'n';
	double firstArg;
	double secondArg;
	double answer;
	char operation;
	cout << "Welcome to the calculator! Available operations: + - * / ^ %" << endl;
	while((check == 'y') || (check == 'Y'))	{
		cout << "Enter an equation, separating elements with a space: ";
			cin >> firstArg >> operation >> secondArg;
			if (!cin.fail() && !invalidOperator(operation))	{
				if (divByZero(operation, secondArg))	{
					cout << "Error! Dividing by Zero!" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else    {
					answer = doOperation(operation, firstArg, secondArg);
					cout << firstArg << " " << operation << " " << secondArg << " = " << answer << endl;
					cin.clear();
					cin.ignore(1000, '\n');
				}	
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Invalid input!" << endl;
			}
		cout << "Would you like to perform another operation? (y/n):";
		check = cin.get();
	}
	cout << "Exiting..." << endl;
	return 0;
}
double doOperation(char operation, double firstArg, double secondArg){
	double answer;
	switch(operation)	{
			case '+':
				answer = firstArg + secondArg;
				break;
			case '-':
				answer = firstArg - secondArg;
				break;
			case '*':
				answer = firstArg * secondArg;
				break;
			case '/':
				answer = firstArg / secondArg;
				break;
			case '^':
				answer = pow(firstArg, secondArg);
				break;
			case '%':
				answer = fmod(firstArg, secondArg);
				break;
			default:
				cout << "Invalid operator!" << endl;
		}
		return answer;
}
bool divByZero(char op, double secondArg){
	if((op == '/' || op == '%') && secondArg == 0)
		return true;
	else
		return false;
}
bool invalidOperator(char op)	{
	if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%') //this would be less bulky with a list
		return false;
	else
		return true;
}
