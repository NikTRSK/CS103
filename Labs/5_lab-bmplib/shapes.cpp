/* Author: Nikica Trajkovski
 * Program: shapes
 * Description: Draws rectangles and circles based on users input
 */
#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

unsigned char image[SIZE][SIZE];

// Function prototypes
void draw_rectangle(int top, int left, int height, int width);
void draw_ellipse(int cy, int cx, int height, int width);

int main()
{
  int choice = 0, x, y, height, width;
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }

cout << "To draw a rectangle, enter: 0 top left height width\n";
cout << "To draw an ellipse, enter: 1 cy cx height width\n";
cout << "To save your drawing as \"output.bmp\" and quit, enter: 2\n";
while (choice < 2)
{
  cin >> choice;
  if (choice == 2)   // Checks if the user wants to quit
    {
      break;
    }
  cin >> x >> y >> height >> width;
  if (choice == 0)   // Checks if the user wants a triangle
  {
    draw_rectangle(x,y,height,width);
  }
  if (choice == 1)   // Checks if the user wants an ellipse
  {
    draw_ellipse(x,y,height,width);
  }

}

   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);

   return 0;
}


// Function to draw a rectangle
void draw_rectangle(int top, int left, int height, int width)
{
  int x_max = width + left;
  int y_max = height + top;
  for (int i = top; i < y_max; i++)
  {
    // draws the row if the pixel is within the grid
    if ( (i >= 0) && (i < SIZE) )
    {
      // draws out the first and last row (x-axis)
      if ( (i == top) || (i == (y_max -1)))
      {
        for (int j = left; j < x_max; j++)
        {
          // draws out the columns (y-axis)
          if ( (j >= 0) && (j < SIZE) )
            image[i][j] = 0;
        }
      }
      // checks other cases and draws the appropriate rows
      else
      {
        if ( left >= 0 )
          image[i][left] = 0;
        if ( (x_max - 1) < SIZE )
          image[i][x_max - 1] = 0;
      }
    }
  }
}

// Function to draw an ellipse
void draw_ellipse(int cy, int cx, int height, int width)
{
  double rx = width/2;
  double ry = height/2;

  for (double theta=0.0; theta < 2*M_PI; theta += .01)
  {
    int x = (int)((rx)*cos(theta));
    int y = (int)((ry)*sin(theta));

    x += cx;
    y += cy;

    // draws the array only if it is within the grid
    if ( (x < 0) || (x > SIZE) || (y < 0) || (y > SIZE) )
    {
      continue;
    }
    else
      image[(int)y][(int)x] = 0;
  }
}
