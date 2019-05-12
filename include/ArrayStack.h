#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_

#include <algorithm>
#include "array.h"

using namespace std;

namespace data_structure {
  template <class T>
    class DualArrayDeque;

  template <class T>
  class ArrayStack {
  protected:
    friend class DualArrayDeque<T>;
    array<T> a;
    int n;
    virtual void resize();
  public:
    ArrayStack<T>();
    virtual ~ArrayStack();
    int size();
    T get(int i);
    T set(int i, T x);
    virtual void add(int i, T x);
    virtual T remove(int i);
    virtual void clear();
  };

  template <class T>
  ArrayStack<T>::ArrayStack() : a(1) {
    n = 0;
  }

  template <class T>
  ArrayStack<T>::~ArrayStack() {
  }

  template <class T>
  int ArrayStack<T>::size() {
    return n;
  }

  template <class T>
  void ArrayStack<T>::add(int i, T x) {
    if (n + 1 > a.length) resize();
    for (int j = n; j > i; j--)
      a[j] = a[j - 1];
    a[i] = x;
    n++;
  }

  template <class T>
  T ArrayStack<T>::remove(int i) {
    T x = a[i];
    for (int j = i; j < n - 1; j++)
      a[j] = a[j+1];
    n--;
    if (3 * n <= a.length) resize();
    return x;
  }

  template<class T>
  void ArrayStack<T>::resize() {
    array<T> b(max(2 * n, 1));
    for (int i = 0; i < n; i++)
      b[i] = a[i];
    a = b;
  }

  template <class T> inline
  void ArrayStack<T>::clear() {
    n = 0;
    array<T> b(1);
    a = b;
  }

  template <class T> inline
  T ArrayStack<T>::get(int i) {
    return a[i];
  }

  template <class T> inline
  T ArrayStack<T>::set(int i, T x) {
    T y = a[i];
    a[i] = x;
    return y;
  }
}
#endif
