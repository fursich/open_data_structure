#include <iostream>
#include "SEList.h"

using namespace std;
using namespace data_structure;

int main()
{
  SEList<int> a(3);

  a.add(0, 100);
  a.print_all();
  a.add(1, 123);
  a.print_all();
  a.add(2, 12);
  a.add(3, -1000);
  a.print_all();
  a.add(4, -2000);
  a.add(5, -3000);
  a.print_all();
  a.remove(0);
  a.print_all();
  a.remove(0);
  a.print_all();
  a.remove(0);
  a.print_all();

  a.add(0,10000);
  a.print_all();
  a.remove(0);
  a.print_all();
  a.add(0,-888888);
  a.print_all();
  a.remove(0);
  a.print_all();

  a.add(3, 444);
  a.print_all();
  a.remove(2);
  a.print_all();
  a.add(2, 333);
  a.print_all();
  a.remove(1);
  a.print_all();
}
