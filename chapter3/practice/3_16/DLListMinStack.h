#ifndef DLLIST_MINSTACK_H_
#define DLLIST_MINSTACK_H_

#include <iostream>
#include "DLList.h"

using namespace std;

namespace data_structure {
  template <class T> class MinDeque;

  template <class T>
  class DLListMinStack {
  protected:
    friend class MinDeque<T>;
    DLList<T>* stack;
    DLList<T>* min_stack;
    T null;

    static void rebalance_stacks(DLListMinStack<T>* x, DLListMinStack<T>* y);
    void rebuild_min_stack();
  public:
    DLListMinStack();
    virtual ~DLListMinStack();

    int size();
    T push(T x);
    T pop();
    T min();

    void print_all();
    void print_min();
  };

  template <class T>
  DLListMinStack<T>::DLListMinStack() {
    stack = new DLList<T>;
    min_stack = new DLList<T>;
    null = (T) NULL;
  }

  template <class T>
  DLListMinStack<T>::~DLListMinStack() {
    delete stack;
    delete min_stack;
  }

  template <class T>
  int DLListMinStack<T>::size() {
    return stack->size();
  }

  template <class T>
  T DLListMinStack<T>::min() {
    if (size() == 0) return null;

    return min_stack->peek();
  }

  template <class T>
  T DLListMinStack<T>::push(T x) {
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
  T DLListMinStack<T>::pop() {
    min_stack->pop(); /* no longer needed */
    return stack->pop();
  }

  template <class T>
  void DLListMinStack<T>::rebalance_stacks(DLListMinStack<T>* x, DLListMinStack<T>* y) {
    DLList<T>* l1 = x->stack;
    DLList<T>* l2 = y->stack;

    int n = l1->size() + l2->size();

    DLList<T> *longer, *shorter;
    if(l1->size() >= l2->size()) {
      longer  = l1;
      shorter = l2;
    } else {
      shorter = l1;
      longer  = l2;
    }

    int i = (n+1)/2;
    if (i <= 0) return;

    DLList<T>* list = longer->truncate(i);
    list->reverse();
    shorter->absorb(list);

    x->rebuild_min_stack();
    y->rebuild_min_stack();
  }

  template <class T>
  void DLListMinStack<T>::rebuild_min_stack() {

    delete min_stack;
    min_stack = new DLList<T>;

    typename DLList<T>::Node* u = stack->getNode(stack->size()-1);
    T min;
    while (u != &stack->dummy) {
      if (min_stack->size() == 0) {
        min = u->x;
      } else {
        T y = min_stack->peek();
        min = u->x < y ? u->x : y;
      }
      min_stack->push(min);

      u = u->prev;
    }
  }


  template <class T> inline
  void DLListMinStack<T>::print_all() {
    stack->print_all();
    min_stack->print_all();
  }

  template <class T> inline
  void DLListMinStack<T>::print_min() {
    cout << "min : " << min() << endl;
  }
}
#endif
