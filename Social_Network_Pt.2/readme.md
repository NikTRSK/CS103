# Social Network Pt.2: Six Degrees of Kevin Bacon
Second part of a simple Social Network implementation.
* Finds shortest paths between users
* Finds the disjoint sets
* Suggests Friends for a user

### To Compile & Run
* run `make` to compile
* execute `./scial_network <input_file>` to run the network



Ex.

```
./social_network users_large.txt

****************** MENU ******************
Option 1: Add a user
    Usage: 1 Steph Curry 1988 94027
Option 2: Add friend connection
    Usage: 2 Mark Redekopp Steph Curry
Option 3: Remove friend connection
    Usage: 3 Mark Redekopp Juju Smith
Option 4: Print users
Option 5: List friend
    Usage: 5 Mark Redekopp
Option 6: Write to file
    Usage: 6 users_new.txt
Option 7: Find shortest path between users
    Usage: 7 Mark Redekopp Max Nikias
Option 8: Find Disjoint Sets
Option 9: Suggest Friends
    Usage: 9 Mark Redekopp
Option 0: Exit the program
```