
#include <iostream>
#include "array.h"

using namespace std;
using namespace data_structure;

int main() {
  array<int> a(2), b(3);

  a[1] = 1;
  a[0] = 0;

  b[0] = 100;
  b[1] = 123;
  b[2] = -321;

  cout << a.length << " : "  << a[0] << ", " << a[1] << endl;
  a = b;
  cout << a.length << " : "  << a[0] << ", " << a[1] << endl;
}
