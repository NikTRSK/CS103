#include "network.h"
#include "user.h"

using namespace std;

// function prototypes
void menu();

int main(int argc, char *argv[])
{

// define input variables
string firstUser, secondUser, temp;
int zip, year, opt;
int check = 0;

  if (argc != 2)
  {
    cout << "Wrong number of arguments." << endl;
    cout << "Usage: social_network filename" << endl;
    return 1;
  }

  // initialize social network
  Network socialNetwork;
  int read = socialNetwork.read_friends(argv[1]);
  // error checking
  if (read == -1)
  {
    cerr << "Couldn't open file";
    return 1;
  }
do
  // Option menu:
  {
    menu();

    cin >> opt;

    // Option 1
    if (opt == 1)
    {
      cin >> firstUser >> temp;
      firstUser.append(1, ' ');
      firstUser.append(temp);
      cin >> year;
      cin >> zip;
      
      socialNetwork.add_user(firstUser, year, zip);
    }

    // Option 2
    if (opt == 2)
    {
      cin >> firstUser >> temp;
      firstUser.append(1, ' ');
      firstUser.append(temp);

      cin >> secondUser >> temp;
      secondUser.append(1, ' ');
      secondUser.append(temp);
      
      check = socialNetwork.add_connection(firstUser, secondUser);
      if (check == -1)
      {
        cerr << "Problem connecting friends. Check if the users exist." << endl;
      }
    }

    // Option 3
    if (opt == 3)
    {
      cin >> firstUser >> temp;
      firstUser.append(1, ' ');
      firstUser.append(temp);

      cin >> secondUser >> temp;
      secondUser.append(1, ' ');
      secondUser.append(temp);
      
      check = socialNetwork.remove_connection(firstUser, secondUser);
      if (check == -1)
      {
        cerr << "Problem connecting friends. Check if the users exist." << endl;
      }
    }

    // Option 4
    if (opt == 4)
    {
      socialNetwork.get_user_list();
    }

    // Option 5
    if (opt == 5)
    {
      cin >> firstUser >> temp;
      firstUser.append(1, ' ');
      firstUser.append(temp);

      socialNetwork.get_friends_list(firstUser);
    }

    // Option 6
    if (opt == 6)
    {
      string file;
      cin >> file;
      check = socialNetwork.write_friends(file.c_str());
      if (check == -1)
      {
        cerr << "Problem connecting friends. Check if the users exist." << endl;
      }
    }

    // Option 7
    if (opt == 7)
    {
      cin >> firstUser >> temp;
      firstUser.append(1, ' ');
      firstUser.append(temp);

      cin >> secondUser >> temp;
      secondUser.append(1, ' ');
      secondUser.append(temp);
      
      if ( (socialNetwork.user_exists(firstUser)) &&
         (socialNetwork.user_exists(secondUser)) )
      {
        vector<int> path =
          socialNetwork.shortest_path(socialNetwork.get_id(firstUser),
          socialNetwork.get_id(secondUser));

        if (path.size() == 0)
        {
          cout << "NONE" << endl;
        }
        else
        {
          cout << "Distance: " << path.size() - 1 << endl;
          for (int i = 0; i < path.size(); i++)
          {
            cout << socialNetwork.get_username(path[i]);
          // only print an arrow if the item is not last in the list
          if ( i < (path.size() - 1) )
            cout << " -> ";
          }
          cout << endl;
        }
      cout << endl;
      }
      else
        cerr << "Problem finding users. Make sure both users exist." << endl;
    }

    // Option 8
    if (opt == 8)
    {
      vector<vector<int> > sets = socialNetwork.groups();

      for (unsigned int i = 0; i < sets.size(); i++)
      {
        cout << "Set " << (i+1) << " => ";

        for (unsigned int j = 0; j < sets[i].size(); j++)
        {
          cout << socialNetwork.get_username(sets[i][j]);
          if ( j < (sets[i].size() - 1) )
            cout << ", ";
        }

        cout << endl;
      }
    }

    // Option 9
    if (opt == 9)
    {
      cin >> firstUser >> temp;
      firstUser.append(1, ' ');
      firstUser.append(temp);
      
      int score = 0;

      if (!socialNetwork.user_exists(firstUser))
        cerr << firstUser << " is not a valid user. Try a different user." << endl;
      else
      {
        vector<int> suggesgions = 
              socialNetwork.suggest_friends(socialNetwork.get_id(firstUser), score);

        cout << "The suggested friend(s) is/are:" << endl;

        if (suggesgions.size() == 0)
          cout << "NONE" << endl;
        else
        {
          for (unsigned int i = 0; i < suggesgions.size(); i++)
            cout << "\t" << socialNetwork.get_username(suggesgions[i]) <<
                    "\tScore: " << score << endl;
        }
        cout << endl;
      }

      cout << endl;
    }
  } while ( (opt > 0) && (opt < 10) );

  return 0;
}

void menu()
{
  cout << "****************** MENU ******************" << endl;
  cout << "Option 1: Add a user" << endl;
  cout << "    Usage: 1 Steph Curry 1988 94027" << endl;

  cout << "Option 2: Add friend connection" << endl;
  cout << "    Usage: 2 Mark Redekopp Steph Curry" << endl;

  cout << "Option 3: Remove friend connection" << endl;
  cout << "    Usage: 3 Mark Redekopp Juju Smith" << endl;

  cout << "Option 4: Print users" << endl;

  cout << "Option 5: List friend" << endl;
  cout << "    Usage: 5 Mark Redekopp" << endl;

  cout << "Option 6: Write to file" << endl;
  cout << "    Usage: 6 users_new.txt" << endl;

  cout << "Option 7: Find shortest path between users" << endl;
  cout << "    Usage: 7 Mark Redekopp Max Nikias" << endl; 

  cout << "Option 8: Find Disjoint Sets" << endl;

  cout << "Option 9: Suggest Friends" << endl;
  cout << "    Usage: 9 Mark Redekopp" << endl;

  // also exits on any other number outside of range
  cout << "Option 0: Exit the program" << endl;
}
