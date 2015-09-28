/* Author: Nikica Trajkovski
 * Program: diceplot
 * Description: Prints a histogram of rolling 4 6 sided dice in n number of experiments
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int roll()
{	
	//return ( (rand() % 6) +1 );
	return ( ( (int)( ((double) rand() / (RAND_MAX)*100)) ) % 6 + 1 );	// lowers the bias comprad to just using rand() % 6
}

void printHistogram(int counts[])
{
	for ( int i = 0; i <= 20; i++ )
	{
		cout << i + 4 << ":";
		for ( int j = 0; j < counts[i]; j++ )
		{
			cout << "X";
		}
		cout << endl;
	}
}

int main()
{

	int n, rollSum = 0, counts[21] = {0};
	
	// salt the random number generation
	srand( time(0) );
	
	cout << "Enter the number of experiments: ";
	cin >> n;
	cout <<  endl;
	
	// generate the random numbers and count the occurence of each roll
	for ( int i = 0; i < n; i++ )
	{
		rollSum = 0;
		for ( int j = 0; j < 4; j++ )
		{
			rollSum += roll();
		}
		
		counts[rollSum - 4]++;
		
	}
	
	printHistogram(counts);

	return 0;
}