#ifndef FASTARRAY_DEQUE_H_
#define FASTARRAY_DEQUE_H_

#include <iostream>
#include <math.h>
#include "../common/array.h"

using namespace std;

namespace data_structure {
  template <class T>
  class FastArrayDeque {
  protected:
    array<T> a;
    int j;
    int n;
    virtual void resize();
    void fastcopy(int start, int len);
    void fastcopy_backward(int start, int len);
  public:
    FastArrayDeque<T>();
    virtual ~FastArrayDeque();
    virtual void add(int i, T x);
    virtual T remove(int i);
    int size();
    T get(int i);
    T set(int i, T x);
    virtual void clear();
    void print_all();
  };

  template <class T>
  FastArrayDeque<T>::FastArrayDeque() : a(1) {
    j = 0;
    n = 0;
  }

  template <class T>
  FastArrayDeque<T>::~FastArrayDeque() {
  }

  template <class T>
  int FastArrayDeque<T>::size() {
    return n;
  }

  template <class T> inline
  T FastArrayDeque<T>::get(int i) {
    return a[(j + i) % a.length];
  }

  template <class T> inline
  T FastArrayDeque<T>::set(int i, T x) {
    T y = a[(j + i) % a.length];
    a[j + i] = x;
    return y;
  }

  template <class T> inline
  void FastArrayDeque<T>::fastcopy(int start, int len) {
    int remaining = len;
    int copy_start = start;
    int copy_last;

    if (n==0) return; // do not copy at all!

    while (remaining > 0) {
      if (copy_start == 0) {
        a[a.length-1] = a[0];
        copy_start++;
        remaining--;
        continue;
      }

      copy_last = min(copy_start+remaining, a.length);
      copy(a+copy_start, a+copy_last, a+copy_start-1);

      copy_start = 0;
      remaining -= copy_last-copy_start;
    }
  }

  template <class T> inline
  void FastArrayDeque<T>::fastcopy_backward(int last, int len) {
    int remaining = len;
    int copy_last = last+1;
    int copy_start;

    if (n==0) return; // do not copy at all!

    while (remaining > 0) {
      if (copy_last == a.length) {
        a[0] = a[a.length-1];
        copy_last--;
        remaining--;
        continue;
      }

      copy_start = max(copy_last-remaining, 0);

      assert(copy_start >= 0 && copy_start < a.length);
      assert(copy_last > 0 && copy_start <= a.length);
      copy_backward(a+copy_start, a+copy_last, a+copy_last+1);
      copy_last = a.length;
      remaining -= copy_last-copy_start;
    }
  }

  template <class T>
  void FastArrayDeque<T>::add(int i, T x) {
    if (n + 1 > a.length) resize();

    if (2 * i < n) {
      fastcopy(j, i);
      j = (j == 0) ? a.length - 1 : j - 1;
    } else {
      fastcopy_backward((j+n-1) % a.length, n-i);
    }
    a[(j + i) % a.length] = x;
    n++;
  }

  template <class T>
  T FastArrayDeque<T>::remove(int i) {
    T x = a[(j + i) % a.length];
    if (2 * i < n) {
      fastcopy_backward((j+i-1) % a.length, i);
      j = (j + 1) % a.length;
    } else {
      fastcopy((j+i+1) % a.length, n-i-1);
    }
    n--;
    if (3 * n <= a.length) resize();
    return x;
  }

  template<class T>
  void FastArrayDeque<T>::resize() {
    array<T> b(max(2 * n, 1));
    int copy_last = min(j+n, a.length);

    copy(a+j, a+copy_last, b + 0);
    if (copy_last != j+n)
      copy(a+0, a+(j+n)%a.length, b+(copy_last-j));

    a = b;
    j = 0;
  }

  template <class T>
  void FastArrayDeque<T>::clear() {
    n = 0;
    array<T> b(1);
    a = b;
  }

  template <class T> inline
  void FastArrayDeque<T>::print_all() {
    cout << size() << " : ";
    for (int k = j; k < j + n; k++)
      cout << a[k % a.length] << ", ";
    cout << endl;
  }
}
#endif
