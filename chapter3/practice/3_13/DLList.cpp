#include <iostream>
#include "DLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  DLList<int> a;
  DLList<int> b;

  DLList<int>* p;

  a.add(19000);
  a.add(-700);
  a.add(321);
  a.add(13000);
  a.add(-321);
  a.add(5000);
  a.print_all();

  a.add(5000);
  a.add(10000000);
  a.add(9555);
  a.add(1023);
  a.add(1000000);
  a.add(15000);
  a.add(555);
  a.add(990000);
  a.add(500);
  a.print_all();

  a.sort();
  a.print_all();
}
