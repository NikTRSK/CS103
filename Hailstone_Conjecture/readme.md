# Hailstone Conjecture
**Definition**: Take any positive integer n. If n is even, divide it by 2 to get n / 2. If n is odd, multiply it by 3 and add 1 to obtain 3n + 1. Repeat the process indefinitely. The conjecture is that no matter what number you start with, you will always eventually reach 1.

### To Compile & Run
#### Hailstone finder
* compile `hailstone.cpp` with any C++ compiler
* execute the compiled executable

#### Hailstone Stats:
* **Input**: start and end sequence of numbers
* **Output**: The numbers that achieve hailstone in minimum & maximum itterations
* compile `hailstats.cpp` with any C++ compiler
* execute the compiled executable

Ex.
```
$ ./hailstats
Enter the range you want to search: 10 100
Minimum length: 4
Achieved by: 16
Maximum length: 118
Achieved by: 97
```