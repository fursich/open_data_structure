#include <iostream>
#include "MinQueue.h"

using namespace std;
using namespace data_structure;

int main()
{
  MinQueue<int> a;

  a.remove();
  a.print_all();
  a.print_min();

  a.add(11111);
  a.print_all();
  a.print_min();

  a.add(5432);
  a.print_all();
  a.print_min();

  a.add(13000);
  a.print_all();
  a.print_min();

  a.add(-555);
  a.print_all();
  a.print_min();

  a.add(-555);
  a.print_all();
  a.print_min();

  a.add(10000000);
  a.print_all();
  a.print_min();

  a.add(100000);
  a.print_all();
  a.print_min();

  a.add(-5);
  a.print_all();
  a.print_min();

  a.add(100000);
  a.print_all();
  a.print_min();

  a.add(300000);
  a.print_all();
  a.print_min();

  a.add(200000);
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.add(555);
  a.print_all();
  a.print_min();

  a.add(990000);
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.add(11111);
  a.print_all();
  a.print_min();

  a.add(5432);
  a.print_all();
  a.print_min();

  a.add(13000);
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();

  a.remove();
  a.print_all();
  a.print_min();
}
