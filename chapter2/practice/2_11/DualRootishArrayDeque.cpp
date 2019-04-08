#include <iostream>
#include "DualRootishArrayDeque.h"

using namespace std;
using namespace data_structure;

int main()
{
  DualRootishArrayDeque<int> a;

  a.add(0,100);
  a.print_all();
  a.add(0,123);
  a.print_all();
  a.add(0,321);
  a.print_all();
  a.add(1,-4431);
  a.print_all();
  a.add(2,-99999);
  a.print_all();
  a.add(2,12);
  a.add(0,-1000);
  a.print_all();

  a.add(4,-2000);
  a.add(3,-3000);
  a.print_all();

  a.remove(1);
  a.print_all();

  a.remove(2);
  a.print_all();
}
