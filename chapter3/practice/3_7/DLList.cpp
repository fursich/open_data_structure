#include <iostream>
#include "DLList.h"

using namespace std;
using namespace data_structure;

int main()
{
  DLList<int> a;

  cout << a.isPalindrome() << endl;

  a.add(100);
  cout << a.isPalindrome() << endl;
  a.print_all();

  a.add(123);
  cout << a.isPalindrome() << endl;
  a.print_all();

  a.add(100);
  cout << a.isPalindrome() << endl;
  a.print_all();

  a.add(-1000);
  cout << a.isPalindrome() << endl;
  a.print_all();


  a.add(-2000);
  a.add(-3000);
  a.print_all();

  a.add(0,-1000);
  a.add(0,-2000);
  a.add(0,-3000);
  cout << a.isPalindrome() << endl;
  a.print_all();


  a.remove(0);
  cout << a.isPalindrome() << endl;
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

  a.add(3, 444);
  a.print_all();
  a.remove(2);
  a.print_all();
  a.add(2, 333);
  a.print_all();
  a.remove(1);
  cout << a.isPalindrome() << endl;
  a.print_all();
}
