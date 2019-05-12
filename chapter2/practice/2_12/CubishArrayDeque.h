#ifndef CUBISH_ARRAY_DEQUE_H_
#define CUBISH_ARRAY_DEQUE_H_

#include <iostream>
#include <math.h>
#include "ArrayStack.h"
#include "BDeque.h"

using namespace std;

namespace data_structure {

  template <class T>
  class CubishArrayDeque {
  protected:
    ArrayStack<BDeque<T>*> blocks;
    int n;

    int i2b(int i);
    int accumulated_size(int b);
    void grow();
    void shrink();
  public:
    CubishArrayDeque<T>();
    virtual ~CubishArrayDeque();
    int size();
    T get(int i);
    T set(int i, T x);

    virtual void add(int i, T x);
    virtual T remove(int i);
    virtual void clear();
    void print_all();
  };

  template <class T> inline
  int CubishArrayDeque<T>::size() {
    return n;
  }

  template <class T> inline
  T CubishArrayDeque<T>::get(int i) {
    int b = i2b(i);
    int j = i - accumulated_size(b);
    return blocks.get(b)->get(j);
  }

  template <class T> inline
  T CubishArrayDeque<T>::set(int i, T x) {
    int b = i2b(i);
    int j = i - accumulated_size(b);
    T y = blocks.get(b)->get(j);
    blocks.get(b)->set(j, x);
    return y;
  }

  template <class T> inline
  int CubishArrayDeque<T>::i2b(int i) {
    double factor = sqrt( (9.0*(i+1.0)*(i+1.0))/4 - 1.0/1728 );
    double first  = cbrt( 3*(i+1.0)/2 + factor );
    double second = cbrt( 3*(i+1.0)/2 - factor );
    double third  = -3.0/2;

    int b = (int)ceil( first + second + third );
    return b;
  }

  template <class T> inline
  int CubishArrayDeque<T>::accumulated_size(int b) {
    int size = (int) (b * (b+1.0) * (2.0*b+1) / 6.0);
    return size;
  }

  template <class T>
  CubishArrayDeque<T>::CubishArrayDeque() {
    n = 0;
  }

  template <class T>
  CubishArrayDeque<T>::~CubishArrayDeque() {
  }

  template <class T>
  void CubishArrayDeque<T>::add(int i, T x) {
    int r = blocks.size();
    if (accumulated_size(r) < n+1) grow();
    n++;

    int b = i2b(i);
    int b0 = blocks.size() - 1;

    if (b < b0) {
      T y = blocks.get(b)->pop();
      for (int k=b+1; k<=b0; k++) {
        y = blocks.get(k)->unshift_rotate(y);
      }
    }

    int j = i - accumulated_size(b);
    blocks.get(b)->add(j, x);
  }

  template <class T>
  T CubishArrayDeque<T>::remove(int i) {
    int r = blocks.size();
    int b = i2b(i);
    int b0 = blocks.size() - 1;

    int j = i - accumulated_size(b);
    T x = blocks.get(b)->remove(j);

    if (b < b0) {
      T y = blocks.get(b0)->shift();
      for (int k=b0-1; k>=b; k--) {
        y = blocks.get(k)->push_rotate(y);
      }
    }

    n--;
    if (accumulated_size(r-2) >= n) shrink(); 
    return x;
  }

  template<class T>
  void CubishArrayDeque<T>::grow() {
    blocks.add(blocks.size(), new BDeque<T>( (blocks.size() + 1) * (blocks.size() + 1) ));
  }

  template<class T>
  void CubishArrayDeque<T>::shrink() {
    int r = blocks.size();
    while (r > 0 && accumulated_size(r-2) >= n) {
      delete blocks.remove(blocks.size()-1);
      r--;
    }
  }

  template <class T>
  void CubishArrayDeque<T>::clear() {
    while(blocks.size() > 0) {
      delete blocks.remove(blocks.size()-1);
    }
  }

  template <class T> inline
  void CubishArrayDeque<T>::print_all() {
    cout << size() << " : ";
    for (int i=0; i<size(); i++)
      cout << get(i) << ", ";
    cout << endl;
  }
}
#endif
