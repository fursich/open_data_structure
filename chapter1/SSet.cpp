
#include <iostream>
#include "SSet.h"

using namespace std;
using namespace data_structure;

int main() {
  SSet<double> set;
  double a = 123.35;
  double a2 = 123.35;
  double b = -1020.0;
  double c = 2.299;
  double d = 1.0345;

  cout << "-------" << endl;
  cout << set.size() << endl;
  cout << set.add(&a) << endl;
  cout << set.size() << endl;
  cout << "-------" << endl;
  cout << set.add(&a2) << endl;
  cout << set.size() << endl;
  cout << "-------" << endl;
  cout << set.add(&b) << endl;
  cout << set.add(&c) << endl;
  cout << set.size() << endl;
  cout << *set.find(&c) << endl;
  cout << *set.find(&d) << endl;
  cout << "-------" << endl;
  cout << *set.remove(&c) << endl;
  cout << set.size() << endl;
  cout << *set.find(&c) << endl;
  cout << *set.find(&d) << endl;
  cout << "-------" << endl;
  cout << *set.find(&a) << endl;
  cout << *set.remove(&a) << endl;
  cout << (set.find(&a) == nullptr) << endl;
  cout << "-------" << endl;

}