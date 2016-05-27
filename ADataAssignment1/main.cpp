#include "Fraction.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isProper = true;	//default value
bool isActive = true;
CFraction f1, f2, f3;

//Function Name: FlushBuffer
//Author: Wayne 140189H
//returns void
//params:
//
//Function Purpose: UFlush the cin buffer completely
void FlushBuffer()
{
	cin.clear();
	fflush(stdin);
}
//Function Name: Input Fractions
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Handles the Input of Fractions
void InputFractions()
{
	cout << " Please Input Fraction 1 in this format: 1-2/3" << endl;
	cin >> f1;

	cout << " Please Input Fraction 2 in the same format" << endl;
	cin >> f2;
}

//Function Name: Render Menu
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Renders the Text Menu
void RenderMenu()
{
	//Handle Menu System here
	cout << "===============================================" << endl;
	cout << "      Welcome to The Fraction Calculator!      " << endl;
	cout << "===============================================" << endl;

	cout << "What would you like to do?" << endl;
	if (isProper)
	{
		cout << endl;
		cout << "CURRENT MODE IS: PROPER FRACTIONS (1-2/3)" << endl;
		cout << endl;
	}
	else if (!isProper)
	{
		cout << endl;
		cout << "CURRENT MODE IS: IMPROPER FRACTIONS (5/3)" << endl;
		cout << endl;
	}
	cout << "<1> Addition" << endl;
	cout << "<2> Subtraction" << endl;
	cout << "<3> Multiplication" << endl;
	cout << "<4> Division" << endl;
	cout << "<5> Simplification" << endl;
	cout << "<6> Comparison" << endl;
	cout << "<7> Toggle Fraction Mode (Proper/Improper)" << endl;
	cout << "<8> Exit Application" << endl;
}

//Function Name: Addition
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Addition
void Addition()
{
	cout << " <[ADDITION]> " << endl;
	cout << endl;
	InputFractions();

	f3 = f1 + f2;

	f3.Display(isProper);
	system("pause");
	
}

//Function Name: Subtraction
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Subtraction
void Subtraction()
{
	cout << " <[SUBTRACTION]> " << endl;
	cout << endl;
	InputFractions();

	f3 = f1 - f2;

	f3.Display(isProper);
	system("pause");
}

//Function Name: Multiply
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Multiply
void Multiply()
{
	cout << " <[MULTIPLICATION]> " << endl;
	cout << endl;
	InputFractions();

	f3 = f1 * f2;

	f3.Display(isProper);
	system("pause");
}

//Function Name: Division
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Division
void Divide()
{
	cout << " <[TOM CLANCY'S THE DIVISION]> " << endl;
	cout << endl;
	InputFractions();

	f3 = f1 / f2;

	f3.Display(isProper);
	system("pause");
}

//Function Name: Simplify
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Simplifies Fraction
void Simplify()
{
	cout << " <[SIMPLIFY]> " << endl;
	cout << endl;
	cout << " Please Input Fraction in this format: 1-2/3" << endl;
	cin >> f1;

	f1.simplifyResult();

	f1.Display(isProper);

	system("pause");
}

//Function Name: Compare
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Compares Fractions
void Compare()
{
	cout << " <[COMPARISON]> " << endl;
	cout << endl;
	InputFractions();

	f1.compare(f2);

	system("pause");
}

//Function Name: Toggle
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Changes the Boolean (isProper)
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

//Function Name: Exit
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Exits Application
void Exit()
{
	isActive = false;
}

//Function Name: Handle User Input
//Author: Wayne 140189H
//returns void
//params: int choice (User Input Choice)
//
//Function Purpose: takes in user input and error check it
void HandleUserInput(int choice)
{
	if (choice <= 0 || choice > 8)
	{
		cout << "Invalid Input, PLEASE INPUT A NUMBER BETWEEN 1 AND 7" << endl;
		
		//Clearing the cin buffer to prevent indefinite input
		FlushBuffer();
		cin >> choice;

		//Recursive
		HandleUserInput(choice);
	}
	else if (choice > 0 && choice < 9)
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

//Function Name: main
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Main Program
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
