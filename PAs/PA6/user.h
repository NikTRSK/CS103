/*
user.h

Author: Nikica Trajkovski

Description: User file for the Network class
*/

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class User {
 public:
   User();
   User(string name, int birthyear, int zip);
   ~User();

   // Adder methods
   void add_friend(int user_id);
   void delete_friend(int user_id);

   // Accessor methods
   string get_username();
   int get_year();
   int get_zip();
   vector<int> get_friends_list();

   // Mutator methods
   void set_name(string name);
   void set_birthyear(int year);
   void set_zip(int zip);

 private:
   string user_name;
   int user_birthyear;
   int user_zip;
   vector<int> id_friends;
   
public:
   int depth;
   int predecessor;
};


#endif
