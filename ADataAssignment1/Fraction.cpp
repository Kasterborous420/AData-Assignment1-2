#include "Fraction.h"
#include <stdexcept>
//Function Name: CFraction constructor
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Default Contructor
CFraction::CFraction()
{
	//Default Values
	this->numerator = 0;
	this->denominator = 0;
}

//Function Name: Overloaded Constructor
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Overloads the constructor
CFraction::CFraction(int numerator, int denominator)
{

	this->numerator = numerator;
	this->denominator = denominator;
}

//Function Name: xXx_D3STR0Y3R_xXx
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: xXx_D3STR0Y3R_xXx
CFraction::~CFraction()
{
}


//================Operator Overloads===============//

//Function Name: Overloaded + operator
//Author: Wayne 140189H
//returns CFraction
//params: CFraction otherFraction
//
//Function Purpose: to make operator + work with the CFraction Class
CFraction CFraction::operator+(CFraction other)
{
	CFraction output;
	
	int lcm, scale;
	
	int numer1, numer2;

	//Get LCM
	lcm = getLCM(other);

	//Convert Values to LCM scale
	scale = lcm / this->denominator;
	numer1 = this->numerator * scale;

	scale = lcm / other.denominator;
	numer2 = other.numerator * scale;
	
	//Assign output
	output.numerator = numer1 + numer2;
	output.denominator = lcm;

	//Simplify output
	output.simplifyResult();

	return output;
}

//Function Name: Overloaded - operator
//Author: Wayne 140189H
//returns CFraction
//params: CFraction otherFraction
//
//Function Purpose: to make operator - work with the CFraction Class
CFraction CFraction::operator-(CFraction other)
{
	CFraction output;

	int lcm, scale;

	int numer1, numer2;

	//Get LCM
	lcm = getLCM(other);

	//Convert Values to LCM scale
	scale = lcm / this->denominator;
	numer1 = this->numerator * scale;

	scale = lcm / other.denominator;
	numer2 = other.numerator * scale;

	//Assign output
	output.numerator = numer1 - numer2;
	output.denominator = lcm;

	//Simplify output
	output.simplifyResult();

	return output;
}

//Function Name: Overloaded * operator
//Author: Wayne 140189H
//returns CFraction
//params: CFraction otherFraction
//
//Function Purpose: to make operator * work with the CFraction Class
CFraction CFraction::operator*(CFraction other)
{
	CFraction output;

	output.numerator = this->numerator * other.numerator;
	output.denominator = this->denominator * other.denominator;

	return output;
}

//Function Name: Overloaded / operator
//Author: Wayne 140189H
//returns CFraction
//params: CFraction otherFraction
//
//Function Purpose: to make operator / work with the CFraction Class
CFraction CFraction::operator/(CFraction other)
{
	CFraction output;
	CFraction temp1, temp2;

	//Flip fraction around first, then multiply
	temp1.numerator = other.denominator;
	temp1.denominator = other.numerator;


	temp2.numerator = this->numerator;
	temp2.denominator = this->denominator;

	output.numerator = temp2.numerator * temp1.numerator;
	output.denominator = temp2.denominator * temp1.denominator;


	output.simplifyResult();

	return output;
}

//Function Name: Overloaded << operator
//Author: Wayne 140189H
//returns ostream
//params: CFraction otherFraction, CFraction &f
//
//Function Purpose: Use CFraction in the output stream
ostream & operator<< (ostream & os, CFraction &f)
{
	os << f.numerator << "/" << f.denominator;

	return os;
}

