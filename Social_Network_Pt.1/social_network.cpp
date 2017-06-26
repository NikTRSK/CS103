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

    cout << endl;
  } while ( (opt > 0) && (opt < 7) );

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
  // also exits on any other number outside of range
  cout << "Option 7: Exit the program" << endl;
}
