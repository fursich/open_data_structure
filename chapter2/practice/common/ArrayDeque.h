#ifndef ARRAY_DEQUE_H_
#define ARRAY_DEQUE_H_

#include <iostream>
#include "array.h"

using namespace std;

namespace data_structure {
  template <class T>
  class ArrayDeque {
  protected:
    array<T> a;
    int j;
    int n;
    virtual void resize();
  public:
    ArrayDeque<T>();
    virtual ~ArrayDeque();
    virtual void add(int i, T x);
    virtual T remove(int i);
    virtual int size();
    virtual T get(int i);
    virtual T set(int i, T x);
    virtual void clear();
    void print_all();
  };

  template <class T>
  ArrayDeque<T>::ArrayDeque() : a(1) {
    j = 0;
    n = 0;
  }

  template <class T>
  ArrayDeque<T>::~ArrayDeque() {
  }

  template <class T>
  int ArrayDeque<T>::size() {
    return n;
  }

  template <class T> inline
  T ArrayDeque<T>::get(int i) {
    return a[(j + i) % a.length];
  }

  template <class T> inline
  T ArrayDeque<T>::set(int i, T x) {
    T y = a[(j + i) % a.length];
    a[j + i] = x;
    return y;
  }

  template <class T>
  void ArrayDeque<T>::add(int i, T x) {
    if (n + 1 > a.length) resize();

    if (2 * i < n) {
      j = (j == 0) ? a.length - 1 : j - 1;
      for (int k = 0; k <= i - 1; k++)
        a[(j + k) % a.length] = a[(j + k + 1) % a.length];
    } else {
      for (int k = n; k > i; k--)
        a[(j + k) % a.length] = a[(j + k - 1) % a.length];
    }
    a[(j + i) % a.length] = x;
    n++;
  }

  template <class T>
  T ArrayDeque<T>::remove(int i) {
    T x = a[(j + i) % a.length];
    if (2 * i < n) {
      for (int k = i; k > 0; k--)
        a[(j + k) % a.length] = a[(j + k - 1) % a.length];
      j = (j + 1) % a.length;
    } else {
      for (int k = i; k < n - 1; k++)
        a[(j + k) % a.length] = a[(j + k + 1) % a.length];
    }

    n--;
    if (3 * n <= a.length) resize();
    return x;
  }

  template<class T>
  void ArrayDeque<T>::resize() {
    array<T> b(max(2 * n, 1));
    for (int k = 0; k < n; k++)
      b[k] = a[(j + k) % a.length];
    a = b;
    j = 0;
  }

  template <class T>
  void ArrayDeque<T>::clear() {
    n = 0;
    array<T> b(1);
    a = b;
  }

  template <class T> inline
  void ArrayDeque<T>::print_all() {
    cout << size() << " : ";
    for (int k = j; k < j + n; k++)
      cout << a[k % a.length] << ", ";
    cout << endl;
  }
}
#endif
