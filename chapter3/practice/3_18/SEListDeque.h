#ifndef SELIST_DEQUE_H_
#define SELIST_DEQUE_H_

#include <iostream>
#include "SEList.h"

using namespace std;

namespace data_structure {
  template <class T>
  class SEListDeque {
  protected:
    SEList<T>* front;
    SEList<T>* back;
    void balance();
    T null;
    int b; /* arbitrary */

  public:
    SEListDeque();
    virtual ~SEListDeque();

    int size();

    T addFirst(T x);
    T removeFirst();
    T addLast(T x);
    T removeLast();

    void print_all();
  };

  template <class T>
  SEListDeque<T>::SEListDeque() {
    front = new SEList<T>;
    back = new SEList<T>;
    null = (T) NULL;
  }

  template <class T>
  SEListDeque<T>::~SEListDeque() {
    delete front;
    delete back;
  }

  template <class T>
  int SEListDeque<T>::size() {
    return front->size() + back->size();
  }

  template <class T>
  void SEListDeque<T>::balance() {
    int n = size();
    if (n <= 1) return;
    int i = (n+1)/2;
    if (i <= 0) return;

    if (3 * front->size() <= back->size() || 3 * back->size() <= front->size()) {
    cout << "balanced.." << endl;


      if(front->size() >= back->size()) {
        SEList<T> *new_front = front->truncate(front->size()-i);
        SEList<T> *transferred_list = SEList<T>::reverse(front);

        transferred_list->absorb(back);
        back = transferred_list;
        front = new_front;

      } else {
        SEList<T> *new_back = back->truncate(back->size()-i);
        SEList<T> *transferred_list = SEList<T>::reverse(back);

        transferred_list->absorb(front);
        front = transferred_list;
        back = new_back;
      }
    }
  }

  template <class T>
  T SEListDeque<T>::addFirst(T x) {
    front->push(x);
    balance();
    return x;
  }

  template <class T>
  T SEListDeque<T>::addLast(T x) {
    back->push(x);
    balance();
    return x;
  }

  template <class T>
  T SEListDeque<T>::removeFirst() {
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
  T SEListDeque<T>::removeLast() {
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
  void SEListDeque<T>::print_all() {
    SEList<T>::print_dual_stacks_with_counter_order(front, back);
  }
}
#endif
