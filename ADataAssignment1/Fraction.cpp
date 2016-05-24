#include "Fraction.h"


CFraction::CFraction()
{
	//Default Values
	this->numerator = 0;
	this->denominator = 0;
}

CFraction::CFraction(int numerator, int denominator)
{

	this->numerator = numerator;
	this->denominator = denominator;
}

CFraction::~CFraction()
{
}


//================Operator Overloads===============//

//Addition 
//returns CFraction
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
	output = simplifyResult(output);

	return output;
}

//Subtraction
//returns CFraction
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
	output = simplifyResult(output);

	return output;
}

//Multiplication
//returns CFraction
CFraction CFraction::operator*(CFraction other)
{
	CFraction output;

	output.numerator = this->numerator * other.numerator;
	output.denominator = this->denominator * other.denominator;

	return output;
}

//Division
//returns CFraction
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


	output = simplifyResult(output);

	return output;
}

ostream & operator<< (ostream & os, CFraction &f)
{
	os << f.numerator << "/" << f.denominator;

	return os;
}

istream & operator>> (istream &is, CFraction &f)
{
	string input;

	string w, n, d;

	int wholenumber = 0;
	bool isFraction = false;

	/*std::getline(is, input, '-');

	wholenumber = stoi(input, nullptr, 10);

	std::getline(is, input, '/');

	f.numerator = stoi(input, nullptr, 10);

	std::getline(is, input);

	f.denominator = stoi(input, nullptr, 10);*/


	is >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '-' || input[i] == '/')
		{
			isFraction = true;
		}
	}
	if (isFraction)
	{
		for (int i = 0; i < input.size(); i++)
		{
			//For Proper Fractions
			if (input[i] == '-')
			{
				w = input.substr(0, i);
				input = input.erase(0, i + 1);
				i = 0;
				wholenumber = stoi(w, nullptr, 10);
			}
			if (input[i] == '/')
			{
				n = input.substr(0, i);
				input = input.erase(0, i + 1);
				i = 0;
				f.numerator = stoi(n, nullptr, 10);

				f.denominator = stoi(input, nullptr, 10);
				
				break;
			}
		}
		f.numerator += wholenumber * f.denominator;
	}
	else if (!isFraction)
	{
		wholenumber = stoi(input, nullptr, 10);
		f.denominator = 1;
		f.numerator = wholenumber;
	}
	return is;
}


//================Functions==============//

////Converting to Improper Fraction
//CFraction CFraction::convertToImproper(CFraction other)
//{
//	CFraction output;
//	
//	output.wholenumber = 0;
//	output.numerator = (other.wholenumber * other.denominator) + other.numerator;
//	output.denominator = other.denominator;
//
//	return output;
//}
//
////Converting to Proper Fraction
//CFraction CFraction::convertToProper(CFraction other)
//{
//	CFraction output;
//
//	int i = 0;
//	
//	i = other.numerator / other.denominator;
//
//	output.wholenumber = other.denominator * i;
//
//	output.numerator = other.numerator - output.wholenumber;
//
//	output.denominator = other.denominator;
//
//	return output;
//}

//Simplification
CFraction CFraction::simplifyResult(CFraction other)
{
	int hcf = getHCF(other);

	if (other.numerator != 0 && hcf != 0)
	{
		other.numerator /= hcf;
	}
	if (other.denominator != 0 && hcf != 0)
	{
		other.denominator /= hcf;
	}
	return other;
}

//Comparison
void CFraction::compare(CFraction f1, CFraction f2)
{
	float c1, c2;

	c1 = (f1.numerator / f1.denominator);
	c2 = (f2.numerator / f2.denominator);

	if (c1 > c2)
	{
		cout << f1 << " is greater than " << f2 << endl;
	}
	else if (c1 < c2)
	{
		cout << f1 << " is lesser than " << f2 << endl;
	}
	else
	{
		cout << "The Fractions: " << f1 << " and " << f2 << " are Equal" << endl;
	}
}

//Get LCM
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

//Get HCF
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
			cout << "0 (Proper)" << endl;
		}
		else if (this->numerator % this->denominator)
		{
			cout << whole << " (Proper)" << endl;
		}
		else
		{
			cout << num << "/" << denom << " " << "(Improper)" << endl;
		}
	}
}