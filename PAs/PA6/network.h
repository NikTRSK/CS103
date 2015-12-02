/*
network.h

Author: Nikica Trajkovski

Description: Header file for the Network class
*/

#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "user.h"
#include <sstream>
#include <deque>

class Network {
 public:
  Network();
  ~Network();
  int read_friends(const char *filename);
  int write_friends(const char *filename);
  void add_user(std::string username, int yr, int zipcode);
  int add_connection(std::string name1, std::string name2);
  int remove_connection(std::string name1, std::string name2);
  int get_id(std::string username);
  string get_username(int id);
  void get_user_list();
  void get_friends_list(std::string username);
  // check if a user exists
  bool user_exists(std::string name);
  // a shortest path starting at user "from" and ending at user "to".
  vector<int> shortest_path(int from, int to);
  // a list of the components of the network
  vector< vector<int> > groups();
  //suggest friends function
  vector<int> suggest_friends(int who, int& score);

  // BFS helper function
  vector<int> BFS(bool* alreadyVisited,
                  int startUser, int endUser, bool &pathFound);

 private:
   User* newUser;
   vector<User*> user_list;
};


#endif
