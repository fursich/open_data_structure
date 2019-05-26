#ifndef MINDEQUE_H_
#define MINDEQUE_H_

#include <iostream>
#include "DLListMinStack.h"

using namespace std;

namespace data_structure {
  template <class T>
  class MinDeque {
  protected:
    DLListMinStack<T>* front;
    DLListMinStack<T>* back;
    void balance();
    T null;

  public:
    MinDeque();
    virtual ~MinDeque();

    int size();

    T addFirst(T x);
    T removeFirst();
    T addLast(T x);
    T removeLast();
    T min();

    void print_all();
    void print_min();
  };

  template <class T>
  MinDeque<T>::MinDeque() {
    front = new DLListMinStack<T>;
    back = new DLListMinStack<T>;
    null = (T) NULL;
  }

  template <class T>
  MinDeque<T>::~MinDeque() {
    delete front;
    delete back;
  }

  template <class T>
  int MinDeque<T>::size() {
    return front->size() + back->size();
  }

  template <class T>
  T MinDeque<T>::min() {
    if (size() == 0) return null;
    if (front->size() == 0) return back->min();
    if (back->size() == 0) return front->min();

    T x = front->min();
    T y = back->min();
    return x < y ? x : y;
  }

  template <class T>
  void MinDeque<T>::balance() {
    int n = size();
    if (n <= 1) return;

    if (3 * front->size() <= back->size() || 3 * back->size() <= front->size()) {
      DLListMinStack<T>::rebalance_stacks(front, back);
    }
  }

  template <class T>
  T MinDeque<T>::addFirst(T x) {
    front->push(x);
    balance();
    return x;
  }

  template <class T>
  T MinDeque<T>::addLast(T x) {
    back->push(x);
    balance();
    return x;
  }

  template <class T>
  T MinDeque<T>::removeFirst() {
    T y;
    if (front->size()==0 && back->size()==1) {
      y = back->pop(); /* the last one */
    } else {
      y = front->pop();
    }
    balance();
    return y;
  }

  template <class T>
  T MinDeque<T>::removeLast() {
    T y;
    if (back->size()==0 && front->size()==1) {
      y = front->pop(); /* the last one */
    } else {
      y = back->pop();
    }
    balance();
    return y;
  }

  template <class T> inline
  void MinDeque<T>::print_all() {
    front->stack->print_all();
    back->stack->print_all_backward();
  }

  template <class T> inline
  void MinDeque<T>::print_min() {
    cout << "min : " << min() << endl;
  }
}
#endif
