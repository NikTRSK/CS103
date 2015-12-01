#include "bigint.h"
#include <iostream>
using namespace std;

int main() {
   BigInt a("13");
   BigInt b("42");
   cout << b.digits[1];
}
