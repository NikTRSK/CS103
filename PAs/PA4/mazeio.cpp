/*
mazeio.cpp

Author: Nikica Trajkovski

Short description of this file:
Functions that read the maze and output the final maze
*/

#include <iostream>
#include "mazeio.h"

using namespace std;

/*************************************************
 * read_maze:
 * Read the maze from cin into a dynamically allocated array.
 *
 * Return the pointer to that array.
 * Return NULL (a special address) if there is a problem,
 * such as integers for the size not found.
 *
 * We also pass in two pointers to integers. Fill
 * the integers pointed to by these arguments
 * with the number of rows and columns
 * read (the first two input values).
 *
 *************************************************/
char** read_maze(int* rows, int* cols)
{
  cin >> *rows >> *cols;

  // allocate memory for the maze
  char **maze = new char*[*rows];

  for (int i = 0; i < *rows; i++)
  {
    maze[i] = new char[*cols];

    for (int j = 0; j < *cols; j++)
      cin >> maze[i][j];  // store the contents of the maze
  }

  return maze;
}

/*************************************************
 * Print the maze contents to the screen in the
 * same format as the input (rows and columns, then
 * the maze character grid).
 *************************************************/
void print_maze(char** maze, int rows, int cols) {
  cout << rows << " " << cols << endl;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
      cout << (maze[i][j]);

    cout << endl;
  }

}
