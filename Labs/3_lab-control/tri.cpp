/* Author: Nikica Trajkovski
 * Program: tri
 * Description: Prints a triangle using stars and if
   the number of stars in a row is between 20 and 30 it only prints
   20 stars in that row.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double theta, radians, x_lenght;
   
	cout << "Enter a value for degrees between 15 and 75 degrees: ";
	cin >> theta;   // value originally in radians
   
	// conversion to degrees
	radians = double (( theta * M_PI ) / 180.0);

	// loop that prints a triangle of angle theta
	for (int row = 1; row <= 30; row++)
	{
	   
		/* check if the number of * is between 20 and 30. If it is set the number of *
		to 20 */
		if ( (floor(tan(radians) * row) >= 20) && (floor(tan(radians) * row) <= 30) )
		{
			x_lenght = 20;
		}
		
		// otherwise print the regular number of *
		else
		{
			x_lenght = floor(tan(radians) * row);
		}

		// print the triangle
		for (int column = 1; column <= x_lenght; column++)
		{ 
			cout << "*";
		}
		cout << endl;
   }
   
	return 0;
}

