#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include <iostream>
#include "array.h"

using namespace std;

namespace data_structure {
  template <class T>
  class ArrayQueue {
  protected:
    array<T> a;
    int j;
    int n;
    virtual void resize();
  public:
    ArrayQueue<T>();
    virtual ~ArrayQueue();
    virtual bool add(T x);
    virtual T remove();
    int size();
    virtual void clear();
    void print_all();
  };

  template <class T>
  ArrayQueue<T>::ArrayQueue() : a(1) {
    n = 0;
  }

  template <class T>
  ArrayQueue<T>::~ArrayQueue() {
  }

  template <class T>
  int ArrayQueue<T>::size() {
    return n;
  }

  template <class T>
  bool ArrayQueue<T>::add(T x) {
    if (n + 1 > a.length) resize();
    a[(j + n) % a.length] = x;
    n++;
    return true;
  }

  template <class T>
  T ArrayQueue<T>::remove() {
    T x = a[j];
    j = (j + 1) % a.length;
    n--;
    if (3 * n <= a.length) resize();
    return x;
  }

  template<class T>
  void ArrayQueue<T>::resize() {
    array<T> b(max(2 * n, 1));
    for (int k = 0; k < n; k++)
      b[k] = a[(j + k) % a.length];
    a = b;
    j = 0;
  }

  template <class T>
  void ArrayQueue<T>::clear() {
    n = 0;
    array<T> b(1);
    a = b;
  }

  template <class T> inline
  void ArrayQueue<T>::print_all() {
    cout << size() << " : ";
    for (int k = j; k < j + n; k++)
      cout << a[k % a.length] << ", ";
    cout << endl;
  }
}
#endif
