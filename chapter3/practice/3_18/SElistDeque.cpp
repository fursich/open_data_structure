#include <iostream>
#include "SEListDeque.h"

using namespace std;
using namespace data_structure;

int main()
{
  SEListDeque<int> a;

  a.removeLast();
  a.removeFirst();
  a.print_all();

  a.addLast(111);
  a.print_all();

  a.addLast(123);
  a.print_all();

  a.addLast(99);
  a.print_all();

  a.addLast(1000);
  a.print_all();

  a.addLast(400);
  a.print_all();

  a.addFirst(222);
  a.print_all();

  a.addFirst(444);
  a.print_all();

  a.addFirst(1234);
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();


  a.addLast(300);
  a.print_all();

  a.addLast(333);
  a.print_all();

  a.addLast(880);
  a.print_all();

  a.addLast(-400);
  a.print_all();


  a.addLast(300);
  a.print_all();

  a.addLast(333);
  a.print_all();

  a.addLast(880);
  a.print_all();

  a.addLast(-400);
  a.print_all();



  a.removeFirst();
  a.print_all();

  a.removeFirst();
  a.print_all();

  a.removeFirst();
  a.print_all();

  a.removeFirst();
  a.print_all();

  a.removeLast();
  a.print_all();

  a.addFirst(100);
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeFirst();
  a.print_all();



  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();


  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();



  a.addFirst(444);
  a.print_all();

  a.addFirst(1234);
  a.print_all();

  a.removeLast();
  a.print_all();

  a.removeLast();
  a.print_all();

  a.addLast(11);
  a.print_all();

  a.addLast(300);
  a.print_all();

  a.addLast(333);
  a.print_all();

  a.addLast(880);
  a.print_all();


  a.removeFirst();
  a.print_all();

  a.removeFirst();
  a.print_all();

  a.removeFirst();
  a.print_all();

  a.removeFirst();
  a.print_all();

}
