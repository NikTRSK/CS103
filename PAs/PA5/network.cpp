#include "network.h"

  Network::Network() {
  }

  Network::~Network() {
    for (int i = 0; i < user_list.size(); i++)
      delete user_list[i];
    
    //delete[] user_list;
  }

  int Network::read_friends(const char *filename) {
    
    // open the file
    std::ifstream inFile(filename);

    // error checking
    if (inFile.fail())
    {
      std::cerr << "File couldn't be opened." << std::endl;
      return -1;
    }
    
    std::string id, uname, year, zip, friends;

    // iterate over the each user in the input file
    std::string numOfUsers;
    getline(inFile, numOfUsers);
    int num = atoi(numOfUsers.c_str());   

    for (int i = 0; i < num; i++)
    {
      getline(inFile, id);

      getline(inFile, uname);
      uname.erase(uname.begin(), uname.begin()+1); // remove leading tab
      
      getline(inFile, year);
      year.erase(year.begin(), year.begin()+1); // remove leading tab
      
      getline(inFile, zip);
      zip.erase(zip.begin(), zip.begin()+1); // remove leading tab

      // creates a new user in the database
      newUser = new User(uname, atoi(year.c_str()), atoi(zip.c_str()));
      user_list.push_back(newUser); // add the new user to the user_list vector

      // add friends
      std::string temp_str;
      getline(inFile, friends);
      friends.erase(friends.begin(), friends.begin()+1);
      std::stringstream ss(friends);

      int friend_id;
      while(ss >> friend_id)
      {
        user_list[atoi(id.c_str())]->add_friend(friend_id);
      }
      ss.clear();
      ss.str("");
    }

    inFile.close();

    return 0;
  }
  
  int Network::write_friends(const char *filename) {

    // create an output file
    std::ofstream outFile(filename);

    // error checking
    if (outFile.fail())
    {
      std::cerr << "File couldn't be opened." << std::endl;
      return -1;
    }

    // store formated user list to the output file
    outFile << user_list.size() << std::endl;
    for (unsigned int i = 0; i < user_list.size(); i++)
    {
      // get the data and store it to variables
      std::string username = user_list[i]->get_username();
      int id = get_id(username);
      int year = user_list[i]->get_year();
      int zip = user_list[i]->get_zip();
      vector<int> friends = user_list[i]->get_friends_list();

      // push user info to output file 
      outFile << id << std::endl << 
                "\t" << username << std::endl <<
                "\t" << year << std::endl <<
                "\t" << zip << std::endl << "\t";

      // store friend list to the file
      for (int j = 0; j < friends.size(); j++)
      {
        if (j == (friends.size() - 1))
          outFile << friends[j];
        else
          outFile << friends[j] << " ";
      }
      outFile << std::endl;
    }

    outFile.close();
    return 0;
  }

  void Network::add_user(std::string username, int yr, int zipcode) {
    newUser = new User(username, yr, zipcode);
    user_list.push_back(newUser);
  }

  int Network::add_connection(std::string name1, std::string name2) {
    int id_user1 = -1, id_user2 = -1;

    for (unsigned int i = 0; i < user_list.size(); i++)
    {
      if (user_list[i]->get_username() == name1)
        id_user1 = i;

      else if (user_list[i]->get_username() == name2)
        id_user2 = i;
    }

    if ( (id_user1 == -1) || (id_user2 == -1) )
      return -1;
    else
    {
      user_list[id_user1]->add_friend(id_user2);
      user_list[id_user2]->add_friend(id_user1);
      return 0;
    }
  }
  
  int Network::remove_connection(std::string name1, std::string name2) {
    int id_user1 = -1, id_user2 = -1;

    for (unsigned int i = 0; i < user_list.size(); i++)
    {
      if (user_list[i]->get_username() == name1)
        id_user1 = i;

      if (user_list[i]->get_username() == name2)
        id_user2 = i;
    }

    if ( (id_user1 == -1) || (id_user2 == -1) )
      return -1;
    else
    {
      user_list[id_user1]->delete_friend(id_user2);
      user_list[id_user2]->delete_friend(id_user1);
      return 0;
    }
  }

  int Network::get_id(std::string username) {
    for (unsigned int i = 0; i < user_list.size(); i++)
    {
      if (user_list[i]->get_username() == username)
        return i;
    }
    return -1;
  }

  void Network::get_user_list() {
    std::cout << std::left <<
    std::setw(7) << "ID" <<
    std::setw(15) << "Name" <<
    std::setw(7) << "Year" <<
    std::setw(10) << "Zip" << std::endl;
    std::cout << "==============================================" << std::endl;
    
    // extract data from vectors and print formated output
    for (unsigned int i = 0; i < user_list.size(); i++)
    {
      int id = i;

      // handles formating of single and double digit numbers
      if (id < 10)
        std::cout << std::left << id << std::setw(6) << ".";
      else
        std::cout << std::left << id << std::setw(5) << ".";

      std::string uname = user_list[i]->get_username();
      std::cout << std::left << std::setw(23) << uname;
      
      int year = user_list[i]->get_year();
      std::cout << std::left << std::setw(7) << year;

      int zip = user_list[i]->get_zip();
      std::cout << std::left << std::setw(10) << zip << std::endl;
    }
  }

  void Network::get_friends_list(std::string username) {
    vector<int> friends;
    std::cout << std::left <<
    std::setw(7) << "ID" <<
    std::setw(15) << "Name" <<
    std::setw(7) <<"Year" <<
    std::setw(10) << "Zip" << std::endl;
    std::cout << "==============================================" << std::endl;
    for (unsigned int i = 0; i < user_list.size(); i++)
    {
      if (user_list[i]->get_username() == username)
        friends = user_list[i]->get_friends_list();
    }

    // extract data from vectors and print formated output
    for (unsigned int j = 0;  j < friends.size(); j++)
    {
      std::string uname = user_list[friends[j]]->get_username();
      int id = get_id(uname);
      // handles formating of single and double digit numbers
      if (id < 10)
        std::cout << std::left << id << std::setw(6) << ".";
      else
        std::cout << std::left << id << std::setw(5) << ".";


      std::cout << std::left << std::setw(23) << uname;
      
      int year = user_list[friends[j]]->get_year();
      std::cout << std::left << std::setw(7) << year;

      int zip = user_list[friends[j]]->get_zip();
      std::cout << std::left << std::setw(10) << zip << std::endl;
    }
  }
