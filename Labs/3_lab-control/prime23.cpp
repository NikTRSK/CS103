/* Author: Nikica Trajkovski
 * Program: prime23
 * Description: Finds if a number is divisible only by 2 and 3.
 */
 
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int naturalNumber, twos = 0, threes = 0,
		number_check;

	cout << "Enter a natural number! ";
	cin >> naturalNumber;
	
	number_check = naturalNumber;

   // counts the number of divisors of 2 and 3.
	for ( int check = 1; check < naturalNumber; check++ )
	{
		while (naturalNumber > 1)
		{
			if ( (naturalNumber % 2) == 0 )
			{
				naturalNumber /= 2;
				twos++;
			}

			else if ( (naturalNumber % 3) == 0 )
			{
				naturalNumber /= 3;
				threes++;
			}

			else
				break;
		}
        		
	}   
      
      // checks if the number is divisible only by 2 and 3.
		if ( (pow(2, twos) * pow(3, threes)) == number_check )
		{
			cout << "Yes" << endl;
			cout << "Twos: " << twos << endl;
			cout << "Threes: " << threes << endl;
		}

		else
		{
			cout << "No" << endl;
		}
		
	return 0;
}
