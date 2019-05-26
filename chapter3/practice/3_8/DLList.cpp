#include <iostream>
#include "DLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  DLList<int> a;

  a.add(100);
  // a.rotate(1);
  a.print_all();

  a.print_all();
  a.add(123);
  a.print_all();
  a.rotate(1);
  a.print_all();
  a.rotate(1);
  a.print_all();
  a.rotate(1);
  a.print_all();

  a.add(12);
  a.add(-1000);
  a.print_all();
  a.add(-2000);
  a.add(-3000);
  a.print_all();

  a.rotate(2);
  a.print_all();
  a.rotate(1);
  a.print_all();
  a.rotate(10);
  a.print_all();

  // a.remove(0);
  // a.print_all();
  // a.remove(0);
  // a.print_all();
  // a.remove(0);
  // a.print_all();

  // a.add(0,10000);
  // a.print_all();
  // a.remove(0);
  // a.print_all();
  // a.add(0,-888888);
  // a.print_all();
  // a.remove(0);
  // a.print_all();

  // a.add(3, 444);
  // a.print_all();
  // a.remove(2);
  // a.print_all();
  // a.add(2, 333);
  // a.print_all();
  // a.remove(1);
  // a.print_all();
}
