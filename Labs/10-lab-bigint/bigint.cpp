#include "bigint.h"
#include <iostream>

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

// Constructor
BigInt::BigInt(string s) {
	for (int i = (s.length() - 1); i >= 0 ; i--)
		digits.push_back((int)(s[i] - 48));
	base = 10;
}

BigInt::BigInt(string s, int Base) {
	base = Base;
	for (int i = (s.length() - 1); i >= 0 ; i--)
	{
		// check if the character is a number (in ASCII)
		if( ((int)(s[i]) >= 48) && ((int)(s[i]) <= 57) )
			digits.push_back((int)(s[i] - 48));
		else
			// convert to the decimal representation of the letter (A = 10, etc)
			// ASCII A = 65. 65 - 55 = 10
			digits.push_back((int)(s[i] - 55));
	}
}

// get string representation
string BigInt::to_string() {
	string stringDigits;
	for (int i = (digits.size() - 1); i >= 0; i--)
	if( ((int)(digits[i]) >= 0) && ((int)(digits[i]) <= 9) )
		stringDigits.push_back((char)digits[i] + '0');
	else
		stringDigits.push_back((char)digits[i] + '7');
	return stringDigits;
}

// add another BigInt to this one
// if the function is not of type BigInt you get a private error
void BigInt::add(BigInt b) {
	int carry = 0;
	int digitAdd = 0;

	if (base != b.base)
	{
		std::cerr << "You cannot add numbers with different bases Bob!!!" << std::endl;
	}
		

	if(digits.size() < b.digits.size())
  {
    while(digits.size() < b.digits.size())
      digits.push_back(0);
  }
  else if(digits.size() > b.digits.size())
  {
    while(b.digits.size() < digits.size())
      b.digits.push_back(0);
  }
  // sum up the two numbers
	for (int k = 0; k < digits.size(); k++)	//0 holds the single unit 1 the tens unit
	{
		digitAdd = digits[k] + b.digits[k] + carry;
		digits[k] = digitAdd % base;
		carry = digitAdd / base;
	}
	if (carry > 0)
		digits.push_back(carry);
}