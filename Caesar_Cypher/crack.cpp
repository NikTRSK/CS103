/*
crack.cpp

Author: Nikica Trajkovski
email: trajkovs@usc.edu

Short description of this file: Performs Caesar cypher cracking by analizing
letter frequencies
*/

#include "caesarlib.h"
#include <fstream>
#include <iostream>

using namespace std;

// frequencies of letters in a large sample of English
const double enfreq[26] = {0.0793, 0.0191, 0.0392, 0.0351, 0.1093,
   0.0131, 0.0279, 0.0238, 0.0824, 0.0024, 0.0103, 0.0506, 0.0277,
   0.0703, 0.0602, 0.0274, 0.0019, 0.0705, 0.1109, 0.0652, 0.0321,
   0.0098, 0.0093, 0.0026, 0.0156, 0.0040};

// return score when ch is shifted (if ch not letter, return 0)
double char_score(char ch, int shift)
{
  char test_ch = (char)( get_lowercase(image(ch, shift)) );
  if ( (test_ch >= 'a') && (test_ch <= 'z') )
    return (double)( enfreq[(int)(test_ch - 'a')] );
  else
    return 0.0;
}

// return score when contents of entire file are shifted
double file_score(const char filename[], int shift)
{
   ifstream inFile(filename);

   if (inFile.fail())
   {
     cerr << "File couldn't be opened." << endl;
     return 1;
   }

   char ch;
   double totalScore = 0;
   // parse through the file and calculate the score
   while (inFile.get(ch))
     totalScore += char_score(ch, shift);

   inFile.close();
   return totalScore;
}

int main(int argc, char* argv[])
{
   if (argc != 2)
   {
      cout << "Wrong number of arguments." << endl;
      cout << "Usage: decrypt ciphertext.txt" << endl;
      return 1;
   }

   // check for best score
   double bestScore = 0;
   int bestSteps = 0;
   for (int steps = 0; steps <= 25; steps++)
   {
     double currentScore = file_score(argv[1], steps);
     if (currentScore > bestScore)
     {
       bestScore = currentScore;
       bestSteps = steps;
     }
   }

   // print out the resultant code crack
   int errorCheck = print_file_image(argv[1], bestSteps);

   // return sensible error if the filename is wrong
   if (errorCheck != 0)
   {
      cerr << "Couldn't open the input file, or wrong file name." << endl;
      return 1;
   }
   else
    return 0;
}
