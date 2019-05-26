#ifndef MINQUEUE_H_
#define MINQUEUE_H_

#include <iostream>
#include "SLList.h"
#include "ArrayDeque.h"

using namespace std;

namespace data_structure {
  template <class T>
  class MinQueue {
  protected:
    SLList<T>* queue;
    ArrayDeque<T>* min_queue;
    T null;

    void add_min(T x);
    void remove_min(T x);
  public:
    MinQueue();
    virtual ~MinQueue();

    int size();
    T add(T x);
    T remove();
    T min();

    void print_all();
    void print_min();
  };

  template <class T>
  MinQueue<T>::MinQueue() {
    queue = new SLList<T>;
    min_queue = new ArrayDeque<T>;
    null = (T) NULL;
  }

  template <class T>
  MinQueue<T>::~MinQueue() {
    delete queue;
    delete min_queue;
  }

  template <class T>
  int MinQueue<T>::size() {
    return queue->size();
  }

  template <class T>
  T MinQueue<T>::min() {
    if (size() == 0) return null;

    return min_queue->get(0);
  }

  template <class T>
  void MinQueue<T>::add_min(T x) {
    for (int i = min_queue->size()-1; i>=0; i--) {
      if (x < min_queue->get(i))
        min_queue->remove(i); /* do not remove when x==min_queue->get(i) */
    }
    min_queue->add(min_queue->size(), x);
  }

  template <class T>
  void MinQueue<T>::remove_min(T x) {
    if (min_queue->size()>0 && x == min_queue->get(0)) min_queue->remove(0);
  }

  template <class T>
  T MinQueue<T>::add(T x) {
    queue->add(x);
    add_min(x);
    return x;
  }

  template <class T>
  T MinQueue<T>::remove() {
    T x = queue->remove();
    remove_min(x); /* only when x==min() */
    return x;
  }

  template <class T> inline
  void MinQueue<T>::print_all() {
    queue->print_all();
    min_queue->print_all();
  }

  template <class T> inline
  void MinQueue<T>::print_min() {
    cout << "min : " << min() << endl;
  }
}
#endif
