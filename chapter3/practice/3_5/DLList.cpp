#include <iostream>
#include "DLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  DLList<int> a;

  a.print_all();
  a.checkSize();

  a.add(100);
  a.print_all();
  a.checkSize();

  a.add(123);
  a.print_all();
  a.checkSize();

  a.add(12);
  a.add(-1000);
  a.print_all();
  a.checkSize();

  a.add(-2000);
  a.add(-3000);
  a.print_all();
  a.checkSize();
  
  a.remove(0);
  a.print_all();
  a.checkSize();

  a.remove(0);
  a.print_all();
  a.checkSize();

  a.remove(0);
  a.print_all();
  a.checkSize();

  a.add(0,10000);
  a.print_all();
  a.remove(0);
  a.print_all();
  a.add(0,-888888);
  a.print_all();
  a.remove(0);
  a.print_all();
  a.checkSize();

  a.add(3, 444);
  a.print_all();
  a.remove(2);
  a.print_all();
  a.add(2, 333);
  a.print_all();
  a.remove(1);
  a.print_all();

  a.remove(1);
  a.print_all();
  a.checkSize();

  a.remove(0);
  a.print_all();
  a.checkSize();

  a.remove(0);
  a.print_all();
  a.checkSize();

}
