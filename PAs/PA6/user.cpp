/*
user.cpp

Author: Nikica Trajkovski

Description: User class
*/

#include "user.h"
#include <iostream>
#include <string>

using std::string;
using std::vector;

  User::User() {
  }

  User::User(string name, int birthyear, int zip) {
    set_name(name);
    set_birthyear(birthyear);
    set_zip(zip);
  }

  User::~User() {     
  }

  void User::add_friend(int id) {
    id_friends.push_back(id);
  }
  
  void User::delete_friend(int id) {
    for (unsigned int i = 0; i < id_friends.size(); i++)
    {
      if (id_friends[i] == id) 
        id_friends.erase(id_friends.begin() + i);
    }
  }
   
  // Accessor methods
   
  string User::get_username() {
    return user_name;
  }
   
  int User::get_year() {
    return user_birthyear;
  }
   
  int User::get_zip() {
    return user_zip;
  }
   
  vector<int> User::get_friends_list() {
    vector<int> friends;
    for (unsigned int i = 0; i < id_friends.size(); i++)
      friends.push_back(id_friends[i]);

    return friends;
  }

  // Mutators methods
  void User::set_name(string name) {
    // takes in both first and last name as a single string
    user_name = name;
  }
   
  void User::set_birthyear(int year) {
    user_birthyear = year;
  }
   
  void User::set_zip(int zip) {
    user_zip = zip;
  }
