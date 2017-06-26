/*
caesarlib.cpp

Author: Nikica Trajkovski
email: trajkovs@usc.edu

Short description of this file:
Library that defines the functions for shifting characters for the Ceasar cypher
*/

#include <fstream>
#include <iostream>
#include "caesarlib.h"

using namespace std;

// is this char an English letter?
bool is_letter(char ch)
{
  if ( ( (ch >= 'a') && (ch <= 'z') ) || ( (ch >= 'A') && (ch <= 'Z') ) )
    return true;
  else
    return false;
}

// return shifted image of ch (if ch not letter, don't shift)
// assumes 0 <= steps < 26
char image(char ch, int steps)
{
  if (is_letter(ch) == true)
  {
    if ( (ch >= 'a') && (ch <= 'z') )   // shift for the lower case letters
    {
      if ( (ch + steps) > 'z' )
        return (char)('a' + (ch + steps - 1)%('z') );
      else
        return (char)(ch + steps);
    }
    else if ( (ch >= 'A') && (ch <= 'Z') )  // shift for the upper case letters
    {
      if ( (ch + steps) > 'Z' )
        return (char)('A' + (ch + steps - 1)%('Z') );
      else
        return (char)(ch + steps);
    }
  }

  return ch;
}

// shift all characters in this file and print it to cout
// return 1 if error (file couldn't be opened), 0 if no error
int print_file_image(const char filename[], int steps)
{
  ifstream inFile (filename);
  if (inFile.fail())
  {
    cerr << "File couldn't be opened." << endl;
    return 1;
  }

  char ch;
  // parse through the file and perform a shift
  while (inFile.get(ch))
    cout << image(ch, steps);

  inFile.close();
  return 0;
}

// convert to lowercase.
// C++ has a built in function (tolower) that achieves this
char get_lowercase(char ch)
{
  if ( (ch >= 'A') && (ch <= 'Z') )
    return (char)(ch + 32);
  else
    return ch;
}
