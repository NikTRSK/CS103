/*  CSCI103 Fall 2015
	Author: Nikica Trajkovski
	email: trjkovs@usc.edu
	Program: hailstone
	Descripton: Computes the hailstone sequence.
*/

#include <iostream>

using namespace std;

int main()
{
	int number, lenght = 0;
	
	cout << "Enter a number: ";
	cin >> number;
	
	/* 	Performs the hailstone sequence calculation
		and counts the number of steps.
		Terminates the calculation before it enters a 4-2-1 loop*/
	while (number > 1)
	{
		
		if ((number % 2) == 0)	// if the number is even
		{
			number /= 2;
		}
		else					// if the number is odd
		{
			number = (number * 3) + 1;
		}
		cout << number << " ";
		lenght += 1;
	}
	
	// Prints out hte number of steps for the calculation.
	cout << endl << "Lenght: " << lenght << endl;
	
	return 0;
}
