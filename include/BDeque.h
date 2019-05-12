#ifndef ARRAY_BDEQUE_H_
#define ARRAY_BDEQUE_H_

#include <iostream>
#include "ArrayDeque.h"

using namespace std;

namespace data_structure {
  template <class T>
  class BDeque : public ArrayDeque<T> {
  protected:
    using ArrayDeque<T>::a;
    using ArrayDeque<T>::j;
    using ArrayDeque<T>::n;
    virtual void resize();
  public:
    BDeque(int b);
    virtual ~BDeque();
    T pop();
    T shift();

    T push_rotate(T x);
    T unshift_rotate(T x);
    int length();
    void print_all();
  };

  template <class T>
  BDeque<T>::BDeque(int b) {
    j = 0;
    n = 0;
    array<int> z(b);
    a = z;
  }

  template<class T>
  int BDeque<T>::length() {
    return a.length;
  }

  template <class T>
  BDeque<T>::~BDeque() {
  }

  template<class T>
  void BDeque<T>::resize() {
    assert(n < a.length);
  }

  template<class T>
  T BDeque<T>::pop() {
    return this->remove(this->size()-1);
  }

  template<class T>
  T BDeque<T>::shift() {
    return this->remove(0);
  }

  template<class T>
  T BDeque<T>::push_rotate(T x) {
    T y = (n >= a.length) ? shift() : (T) NULL;
    this->add(this->size(), x);
    return y;
  }

  template<class T>
  T BDeque<T>::unshift_rotate(T x) {
    T y = (n >= a.length) ? pop() : (T) NULL;
    this->add(0, x);
    return y;
  }

  template <class T> inline
  void BDeque<T>::print_all() {
    cout << this->size() << " : ";
    for (int k = j; k < j + n; k++)
      cout << a[k % a.length] << ", ";
    cout << endl;
  }
}
#endif
