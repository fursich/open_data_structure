#include <iostream>
#include "ArrayQueue.h"

using namespace std;
using namespace data_structure;

int main()
{
  ArrayQueue<int> a;

  a.add(100);
  a.print_all();
  a.add(123);
  a.add(-99999);
  a.add(-1000);
  a.print_all();
  a.remove();
  a.print_all();
}
