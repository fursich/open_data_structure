#ifndef ROOTISH_ARRAY_DEQUE_H_
#define ROOTISH_ARRAY_DEQUE_H_

#include <iostream>
#include <math.h>
#include "ArrayStack.h"
#include "BDeque.h"

using namespace std;

namespace data_structure {

  template <class T>
  class RootishArrayDeque {
  protected:
    ArrayStack<BDeque<T>*> blocks;
    int n;

    int i2b(int i);
    void grow();
    void shrink();
  public:
    RootishArrayDeque<T>();
    virtual ~RootishArrayDeque();
    int size();
    T get(int i);
    T set(int i, T x);

    virtual void add(int i, T x);
    virtual T remove(int i);
    virtual void clear();
    void print_all();
  };

  template <class T> inline
  int RootishArrayDeque<T>::size() {
    return n;
  }

  template <class T> inline
  T RootishArrayDeque<T>::get(int i) {
    int b = i2b(i);
    int j = i - b*(b+1)/2;
    return blocks.get(b)->get(j);
  }

  template <class T> inline
  T RootishArrayDeque<T>::set(int i, T x) {
    int b = i2b(i);
    int j = i - b*(b+1)/2;
    T y = blocks.get(b)->get(j);
    blocks.get(b)->set(j, x);
    return y;
  }

  template <class T> inline
  int RootishArrayDeque<T>::i2b(int i) {
    double db = (-3.0 + sqrt(9 + 8*i)) / 2.0;
    int b = (int)ceil(db);
    return b;
  }

  template <class T>
  RootishArrayDeque<T>::RootishArrayDeque() {
    n = 0;
  }

  template <class T>
  RootishArrayDeque<T>::~RootishArrayDeque() {
  }

  template <class T>
  void RootishArrayDeque<T>::add(int i, T x) {
    int r = blocks.size();
    if (r*(r+1)/2 < n+1) grow();
    n++;

    int b = i2b(i);
    int b0 = blocks.size() - 1;

    if (b < b0) {
      T y = blocks.get(b)->pop();
      for (int k=b+1; k<=b0; k++) {
        y = blocks.get(k)->unshift_rotate(y);
      }
    }

    int j = i - b*(b+1)/2;
    blocks.get(b)->add(j, x);
  }

  template <class T>
  T RootishArrayDeque<T>::remove(int i) {
    int r = blocks.size();
    int b = i2b(i);
    int b0 = blocks.size() - 1;

    int j = i - b*(b+1)/2;
    T x = blocks.get(b)->remove(j);

    if (b < b0) {
      T y = blocks.get(b0)->shift();
      for (int k=b0-1; k>=b; k--) {
        y = blocks.get(k)->push_rotate(y);
      }
    }

    n--;
    if ((r-1)*(r-2)/2 >= n) shrink(); 
    return x;
  }

  template<class T>
  void RootishArrayDeque<T>::grow() {
    blocks.add(blocks.size(), new BDeque<T>(blocks.size() + 1));
  }

  template<class T>
  void RootishArrayDeque<T>::shrink() {
    int r = blocks.size();
    while (r > 0 && (r-2)*(r-1)/2 >= n) {
      delete blocks.remove(blocks.size()-1);
      r--;
    }
  }

  template <class T>
  void RootishArrayDeque<T>::clear() {
    while(blocks.size() > 0) {
      delete blocks.remove(blocks.size()-1);
    }
  }

  template <class T> inline
  void RootishArrayDeque<T>::print_all() {
    cout << size() << " : ";
    for (int i=0; i<size(); i++)
      cout << get(i) << ", ";
    cout << endl;
  }
}
#endif
