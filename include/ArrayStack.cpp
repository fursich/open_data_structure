#include <iostream>
#include "ArrayStack.h"

using namespace std;
using namespace data_structure;

int main()
{
  ArrayStack<int> a;

  a.add(0, 100);
  cout << a.size() << " : " << a.get(0) << endl;
  a.add(1,123);
  a.add(1,-1000);
  cout << a.size() << " : " << a.get(0) << ", " << a.get(1) << ", " << a.get(2) << endl;
  a.remove(0);
  cout << a.size() << " : " << a.get(0) << ", " << a.get(1) << endl;
}
