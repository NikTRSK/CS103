/*
network.cpp

Author: Nikica Trajkovski

Description: Network class
*/

#include "network.h"

Network::Network() {
}

Network::~Network() {
  for (int i = 0; i < user_list.size(); i++)
    delete user_list[i];
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

  // error checking
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

  // error checking
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
  // if id not found return -1
  return -1;
}

string Network::get_username(int id) {
  if ( (user_list.size() < id) || (id < 0) )
    return "-1";
  else
    return user_list[id]->get_username();
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
  vector<int>* friends;
  std::cout << std::left <<
  std::setw(7) << "ID" <<
  std::setw(15) << "Name" <<
  std::setw(7) <<"Year" <<
  std::setw(10) << "Zip" << std::endl;
  std::cout << "==============================================" << std::endl;
  for (unsigned int i = 0; i < user_list.size(); i++)
  {
    if (user_list[i]->get_username() == username)
      friends = &user_list[i]->get_friends_list();
  }

  // extract data from vectors and print formated output
  for (unsigned int j = 0;  j < friends->size(); j++)
  {
    std::string uname = user_list[(*friends)[j]]->get_username();
    int id = get_id(uname);
    // handles formating of single and double digit numbers
    if (id < 10)
      std::cout << std::left << id << std::setw(6) << ".";
    else
      std::cout << std::left << id << std::setw(5) << ".";


    std::cout << std::left << std::setw(23) << uname;
    
    int year = user_list[(*friends)[j]]->get_year();
    std::cout << std::left << std::setw(7) << year;

    int zip = user_list[(*friends)[j]]->get_zip();
    std::cout << std::left << std::setw(10) << zip << std::endl;
  }
}


bool Network::user_exists(std::string name) {
  if (get_id(name) == -1)
    return false;
  else
    return true;
}

// a shortest path starting at user "from" and ending at user "to".
vector<int> Network::shortest_path(int from, int to) {

  // mark all users as not visited
  bool* visited = new bool[user_list.size()];
  for (int i = 0; i < user_list.size(); i++)
    visited[i] = false;

  // keeps track whether a path has been found
  bool pathFound = false;

  // run the BFS algorhitm to find the path to the friend
  vector<int> path = BFS(visited, from, to, pathFound);
  // delete allocated memory
  delete [] visited;

  // stores the path in the from->to direction
  vector<int> forwardPath;

  // if pathFound reverse the direction to the correct direction
  if (pathFound)
  {
    vector<int> backtrack;

    // backtrack starting from the back (generate the actual shortest path)
    backtrack.push_back(to);
    while (user_list[backtrack.back()]->predecessor != -1)
      backtrack.push_back(user_list[backtrack.back()]->predecessor);

    (user_list[from]->depth) = backtrack.size() - 1;
    // create the path in the from->to direction
    for (int i = backtrack.size() - 1; i >= 0; i--)
      forwardPath.push_back(backtrack[i]);

    return forwardPath;
  }
  // if path not found return an empty vector
  else
    return forwardPath;

}

// a list of the components of the network
vector<vector<int> > Network::groups() {
  
  // store all disjoint sents in a 2D vector
  vector<vector<int> > sets;

  // mark all users as not visited yet
  bool* visited = new bool[user_list.size()];
  for (int i = 0; i < user_list.size(); i++)
    visited[i] = false;

  // keeps track whether a path has been found
  bool pathFound = false;

  // run the BFS algorhitm to find the path to the friend
  for (int i = 0; i < user_list.size(); i++)
  {
    // make sure that each user is explored only once
    if (!visited[i])
    {
      visited[i] = true;
      // explore all nodes for a user. to = -1 means it never finds
      // the path but explores all nodes
      sets.push_back(BFS(visited, i, -1, pathFound));
    }
  }

  // delete dynamic memory
  delete [] visited;

  return sets;
}

// suggested friends with highest score for this user.
// fills in "score" at the given pointer.
// if no suggestions exist, give empty vector and 
//   set score to be -1 
vector<int> Network::suggest_friends(int who, int& score) {
  
  // keeps track of the # of identical friends
  int currScore = 0;
  // holds a list of suggested friends
  vector<int> suggestions;
  // holds a list of friends for a user
  vector<int>* friends;
  // get the friend list of the originating user
  vector<int>* friendsOrigUser = &user_list[who]->get_friends_list();

  // compare friends with all users
  for (unsigned int userID = 0; userID < user_list.size(); userID++)
  {
    // check if the user is the same as the originating user
    if (userID != who)
    {
      // get a list of users of the user
      friends = &user_list[userID]->get_friends_list();
    

      for (unsigned int friendID = 0; friendID < friends->size(); friendID++)
      {
        // checks if the originating user and the current user are already friends
        if ((*friends)[friendID] == who)
        {
          currScore = 0;
          break;
        }
        else
        {
          for (unsigned int originUserFriendID = 0;
               originUserFriendID < friendsOrigUser->size(); originUserFriendID++)
          {
            if ((*friendsOrigUser)[originUserFriendID] == (*friends)[friendID])
              currScore++;
          }
        }
      }

      if (currScore >= score)
      {
        vector<int> chkDist = shortest_path(who, userID);
        // checks if the users are 2 hops away
        if (user_list[who]->depth >= 2)
        {
          if ((currScore > score) && (currScore > 0))
          {
            score = currScore;
            suggestions.clear();
            suggestions.push_back(userID);
          }
          else if ((currScore == score) && (currScore > 0))
            suggestions.push_back(userID);
        }
      }
    }
    currScore = 0;
  }
  // just for the sake of the assignment. absolutely not needed
  if (suggestions.size() == 0)
    score = -1;
  
  return suggestions;
}

vector<int> Network::BFS(bool* alreadyVisited, int startUser, int endUser,
                         bool &pathFound) {
  // define a Deque
  std::deque<int> friendQueue;
  // keeps track of the path to the final user
  vector<int> pathToRome;
  // add the initial user to the deque
  friendQueue.push_back(startUser);
  // set the predecessor of the starting user to -1
  user_list[startUser]->predecessor = -1;
  // mark the starting user as visited
  alreadyVisited[startUser] = true;
  // add the starting user to the path
  pathToRome.push_back(startUser);
  
  while ( (!friendQueue.empty()) && (!pathFound) )
  {
    // load up the friend list
    vector<int> friendList = user_list[friendQueue.front()]->get_friends_list();
    
    // add each friend in the list
    for (unsigned int friendID = 0; friendID < friendList.size(); friendID++)
    {
      // make sure it hasn't been visited yet
      if (!alreadyVisited[friendList[friendID]])
      {
        // label the friend as visited
        alreadyVisited[friendList[friendID]] = true;
        // add the friend to the deque
        friendQueue.push_back(friendList[friendID]);
        // make the current user the predecessor of the friend
        user_list[friendList[friendID]]->predecessor = friendQueue.front();
        // add the user to the path
        pathToRome.push_back(friendList[friendID]);

        // check if the path to the end user is found
        if (friendList[friendID] == endUser)
          pathFound = true;
      }
    }
    // delete the current user from the queue
    friendQueue.pop_front();
  }
  //std::cout << "rome: " << pathToRome.size() << std::endl;
  return pathToRome;
}
