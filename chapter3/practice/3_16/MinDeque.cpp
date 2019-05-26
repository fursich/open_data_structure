#include <iostream>
#include "MinDeque.h"

using namespace std;
using namespace data_structure;

int main()
{
  MinDeque<int> a;

  a.removeLast();
  a.removeFirst();
  a.print_all();
  a.print_min();

  a.addLast(111);
  a.print_all();
  a.print_min();

  a.addLast(123);
  a.print_all();
  a.print_min();

  a.addLast(99);
  a.print_all();
  a.print_min();

  a.addLast(1000);
  a.print_all();
  a.print_min();

  a.addFirst(222);
  a.print_all();
  a.print_min();

  a.addFirst(444);
  a.print_all();
  a.print_min();

  a.addFirst(1234);
  a.print_all();
  a.print_min();

  a.removeLast();
  a.print_all();
  a.print_min();

  a.removeFirst();
  a.print_all();
  a.print_min();

  a.removeLast();
  a.print_all();
  a.print_min();

  a.addFirst(100);
  a.print_all();
  a.print_min();

  a.removeLast();
  a.print_all();
  a.print_min();

  a.removeLast();
  a.print_all();
  a.print_min();

  a.removeLast();
  a.print_all();
  a.print_min();

  a.removeLast();
  a.print_all();
  a.print_min();

  a.removeLast();
  a.print_all();
  a.print_min();

  a.removeFirst();
  a.print_all();
  a.print_min();


  a.addFirst(444);
  a.print_all();
  a.print_min();

  a.addFirst(1234);
  a.print_all();
  a.print_min();

  a.removeLast();
  a.print_all();
  a.print_min();

  a.addLast(11);
  a.print_all();
  a.print_min();


  // a.addFirst(22);
  // a.print_all();
  // a.print_min();

  // a.addFirst(3456);
  // a.print_all();
  // a.print_min();

  // a.addLast(-10);
  // a.print_all();
  // a.print_min();

  // a.removeLast();
  // a.print_all();
  // a.print_min();

  // a.removeFirst();
  // a.print_all();
  // a.print_min();

  // a.addFirst(22);
  // a.print_all();
  // a.print_min();

  // a.addLast(90);
  // a.print_all();
  // a.print_min();

  // a.removeLast();
  // a.print_all();
  // a.print_min();

  // a.removeFirst();
  // a.print_all();
  // a.print_min();

  // a.removeFirst();
  // a.print_all();
  // a.print_min();

  // a.removeLast();
  // a.print_all();
  // a.print_min();

  // a.removeFirst();
  // a.print_all();
  // a.print_min();

  // a.removeLast();
  // a.print_all();
  // a.print_min();

  // a.removeFirst();
  // a.print_all();
  // a.print_min();

  // a.addLast(-10);
  // a.print_all();
  // a.print_min();

  // a.removeLast();
  // a.print_all();
  // a.print_min();

}
