/* Author: Nikica Trajkovski
 * Program: color_conv
 * Description: converts RGB values to CMYK values.
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // Enter your code here
   int red, green, blue;
   double cyan, magenta, yellow, black, white;
   
   // Get values for Red, Green, Blue
   cout << "Enter values for: \n";

   cout << "red: ";
   cin >> red;

   cout << "green: ";
   cin >> green;
   
   cout << "blue: ";
   cin >> blue;
   
   // Define white
   if (red > green)
   {
      white = max( (red / 255.0), (blue / 255.0) );
   }
   
   else
   {
      white = max( (green / 255.0), (blue / 255.0) );
   }
   
   // Calculate Cyan
   cyan = (white - red / 255.0) / white;
   
   // Calculate Magenta
   magenta = (white - green / 255.0) / white;
   
   // Calculate Yellow
   yellow = (white - blue / 255.0) / white;
   
   // Calculate Black
   black = 1 - white;
   
   cout << endl;
   cout << "cyan: " << cyan << endl;
   cout << "magenta: " << magenta << endl;
   cout << "yellow: " << yellow << endl;
   cout << "black: " << black << endl;
   
   return 0;
}
