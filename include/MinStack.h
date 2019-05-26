#ifndef MINSTACK_H_
#define MINSTACK_H_

#include <iostream>
#include "SLList.h"

using namespace std;

namespace data_structure {

  template <class T>
  class MinStack {
  protected:
    SLList<T>* stack;
    SLList<T>* min_stack;
    T null;

  public:
    MinStack();
    virtual ~MinStack();

    int size();
    T push(T x);
    T pop();
    T min();

    void print_all();
    void print_min();
  };

  template <class T>
  MinStack<T>::MinStack() {
    stack = new SLList<T>;
    min_stack = new SLList<T>;
    null = (T) NULL;
  }

  template <class T>
  MinStack<T>::~MinStack() {
    delete stack;
    delete min_stack;
  }

  template <class T>
  int MinStack<T>::size() {
    return stack->size();
  }

  template <class T>
  T MinStack<T>::min() {
    if (size() == 0) return null;

    return min_stack->peek();
  }

  template <class T>
  T MinStack<T>::push(T x) {
    stack->push(x);

    T min;
    if (min_stack->size() == 0) {
      min = x;
    } else {
      T y = min_stack->peek();
      min = x < y ? x : y;
    }
    min_stack->push(min);
    return x;
  }

  template <class T>
  T MinStack<T>::pop() {
    min_stack->pop(); /* no longer needed */
    return stack->pop();
  }

  template <class T> inline
  void MinStack<T>::print_all() {
    stack->print_all();
    min_stack->print_all();
  }

  template <class T> inline
  void MinStack<T>::print_min() {
    cout << "min : " << min() << endl;
  }
}
#endif
