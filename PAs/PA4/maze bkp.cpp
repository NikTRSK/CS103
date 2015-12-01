/*
maze.cpp

Author: Nikica Trajkovski

Short description of this file: A maze solver
using Breath First Search.
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main()
{
   int rows, cols, result;

   // read and store the maze into a pointer array
   char** mymaze = read_maze(&rows, &cols);

   if (mymaze == NULL)
   {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   result = maze_search(mymaze, rows, cols);

   // examine value returned by maze_search and print appropriate output
   if (result == 1)
   { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0)
   { // no path :(
      cout << "No path could be found!" << endl;
   }
   else
   { // result == -1
      cout << "Invalid maze." << endl;
   }

   // that read_maze allocated
   for (int i = 0; i < rows; i++)
   {
     delete [] mymaze[i];
   }
   delete [] mymaze;

   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols)
{
  int numStarts = 0, numFinishes = 0;
  bool solutionFound = false;

  // find the starting and ending location
  Location start;
  Location finish;
   for (int i = 0; i < rows; i++)
   {
     for (int j = 0; j < cols; j++)
     {
       if (maze[i][j] == 'S')
       {

         start.row = i;
         start.col = j;

         numStarts++;
       }
       else if (maze[i][j] == 'F')
       {

         finish.row = i;
         finish.col = j;

         numFinishes++;
       }
     }
   }

   // check if starting and ending location exist
  if ( (numStarts != 1) || (numFinishes != 1) )
    return -1;

  // initialize the Queue
  int max_size = rows * cols;

  Queue searchQueue(max_size);

  // initialize visited array
  bool **visited = new bool *[rows];
  for (int i = 0; i < rows; i++)
  {
    visited[i] = new bool[cols];

    // set the array to false
    for (int j = 0; j < cols; j++)
      visited[i][j] = false;
  }

  // initialize presecesessor array
  Location **predecessor = new Location *[rows];
  for (int i = 0; i < rows; i++)
    predecessor[i] = new Location[cols];

  // add the start of the array to the Queue
  searchQueue.add_to_back(start);
  // mark the location as visited
  Location previousLocation = start;
  while (!searchQueue.is_empty())
  {
    Location currentLocation = searchQueue.remove_from_front();
    if (!visited[currentLocation.row][currentLocation.col])
    {
      // mark cell as visited
      visited[currentLocation.row][currentLocation.col] = true;

      if (maze[currentLocation.row][currentLocation.col] == 'F')
      {
        solutionFound = true;
        //break;
      }

      // check north cell
      if (currentLocation.row-1 >= 0)  // check for out of bounds
      {
        if ( (maze[currentLocation.row-1][currentLocation.col] != '#') && (!visited[currentLocation.row-1][currentLocation.col]) )
        {
          Location neighbourNorth;
          neighbourNorth.row = currentLocation.row-1;
          neighbourNorth.col = currentLocation.col;
          searchQueue.add_to_back(neighbourNorth);

          predecessor[neighbourNorth.row][neighbourNorth.col].row = currentLocation.row;
          predecessor[neighbourNorth.row][neighbourNorth.col].col = currentLocation.col;
        }
      }

      // check west cell
      if ((currentLocation.col-1) >= 0)  // check for out of bounds
      {
        if ( (maze[currentLocation.row][currentLocation.col-1] != '#') && (!visited[currentLocation.row][currentLocation.col-1]) )
        {
          Location neighbourWest;
          neighbourWest.row = currentLocation.row;
          neighbourWest.col = currentLocation.col-1;
          searchQueue.add_to_back(neighbourWest);

          predecessor[neighbourWest.row][neighbourWest.col].row = currentLocation.row;
          predecessor[neighbourWest.row][neighbourWest.col].col = currentLocation.col;
        }
      }

    // check if the location is open and not visited
      // check south cell
      if ((currentLocation.row+1) < rows)  // check for out of bounds
      {
        if ( (maze[currentLocation.row+1][currentLocation.col] != '#') && (!visited[currentLocation.row+1][currentLocation.col]) )
        {
          Location neighbourSouth;
          neighbourSouth.row = currentLocation.row+1;
          neighbourSouth.col = currentLocation.col;
          searchQueue.add_to_back(neighbourSouth);

          predecessor[neighbourSouth.row][neighbourSouth.col].row = currentLocation.row;
          predecessor[neighbourSouth.row][neighbourSouth.col].col = currentLocation.col;
        }
      }

      // check east cell
      if ((currentLocation.col+1) < cols)  // check for out of bounds
      {
        if ( (maze[currentLocation.row][currentLocation.col+1] != '#') && (!visited[currentLocation.row][currentLocation.col+1]) )
        {
          Location neighbourEast;
          neighbourEast.row = currentLocation.row;
          neighbourEast.col = currentLocation.col+1;
          searchQueue.add_to_back(neighbourEast);

          predecessor[neighbourEast.row][neighbourEast.col].row = currentLocation.row;
          predecessor[neighbourEast.row][neighbourEast.col].col = currentLocation.col;
        }
      }
    }
    previousLocation = currentLocation; // remembers the previous location before extracting a new member from the queue
  }

  // follow the breadcrumbs
  Location tempLoc = predecessor[finish.row][finish.col];
  while (maze[tempLoc.row][tempLoc.col] != 'S')
  {
    maze[tempLoc.row][tempLoc.col] = '*';
    tempLoc = predecessor[tempLoc.row][tempLoc.col];
  }

  // delete memory
  for (int i = 0; i < rows; i++)
  {
    delete [] visited[i];
    delete [] predecessor[i];
  }

  delete [] visited;
  delete [] predecessor;

  if (solutionFound)
  {
    return 1;
  }
  else
    return 0;
}

//void explore_cell();
