/* Author: Nikica Trajkovski
 * Program: digits
 * Description: Finds the ones, tens, and hundrets of a number.
 */

#include <iostream>

using namespace std;

int main()
{
   int number, ones, tens, hundrets;
   
   cout << "Enter a number between 0 and 999: ";
   cin >> number;
   
   // find 1's of the number
   ones = number % 10;
   
   // find 10's of the number
   tens = (number / 10) % 10;
   
   // find 100's of the number
   hundrets = number / 100;
   
   // print the values
   cout << "1's digit is " << ones << endl;
   cout << "10's digit is " << tens << endl;
   cout << "100's digit is " << hundrets << endl;
   
   return 0;
}

