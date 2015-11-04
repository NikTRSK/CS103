/*
crack.cpp

Author: Nikica Trajkovski
email: trajkovs@usc.edu

Short description of this file:
Extra credit part 1. Didn't have time for part 2.
*/

#include "caesarlib.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;

// frequencies of letters in a large sample of a language
double letterFreqs[26] = {0.0};

// function prototypes
int calc_freqs(const char filename[], double letters[]);
double file_score(const char filename[], int shift);
double char_score(char ch, int shift);

// actual main
int main(int argc, char* argv[])
{
  if (argc != 3)
  {
     cout << "Wrong number of arguments." << endl;
     cout << "Usage: extra ciphertext.txt corpusfile1.txt corpusfile2 ... corpusfile3.txt" << endl;
     return 1;
  }

calc_freqs(argv[2], letterFreqs);

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

// calculate frequencies of each letter
int calc_freqs(const char filename[], double letters[])
{
  ifstream inFile;
  inFile.open(filename);

  if (inFile.fail())
  {
    cerr << "File couldn't be opened." << endl;
    return 1;
  }

  char ch;
  double total = 0;
  while (inFile.get(ch))
  {
    if ( is_letter(ch) )
    {
      letters[(int)(tolower(ch)-'a')]++;
      total++;
    }
  }

  inFile.close();

  for (int i = 0; i < 26; i++)
  {
    letters[i] = letters[i]/total;
  }
  return 0;
}

// return score when ch is shifted (if ch not letter, return 0)
double char_score(char ch, int shift)
{
  char test_ch = (char)( get_lowercase(image(ch, shift)) );
  if ( (test_ch >= 'a') && (test_ch <= 'z') )
    return (double)( letterFreqs[(int)(test_ch - 'a')] );
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
