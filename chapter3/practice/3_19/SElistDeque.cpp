#include <iostream>
#include <assert.h>
#include <random>

using namespace std;

int main()
{
  int s = 121324, t=-90343;
  random_device rnd;

  for (int i=0;i<100;i++) {
    s = rnd();
    t = rnd();
    int s0=s, t0=t;

    cout << "s: " << s << ", t: " << t << endl;

    s ^=t;
    t ^= s;
    s ^=t;

    cout << "s: " << s << ", t: " << t << endl;

    assert(s==t0 && t==s0);
  }
}
