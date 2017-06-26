#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream inFile("users_small.txt");

	
  int num;
	string user_id;
	string input;
	string zip;
	string year;
	string friends;

  string numOfUsers;
	getline(inFile, numOfUsers);
  num = atoi(numOfUsers.c_str());
  cout << num << endl;

    for (int i = 0; i < num; i++)
    {
      getline(inFile, user_id);
      getline(inFile, input);
      input.erase(input.begin(), input.begin()+1);
      getline(inFile, year);
      year.erase(year.begin(), year.begin()+1);
      getline(inFile, zip);
      zip.erase(zip.begin(), zip.begin()+1);
      //getline(inFile, friends);

      //cout << setw(20);
      cout << "id: " <<user_id << endl;
      cout << "name: " << input << endl;
      cout << "year: " << year << endl;
      cout << "zip: " << zip << endl;
      inFile.get(friend);
      cout << "friends: " << friends << endl;
    }

    return 0;
}

/*

5
0
  Mark Redekopp
  1978
  90018
  1 2 3
1
  Juju Smith
  1995
  90271
  0 2
2
  Tommy Trojan
  1885
  90089
  0 1
3
  Max Nikias
  1945
  91103
  0 4
4
  Jane Doe
  1988
  90007
  3


*/