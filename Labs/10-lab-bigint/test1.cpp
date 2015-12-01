#include "bigint.h"
#include <iostream>
using namespace std;

int main() {
  BigInt a("13");
  BigInt b("42");
  b.add(a);    // increase b by a
  cout << b.to_string() << endl; // prints 55
  b.add(a);    // increase b by a
  cout << b.to_string() << endl; // prints 68

  // extra tests
  cout << "====Extra tests====" << endl;
  b.add(a);    // increase b by a
  cout << b.to_string() << endl; // prints 81

  b.add(a);    // increase b by a
  cout << b.to_string() << endl; // prints 94

  b.add(a);    // increase b by a
  cout << b.to_string() << endl; // prints 107

  cout << "=====Extra credit bussiness=====" << endl;
  cout << "***HEX***" << endl;
  BigInt first("DADCAFE", 16); // hexadecimal
	BigInt second("AAABEEF", 16);
	first.add(second);
	cout << first.to_string() << endl; // prints 185889ED

	cout << "***OCT***" << endl;
  BigInt third("1457", 8); // hexadecimal
	BigInt fourth("4721", 8);
	third.add(fourth);
	cout << third.to_string() << endl; // prints 6400

	cout << "***DIFFERENT BASES***" << endl;
  BigInt fifth("1457", 10); // hexadecimal
	BigInt sixth("4721", 8);
	fifth.add(sixth);	// prints out an error

/*	cout << "***DIGITS OUT OF RANGE***" << endl;
  BigInt seventh("145A", 10); // hexadecimal*/

  return 0;
}
