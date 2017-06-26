#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream inFile("msg.txt");

  string line;

  getline(inFile, line);

  char *buffer = new char[line.length()];

  line.copy(buffer, line.length());

/*  for ( int i = 0; i < length; i++ )
  {
    inFile.get(*buffer);
  }
*/
  for ( int i = 0; i < line.length(); i++ )
  {
    cout << buffer[i];
  }

/*  for ( int i = 0; i < strlen(buffer); i++)
    cout << buffer;*/

}
