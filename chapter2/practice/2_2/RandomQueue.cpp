#include <iostream>
#include "RandomQueue.h"

using namespace std;
using namespace data_structure;

int main()
{
  RandomQueue<int> a;

  a.append(-120);
  a.append(1022);
  a.append(10123);
  a.append(4);
  a.append(5124);
  cout << a.take() << endl;
  cout << a.take() << endl;
  cout << a.take() << endl;
  cout << a.take() << endl;
  a.append(123);
  a.append(98765);
  cout << a.take() << endl;
}
