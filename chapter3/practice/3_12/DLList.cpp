#include <iostream>
#include "DLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  DLList<int> a;

  a.print_all();
  a.reverse();
  a.print_all();

  a.add(100);
  a.print_all();
  a.reverse();
  a.print_all();

  a.add(123);
  a.add(12);
  a.add(-1000);
  a.print_all();
  a.reverse();
  a.print_all();

  a.add(400);
  a.add(423);
  a.add(42);
  a.add(-41000);
  a.print_all();
  a.reverse();
  a.print_all();

  a.add(600);
  a.add(623);
  a.add(72);
  a.add(-71000);
  a.print_all();

  a.reverse();
  a.print_all();
}
