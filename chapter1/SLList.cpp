#include <iostream>
#include <string>
#include "SLList.h"

using namespace std;
using namespace data_structure;

int main() {
  SLList<string> list;

  cout << "-------" << endl;
  string a = "hello, goodbye", b = "and your bird can sing";
  list.add(0, &a);
  list.add(1, &b);
  list.print_list();

  cout << "-------" << endl;

  string x = "FOOOOOOooooo!", y = "barrrrrrr";
  cout << list.set(10, &x) << endl;
  cout << list.set(1, &x) << endl;
  list.print_list();

  cout << "-------" << endl;

  cout << list.add(0, &y) << endl;
  list.print_list();

  cout << "-------" << endl;

  string* pRemoved = list.remove(1);
  cout << *pRemoved << " has been removed!" << endl;
  list.print_list();
}

