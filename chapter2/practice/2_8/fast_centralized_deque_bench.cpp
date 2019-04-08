#include <iostream>
#include <random>
#include <chrono>

#include "FastCentralizedArrayDeque.h"
#include "../2_6/FastArrayDeque.h"

using namespace std;
using namespace data_structure;

void make_rands(int* arr, int max)
{
  std::random_device rnd;

  for(int i=0; i<100000; i++) {
    arr[i] = rnd() % max;
  }
}

int main()
{
  FastArrayDeque<int> a;
  FastCentralizedArrayDeque<int> b;
  int rands[100000];
  int i0;

  make_rands(rands, 100);

  for (int i=0;i<100;i++) {
    a.add(0,100);
    b.add(0,100);
  }

  // bench a
  auto start = std::chrono::steady_clock::now(); // 計測開始時間

  for (int i=0;i<100000;i+=1) {
    a.add(a.size() - rands[i], i);
  }
  for (int i=0;i<100000;i+=1) {
    a.remove(a.size() - rands[i]);
  }

  auto end = std::chrono::steady_clock::now();  // 計測終了時間
  double elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << dec << fixed << "a time: " << elapsed1 << endl;

  // // bench b
  auto start2 = std::chrono::system_clock::now(); // 計測開始時間

  for (int i=0;i<100000;i+=1) {
    b.add(b.size() - rands[i], i);
  }
  for (int i=0;i<100000;i+=1) {
    b.remove(b.size() - rands[i]);
  }

  auto end2 = std::chrono::system_clock::now();  // 計測終了時間
  double elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2-start2).count();
  cout << dec << fixed << "b time: " << elapsed2 << endl;
}
