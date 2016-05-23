#pragma once
#include <ostream>
#include <istream>
#include <iostream>
#include <string>
#include <sstream>


using std::istream;
using std::ostream;

using std::cout; 
using std::endl;

using std::string;

using std::stoi;

class CFraction
{
private:
	//==================================================//
	// By default, store data as improper fraction      //
	// When Displaying fraction, check for display mode //
	//==================================================//
	int numerator, denominator;

public:
	CFraction();
	~CFraction();
	CFraction(int numerator, int denominator);


	CFraction operator+ (CFraction other);				//Addition
	CFraction operator- (CFraction other);				//Subtraction
	CFraction operator* (CFraction other);				//Multiplication
	CFraction operator/ (CFraction other);				//Division ( not the Ubisoft one )
	friend ostream & operator<< (ostream& os, CFraction &other);
	friend istream & operator>> (istream& is, CFraction &other);

	//CFraction convertToImproper(CFraction fraction);	//convert from Improper to Proper fraction
	//CFraction convertToProper(CFraction fraction);		//convert from Proper to Improper fraction

	CFraction simplifyResult(CFraction fraction);		//Simplify Answer

	void compare(CFraction f1, CFraction f2);			//Compare 2 fractions

	int getLCM(CFraction other);						//Get Lowest Common Multiple
	int getHCF(CFraction fraction);						//Get Highest Common Factor

	void Display(bool isProper);

};

