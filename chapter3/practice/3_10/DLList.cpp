#include <iostream>
#include "DLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  DLList<int> a;
  DLList<int> b;

  a.add(100);
  a.add(123);
  a.add(12);
  a.add(-1000);
  a.print_all();

  b.add(-2000);
  b.add(-3000);
  b.add(-700);
  b.add(-321);
  b.print_all();

  a.absorb(&b);
  a.print_all();
  b.print_all();

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


  b.add(100);
  b.add(123);
  b.add(12);
  b.add(-1000);
  b.add(-2000);
  b.add(-3000);
  b.add(-700);
  b.add(-321);
  b.print_all();

  b.absorb(&a);
  a.print_all();
  b.print_all();

  b.absorb(&b);
  b.print_all();
}
