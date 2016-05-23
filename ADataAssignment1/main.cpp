#include "Fraction.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isProper = true;	//default value
bool isActive = true;
CFraction f1, f2, f3;

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
	cout << "<8> Exit Application" << endl;
}

void Addition()
{
	cout << " <[ADDITION]> " << endl;

	InputFractions();

	f3 = f1 + f2;

	f3.Display(isProper);
	system("pause");
	
}

void Subtraction()
{
	cout << " <[SUBTRACTION]> " << endl;

	InputFractions();

	f3 = f1 - f2;

	f3.Display(isProper);
	system("pause");
}

void Multiply()
{
	cout << " <[MULTIPLICATION]> " << endl;

	InputFractions();

	f3 = f1 * f2;

	f3.Display(isProper);
	system("pause");
}

void Divide()
{
	cout << " <[TOM CLANCY'S THE DIVISION]> " << endl;

	InputFractions();

	f3 = f1 / f2;

	f3.Display(isProper);
	system("pause");
}

void Simplify()
{


	system("pause");
}

void Compare()
{


	system("pause");
}

void Toggle()
{
	if (isProper)
	{
		isProper = false;
		cout << "Improper Mode" << endl;
	}
	else
	{
		isProper = true;
		cout << "Proper Mode" << endl;
	}

	system("pause");
}

void Exit()
{
	isActive = false;
}

void HandleUserInput(int choice)
{
	if (choice <= 0 || choice > 8)
	{
		cout << "Invalid Input, PLEASE INPUT A NUMBER BETWEEN 1 AND 7" << endl;
		cin >> choice;
		HandleUserInput(choice);
	}
	else
	{
		switch (choice)
		{

			case 1:
			{
					  Addition();
					  break;
			}
			case 2:
			{
					  Subtraction();
					  break;
			}
			case 3:
			{
					  Multiply();
					  break;
			}
			case 4:
			{
					  Divide();
					  break;
			}
			case 5:
			{
					  Simplify();
					  break;
			}
			case 6:
			{
					  Compare();
					  break;
			}
			case 7:
			{
					  Toggle();
					  break;
			}
			case 8:
			{
					  Exit();
					  break;
			}
		}

	}
}


void main()
{
	string userInput;
	int choice = 0;

	while (isActive)
	{
		system("cls");

		RenderMenu();

		cin >> choice;

		HandleUserInput(choice);
	}
}

