#include <iostream>
#include <random>
#include <chrono>

#include "RootishArrayStack.h"

using namespace std;
using namespace data_structure;

void make_rands(int* arr)
{
  std::random_device rnd;

  for(int i=0; i<100000; i++) {
    arr[i] = rnd();
    if (arr[i] < 0) arr[i] = -arr[i];
  }
}

void bench(RootishArrayStack<int>* a, int t)
{
  // bench
  int testable_idx = t/2;
  auto start = std::chrono::steady_clock::now(); // 計測開始時間

  for (int i=1;i<=t;i++) {
    a->add(testable_idx, i);
    a->remove(testable_idx);
  }

  auto end = std::chrono::steady_clock::now();  // 計測終了時間
  double elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << fixed << "count: " << t << ", time: " << elapsed1 << ", time/ins: " << elapsed1/t << endl;
}

int main()
{
  for (int t=10; t<=10000; t*=10) {
    auto tmp = new RootishArrayStack<int>;
    for (int i=0;i<t;i++) {
      tmp->add(0,i);
    }
    bench(tmp,t);
    delete tmp;
  }
}


