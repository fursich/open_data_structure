#include <iostream>
#include "DLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  DLList<int> a;
  DLList<int> b;

  DLList<int>* p;

  a.add(500);
  a.add(1023);
  a.print_all();

  b.add(-700);
  b.add(-321);
  b.print_all();

  b.takeFirst(&a);
  a.print_all();
  b.print_all();

  b.takeFirst(&a);
  a.print_all();
  b.print_all();

  b.takeFirst(&a);
  a.print_all();
  b.print_all();

  a.takeFirst(&a);
  a.print_all();
  b.print_all();

  a.takeFirst(&b);
  a.print_all();
  b.print_all();

  b.add(5000);
  b.add(10321);
  b.add(13000);
  b.add(19000);
  b.print_all();

  a.add(5000);
  a.add(9555);
  a.add(15000);
  a.add(99555);
  a.add(990000);
  a.add(1000000);
  a.add(10000000);
  a.print_all();

  p = DLList<int>::merge(&a,&b);
  a.print_all();
  b.print_all();
  p->print_all();

  // a.add(400);
  // a.add(423);
  // a.add(42);
  // a.add(-41000);
  // a.print_all();
  // a.reverse();
  // a.print_all();

  // a.add(600);
  // a.add(623);
  // a.add(72);
  // a.add(-71000);
  // a.print_all();

  // a.reverse();
  // a.print_all();
}
