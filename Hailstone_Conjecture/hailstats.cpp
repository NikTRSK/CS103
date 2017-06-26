/*  CSCI103 Fall 2015
	Author: Nikica Trajkovski
	email: trjkovs@usc.edu
	Program: hailstat
	Descripton: Searches through a range of numbers that the user specifies,
	computes the hailstone sequence	and reports the shortest and longest
	lengths in that range.
*/

#include <iostream>

using namespace std;

int main()
{
	int rangeMin, rangeMax, 
		minLenght = 0, maxLenght = 0, lenght = 0,
		number, minNumber = 0, maxNumber = 0;

	cout << "Enter the range you want to search: ";
	cin >> rangeMin >> rangeMax;

// Make sure that the starting range is smaller that the ending range.	
	if (rangeMin > rangeMax)
	{
		cout << "Your minimum range has to be smaller than your maximum range!!! \n";
		return 0;
	}

	while (rangeMin <= rangeMax)
	{
		lenght = 0;
		number = rangeMin;

		/* 	Performs the hailstone sequence calculation
			and counts the number of steps.
			Terminates the calculation before it enters a 4-2-1 loop*/		
		while (number > 1)
		{

			if ((number % 2) == 0)			// if the number is even
			{
				number /= 2;
			}
			else							// if the number is odd
			{
				number = (number * 3) + 1;
			}
			lenght += 1;
		}

		// Finds the smallest and largest lenghts in the provided range.
		if ((lenght < minLenght) || (minLenght == 0))
		{
			minLenght = lenght;
			minNumber = rangeMin;
		}
		
		
		if (lenght > maxLenght)
		{
			maxLenght = lenght;
			maxNumber = rangeMin;
		}

		rangeMin++;
	}

	cout << "Minimum length: " << minLenght << endl;
	cout << "Achieved by: " << minNumber << endl;

	cout << "Maximum length: " << maxLenght << endl;
	cout << "Achieved by: " << maxNumber << endl;
}
