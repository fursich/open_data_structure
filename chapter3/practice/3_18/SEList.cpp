#include <iostream>
#include "SEList.h"

using namespace std;
using namespace data_structure;

int main()
{
  SEList<int> a;
  SEList<int>* b;

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

  cout << "truncated.." << endl;
  b = a.truncate(3);
  a.print_all();
  b->print_all();

  a.push(-2000);
  a.push(-3000);
  a.print_all();
  b->print_all();

  cout << "truncated.." << endl;
  b = a.truncate(3);
  a.print_all();
  b->print_all();

  cout << "reversing.." << endl;
  b = SEList<int>::reverse(b);
  b->print_all();


  b->push(-200);
  b->push(5000);
  b->print_all();

  b->pop();
  a.print_all();
  b->print_all();

  cout << "absorbing.." << endl;
  a.absorb(b);
  a.print_all();
  b->print_all();

  cout << "truncated.." << endl;
  b = a.truncate(1);
  a.print_all();
  b->print_all();

  cout << "reversing.." << endl;
  b = SEList<int>::reverse(b);
  b->print_all();

  cout << "absorbing.." << endl;
  a.absorb(b);
  a.print_all();
  b->print_all();

  cout << "absorbing.." << endl;
  a.absorb(b);
  a.print_all();
  b->print_all();

  cout << "reversing.." << endl;
  b = SEList<int>::reverse(b);
  b->print_all();

  a.push(-2000);
  a.push(-3000);
  a.print_all();

  cout << "reversing.." << endl;
  b = SEList<int>::reverse(&a);
  b->print_all();

  a.push(15000);
  a.push(50);
  a.push(2340);
  a.print_all();
  b->print_all();

  a.push(2);
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

  a.add(1, 444);
  a.add(1, 321);
  a.print_all();
  a.remove(2);
  a.print_all();
  a.add(1, 333);
  a.remove(0);
  a.print_all();
  a.remove(1);
  a.print_all();
}
