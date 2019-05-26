#include <iostream>
#include "SLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  SLList<int> a;

  a.reverse();
  a.print_all();

  a.add(100);
  a.print_all();
  a.reverse();
  a.print_all();

  a.add(123);
  a.print_all();
  a.reverse();
  a.print_all();

  a.add(12);
  a.print_all();
  a.reverse();
  a.print_all();

  a.add(-1000);
  a.print_all();
  a.reverse();
  a.print_all();

  a.add(-2000);
  a.print_all();
  a.reverse();
  a.print_all();

  a.add(-3000);
  a.print_all();
  a.reverse();
  a.print_all();

  a.remove();
  a.print_all();
  a.reverse();
  a.print_all();

  a.remove();
  a.print_all();
  a.reverse();
  a.print_all();

  a.remove();
  a.print_all();
  a.reverse();
  a.print_all();


  a.push(10000);
  a.push(-888888);
  a.print_all();
  a.pop();
  a.pop();
  a.print_all();
  a.pop();
  a.pop();
  a.print_all();
  a.pop();
  a.print_all();

}
