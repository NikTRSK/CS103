/*
shift.cpp

Author: Nikica Trajkovski
email: trajkovs@usc.edu

Short description of this file: Performs a Caesar cypher by shifting a phrase
by a certain ammount of spots
*/

#include "caesarlib.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
   if (argc != 3)
   {
      cout << "Wrong number of arguments." << endl;
      cout << "Usage: shift message.txt shift_number" << endl;
      return 1;
   }

   // read the arguments and print the shifted output
   int errorCheck = print_file_image(argv[1], atoi(argv[2]));

   // return sensible error if the filename is wrong
   if (errorCheck != 0)
   {
      cout << "Couldn't open the input file, or bad file name." << endl;
      return 1;
   }
   else
    return 0;
}
