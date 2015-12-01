#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "network.h"
using namespace std;

// compile: g++ {user,network,test_suggest_friends}.cpp -o test_suggest_friends

int main(int argc, char* argv[]) {
   if (argc < 3 || argc > 4) {
      cerr << "Usage: ./test_suggest_friends network_file userid" << endl;
      return -1;
   }
   int who = atoi(argv[2]);

   Network n;
   n.read_friends(argv[1]);
   int score = 0;
   if (argc == 4) score = atoi(argv[3]);
   vector<int> sg = n.suggest_friends(who, score);
   
   cout << "Score: " << score << endl;
   cout << "Suggestions (length " << sg.size() << "):";
   for (unsigned int i=0; i < sg.size(); i++)
      cout << " " << sg[i];

   return 0;
}


/*
./test_suggest_friends users_small.txt 0
Pass: Returned score 1 and these suggestions: 4

./test_suggest_friends users_small.txt 3
FAIL: Returned score 1 and these suggestions: 1 2 3
Expected score 1 and these suggestions: 1 2

./test_suggest_friends users_large.txt 0
Pass: Returned score 2 and these suggestions: 16 27

*/