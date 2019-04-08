#include <iostream>
#include <string>
#include <climits>
#include "USet.h"

using namespace std;
using namespace data_structure;

int main() {
  USet<string> set;
  string a = "day tripper";
  string b = "day tripper";

  cout << sizeof(size_t) * CHAR_BIT << endl;
  cout << "-------" << endl;
  cout << set.size() << endl;
  cout << USet<string>::hashSize << "  " << USet<string>::bitmask << endl;
  cout << set.hash(&a) << endl;
  cout << set.add(&a) << endl;
  cout << *set.find(&b) << endl;
  cout << set.add(&b) << endl;
  cout << set.size() << endl;
  cout << *set.remove(&b) << endl;
  cout << set.size() << endl;

}