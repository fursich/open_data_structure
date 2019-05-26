#include <iostream>
#include "MinStack.h"

using namespace std;
using namespace data_structure;

int main()
{
  MinStack<int> a;

  a.pop();
  a.print_all();
  a.print_min();

  a.push(11111);
  a.print_all();
  a.print_min();

  a.push(5432);
  a.print_all();
  a.print_min();

  a.push(13000);
  a.print_all();
  a.print_min();

  a.push(5000);
  a.print_all();
  a.print_min();

  a.push(5000);
  a.print_all();
  a.print_min();

  a.push(10000000);
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.push(1023);
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.push(555);
  a.print_all();
  a.print_min();

  a.push(990000);
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();

  a.pop();
  a.print_all();
  a.print_min();
}