//Function Name: Overloaded >> operator
//Author: Wayne 140189H
//returns istream
//params: CFraction otherFraction, CFraction &f
//
//Function Purpose: Parse the Input Stream to CFraction
istream & operator>> (istream &is, CFraction &f)
{
	string input;

	string w, n, d;

	int wholenumber = 0;
	bool isFraction = false;


	is >> input;

	for (unsigned int i = 0; i < input.size(); i++)
	{
		if (input[i] == '-' || input[i] == '/')
		{
			isFraction = true;
		}
	}
	if (isFraction)
	{
		for (unsigned int i = 0; i < input.size(); i++)
		{
			//For Proper Fractions
			if (input[i] == '-')
			{
				w = input.substr(0, i);
				input = input.erase(0, i + 1);
				i = 0;
				if (!w.empty())
				{
					wholenumber = stoi(w, nullptr, 10);
				}
			}
			if (input[i] == '/')
			{
				n = input.substr(0, i);
				input = input.erase(0, i + 1);
				i = 0;
				if (!n.empty())
				{
					if (stoi(n, nullptr, 10) > INT_MAX || stoi(n, nullptr, 10) < INT_MIN)
					{
						cout << " Input out of Bounds" << endl;
						cout << endl;
						cout << " Please Re-Enter Numerator" << endl;
						cout << endl;
						std::cin >> f.numerator;
					}
					else
						f.numerator = stoi(n, nullptr, 10);
				}
				else
				{
					f.numerator = 0;
				}
				if (!input.empty())
				{
					if (stoi(input, nullptr, 10) > INT_MAX || stoi(input, nullptr, 10) < INT_MIN)
					{
						cout << " Input out of Bounds" << endl;
						cout << endl;
						cout << " Please Re-Enter Denominator" << endl;
						cout << endl;
						std::cin >> f.denominator;
					}
					else
						f.denominator = stoi(input, nullptr, 10);
				}
				else
				{
					f.denominator = 0;
				}
				

				//Check for '0' Denominator
				try
				{
					if (f.denominator == 0) throw 0;
				}
				catch (int x)
				{
					if (x == 0)
					{

						cout << "Denominator CANNOT be ZERO!" << endl;
						cout << "Input denominator: ";
						std::cin >> f.denominator;
					}
				}
				
				break;
			}
		}
		f.numerator += wholenumber * f.denominator;
	}
	else if (!isFraction)
	{
		try{

			wholenumber = stoi(input, nullptr, 10);
		}
		catch (std::invalid_argument &ia)
		{
			cout << endl;
			cout << " Invalid argument: " << ia.what() << endl;
			cout << endl;
			cout << " Application will close due to user disobedience" << endl;
			cout << endl;
			system("pause");
			exit(0);
		}
		catch (std::out_of_range &oor)
		{
			cout << endl;
			cout << " " << oor.what() << endl;
			cout << endl;
			cout << " Application will close due to user disobedience" << endl;
			cout << endl;
			system("pause");
			exit(0);
		}
		f.denominator = 1;
		f.numerator = wholenumber;
	}
	return is;
}


//================Functions==============//

//Function Name: simplifyResult
//Author: Wayne 140189H
//returns void
//params: 
//
//Function Purpose: Simplifies Fraction
void CFraction::simplifyResult()
{
	int hcf = getHCF(*this);

	if (this->numerator != 0 && hcf != 0)
	{
		this->numerator /= hcf;
	}
	if (this->denominator != 0 && hcf != 0)
	{
		this->denominator /= hcf;
	}
}

//Function Name: compare
//Author: Wayne 140189H
//returns void
//params: CFraction otherFraction
//
//Function Purpose: Compares this and otherFraction and outputs which Fraction is bigger than the other one
void CFraction::compare(CFraction other)
{
	float c1, c2;

	c1 = ((float)this->numerator / (float)this->denominator);
	c2 = ((float)other.numerator / (float)other.denominator);

	if (c1 > c2)
	{
		cout << *this << " is greater than " << other << endl;
	}
	else if (c1 < c2)
	{
		cout << *this << " is lesser than " << other << endl;
	}
	else
	{
		cout << "The Fractions: " << *this << " and " << other << " are Equal" << endl;
	}
}

//Function Name: getLCM
//Author: Wayne 140189H
//returns int
//params: CFraction otherFraction
//
//Function Purpose: gets the LCM from this and otherFraction
int CFraction::getLCM(CFraction other)
{
	int lcm = 0;

	lcm = (this->denominator > other.denominator) ? this->denominator : other.denominator;

	//find LCM
	while (true)
	{
		if (lcm % this->denominator == 0 && lcm % other.denominator == 0)
		{
			break;
		}
		else
		{
			++lcm;
		}
	}

	return lcm;
}

//Function Name: getHCF
//Author: Wayne 140189H
//returns int
//params: CFraction otherFraction
//
//Function Purpose: gets HCf between this and otherFraction
int CFraction::getHCF(CFraction fraction)
{
	int hcf = 0;

	int n1 = fraction.numerator;
	int n2 = fraction.denominator;
	
	if (n2 > n1)
	{
		int temp = n2;
		n2 = n1;
		n1 = temp;
	}

	for (int i = 1; i <= n2; ++ i)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			hcf = i;
		}
	}

	return hcf;
}

//Function Name: Display
//Author: Wayne 140189H
//returns void
//params: bool isProper
//
//Function Purpose: Displays Fractions in Proper or Improper mode
//Fun fact: This Function exists purely because overloading << cannot take in a boolean
void CFraction::Display(bool isProper)
{
	int whole, num, denom;

	whole = (this->numerator / this->denominator);
	num = (this->numerator % this->denominator);
	denom = (this->denominator);
	
	if (isProper)
	{

		if (this->numerator == 0)
		{
			cout << "0 (Proper)" << endl;
		}
		else if (this->numerator % this->denominator == 0)
		{
			cout << whole << " (Proper)" << endl;
		}
		else
		{
			cout << whole << "-" << num << "/" << denom << " " << "(Proper)" << endl;
		}
	}
	else
	{
		num = (this->numerator);
		denom = (this->denominator);

		if (this->numerator == 0)
		{
			cout << "0 (Improper)" << endl;
		}
		else if (this->numerator % this->denominator == 0)
		{
			cout << whole << " (Improper)" << endl;
		}
		else
		{
			cout << num << "/" << denom << " " << "(Improper)" << endl;
		}
	}
}