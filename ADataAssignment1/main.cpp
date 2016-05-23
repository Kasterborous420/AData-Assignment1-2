#include "Fraction.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isProper = true;	//default value

CFraction f1, f2, f3;

void main()
{
	string userInput;

	RenderMenu();

	system("pause");
}

void InputFractions()
{
	cout << " Please Input Fraction 1 in this format: 1-2/3" << endl;
	cin >> f1;

	cout << " Please Input Fraction 2 in the same format" << endl;
	cin >> f2;
}

void RenderMenu()
{
	//Handle Menu System here
	cout << "===============================================" << endl;
	cout << "      Welcome to The Fraction Calculator!      " << endl;
	cout << "===============================================" << endl;

	cout << "What would you like to do?" << endl;
	cout << "<1> Addition" << endl;
	cout << "<2> Subtraction" << endl;
	cout << "<3> Multiplication" << endl;
	cout << "<4> Division" << endl;
	cout << "<5> Simplification" << endl;
	cout << "<6> Comparison" << endl;
	cout << "<7> Toggle Fraction Mode (Proper/Improper)" << endl;
}

void Addition()
{
	cout << " <[ADDITION]> " << endl;

	InputFractions();

	f3 = f1 + f2;

	f3.Display(isProper);
	
}

void Subtraction()
{
	cout << " <[SUBTRACTION]> " << endl;

	InputFractions();

	f3 = f1 - f2;

	f3.Display(isProper);
}

void Multiply()
{
	cout << " <[MULTIPLICATION]> " << endl;

	InputFractions();

	f3 = f1 * f2;

	f3.Display(isProper);
}

void Divide()
{
	cout << " <[TOM CLANCY'S THE DIVISION]> " << endl;

	InputFractions();

	f3 = f1 / f2;

	f3.Display(isProper);
}

void Simplify()
{

}

void Compare()
{

}

void Toggle()
{
	if (isProper)
	{
		isProper = false;
	}
	else
	{
		isProper = true;
	}
}

void HandleUserInput(int choice)
{

}


