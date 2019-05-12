#ifndef CENTRALIZED_ARRAY_DEQUE_H_
#define CENTRALIZED_ARRAY_DEQUE_H_

#include <iostream>
#include "array.h"

using namespace std;

namespace data_structure {
  template <class T>
  class CentralizedArrayDeque {
  protected:
    array<T> a;
    int j;
    int n;
    virtual void rebuild();
  public:
    CentralizedArrayDeque<T>();
    virtual ~CentralizedArrayDeque();
    virtual void add(int i, T x);
    virtual T remove(int i);
    int size();
    T get(int i);
    T set(int i, T x);
    virtual void clear();
    void print_all();
  };

  template <class T>
  CentralizedArrayDeque<T>::CentralizedArrayDeque() : a(1) {
    j = 0;
    n = 0;
  }

  template <class T>
  CentralizedArrayDeque<T>::~CentralizedArrayDeque() {
  }

  template <class T>
  int CentralizedArrayDeque<T>::size() {
    return n;
  }

  template <class T> inline
  T CentralizedArrayDeque<T>::get(int i) {
    return a[j + i];
  }

  template <class T> inline
  T CentralizedArrayDeque<T>::set(int i, T x) {
    T y = a[j + i];
    a[j + i] = x;
    return y;
  }

  template <class T>
  void CentralizedArrayDeque<T>::add(int i, T x) {
    if (i < n/2) {
      if (j == 0) rebuild();
      j = j - 1;
      for (int k = 0; k <= i - 1; k++)
        a[j + k] = a[j + k + 1];
    } else {
      if (j + n >= a.length) rebuild();
      for (int k = n; k > i; k--)
        a[j + k] = a[j + k - 1];
    }
    a[j + i] = x;
    n++;
  }

  template <class T>
  T CentralizedArrayDeque<T>::remove(int i) {
    T x = a[j + i];
    if (i < n/2) {
      for (int k = i; k > 0; k--)
        a[j + k] = a[j + k - 1];
      j = j + 1;
    } else {
      for (int k = i; k < n - 1; k++)
        a[j + k] = a[j + k + 1];
    }

    n--;
    if (3 * n <= a.length) rebuild();
    return x;
  }

  template<class T>
  void CentralizedArrayDeque<T>::rebuild() {
    array<T> b(max(2 * n, 1));
    int j2 = (b.length - n) / 2;

    for (int k = 0; k < n; k++)
      b[j2 + k] = a[j + k];
    a = b;
    j = j2;
  }

  template <class T>
  void CentralizedArrayDeque<T>::clear() {
    n = 0;
    array<T> b(1);
    a = b;
  }

  template <class T> inline
  void CentralizedArrayDeque<T>::print_all() {
    cout << size() << " : ";
    for (int k = j; k < j + n; k++)
      cout << a[k] << ", ";
    cout << endl;
  }
}
#endif
