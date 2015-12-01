#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <vector>

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

class BigInt {
   public:
      BigInt(string s);   // convert string to BigInt

      BigInt(string s, int base);   // convert string to BigInt with a base
      
      string to_string(); // get string representation
      
      void add(BigInt b); // add another BigInt to this one
   

   private:
   		vector<int> digits;
   		int base;
};

#endif
