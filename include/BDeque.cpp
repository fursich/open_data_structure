#include "BDeque.h"

using namespace std;
using namespace data_structure;

int main()
{
  BDeque<int> a(10);

  a.add(0,100);
  a.print_all();
  a.add(0,123);
  a.print_all();
  a.add(0,321);
  a.add(1,-4431);
  a.add(2,-99999);
  a.print_all();
  a.add(2,12);
  a.add(0,-1000);
  a.print_all();
  a.add(4,-2000);
  a.add(3,-3000);
  a.print_all();
  a.remove(1);
  a.print_all();
  a.remove(2);
  a.print_all();

  BDeque<int> b(5);
  for (int i=0; i<5; i++) {
    b.add(i, i);
  }
  b.print_all();
  b.pop();
  b.push_rotate(1234);
  b.print_all();
  b.push_rotate(2345);
  b.print_all();
  b.unshift_rotate(3456);
  b.print_all();

  b.add(1,100); // invalid operation (must have fixed length)
}
