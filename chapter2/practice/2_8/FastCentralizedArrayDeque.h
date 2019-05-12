#ifndef FIRST_CENTRALIZED_ARRAY_DEQUE_H_
#define FIRST_CENTRALIZED_ARRAY_DEQUE_H_

#include <iostream>
#include "array.h"

using namespace std;

namespace data_structure {
  template <class T>
  class FastCentralizedArrayDeque {
  protected:
    array<T> a;
    int j;
    int n;
    virtual void rebuild();
  public:
    FastCentralizedArrayDeque<T>();
    virtual ~FastCentralizedArrayDeque();
    virtual void add(int i, T x);
    virtual T remove(int i);
    int size();
    T get(int i);
    T set(int i, T x);
    virtual void clear();
    void print_all();
  };

  template <class T>
  FastCentralizedArrayDeque<T>::FastCentralizedArrayDeque() : a(1) {
    j = 0;
    n = 0;
  }

  template <class T>
  FastCentralizedArrayDeque<T>::~FastCentralizedArrayDeque() {
  }

  template <class T>
  int FastCentralizedArrayDeque<T>::size() {
    return n;
  }

  template <class T> inline
  T FastCentralizedArrayDeque<T>::get(int i) {
    return a[j + i];
  }

  template <class T> inline
  T FastCentralizedArrayDeque<T>::set(int i, T x) {
    T y = a[j + i];
    a[j + i] = x;
    return y;
  }

  template <class T>
  void FastCentralizedArrayDeque<T>::add(int i, T x) {
    if (i < n/2) {
      if (j == 0) rebuild();
      copy(a+j, a+j+i, a+j-1);
      j = j - 1;
    } else {
      if (j + n >= a.length) rebuild();
      copy_backward(a+j+i, a+j+n, a+j+n+1);
    }
    a[j + i] = x;
    n++;
  }

  template <class T>
  T FastCentralizedArrayDeque<T>::remove(int i) {
    T x = a[j + i];
    if (i < n/2) {
      copy_backward(a+j, a+j+i, a+j+i+1);
      j = j + 1;
    } else {
      copy(a+j+i, a+j+n, a+j+i-1);
    }

    n--;
    if (3 * n <= a.length) rebuild();
    return x;
  }

  template<class T>
  void FastCentralizedArrayDeque<T>::rebuild() {
    array<T> b(max(2 * n, 1));

    int j2 = (b.length - n) / 2;
    copy(a+j, a+j+n, b+j2);

    a = b;
    j = j2;
  }

  template <class T>
  void FastCentralizedArrayDeque<T>::clear() {
    n = 0;
    array<T> b(1);
    a = b;
  }

  template <class T> inline
  void FastCentralizedArrayDeque<T>::print_all() {
    cout << size() << " : ";
    for (int k = j; k < j + n; k++)
      cout << a[k] << ", ";
    cout << endl;
  }
}
#endif
