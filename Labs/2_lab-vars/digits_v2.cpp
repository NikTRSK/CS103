/* Author: Nikica Trajkovski
 * Program: digits
 * Description: Finds the ones, tens, and hundrets of a number using a while loop.
 */

#include <iostream>

using namespace std;

int main()
{
   int number, digit;
   
   cout << "Enter a number between 0 and 999: ";
   cin >> number;
   
   while (number >= 10)
   {
	   digit = number % 10;
	   number = number / 10;
	   
	   cout << digit << endl;
   }
   
   cout << number << endl;
   return 0;
}
