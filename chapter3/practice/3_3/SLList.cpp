#include <iostream>
#include "SLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  SLList<int> a;

  a.add(100);
  a.print_all();
  a.add(123);
  a.print_all();
  a.add(12);
  a.print_all();
  a.add(-1000);
  a.print_all();
  a.add(-2000);
  a.print_all();

  a.set(1,1000000);
  a.print_all();
  a.set(3,-1000000);
  a.print_all();
  cout << a.get(4) << endl;


  a.add(-3000);
  a.print_all();

  a.remove();
  a.print_all();
  a.remove();
  a.print_all();
  a.remove();
  a.print_all();


  // a.push(10000);
  // a.print_all();
  // a.pop();
  // a.print_all();
  // a.push(-888888);
  // a.print_all();
  // a.pop();
  // a.print_all();

}
