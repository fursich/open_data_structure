#ifndef DUAL_ROOTISH_ARRAY_DEQUEUE_H_
#define DUAL_ROOTISH_ARRAY_DEQUEUE_H_

#include <iostream>
#include <math.h>
#include "RootishArrayDeque.h"

using namespace std;

namespace data_structure {

  template <class T>
  class DualRootishArrayDeque {
  protected:
    RootishArrayDeque<T>* front;
    RootishArrayDeque<T>* back;
    void balance();
  public:
    DualRootishArrayDeque<T>();
    virtual ~DualRootishArrayDeque();
    int size();
    T get(int i);
    T set(int i, T x);

    virtual void add(int i, T x);
    virtual T remove(int i);
    virtual void clear();
    void print_all();
  };

  template <class T> inline
  T DualRootishArrayDeque<T>::get(int i) {
    if (i < front->size()) {
      return front->get(front->size() - i - 1);
    } else {
      return back->get(i - front->size());
    }
  }

  template <class T> inline
  T DualRootishArrayDeque<T>::set(int i, T x) {
    if (i < front->size()) {
      return front->set(front->size() - i - 1, x);
    } else {
      return back->set(i - front->size(), x);
    }
  }

  template <class T> inline
  int DualRootishArrayDeque<T>::size() {
    return front->size() + back->size();
  }

  template <class T>
  DualRootishArrayDeque<T>::DualRootishArrayDeque() {
    front = new RootishArrayDeque<T>;
    back  = new RootishArrayDeque<T>;
  }

  template <class T>
  DualRootishArrayDeque<T>::~DualRootishArrayDeque() {
    delete front;
    delete back;
  }

  template <class T>
  void DualRootishArrayDeque<T>::add(int i, T x) {
    if (i < front->size()) {
      front->add(front->size() - i, x);
    } else {
      back->add(i - front->size(), x);
    }
    balance();
  }

  template <class T>
  T DualRootishArrayDeque<T>::remove(int i) {
    T x;
    if (i < front->size()) {
      x = front->remove(front->size()-i-1);
    } else {
      x = back->remove(i-front->size());
    }
    balance();
    return x;
  }

  template<class T>
  void DualRootishArrayDeque<T>::balance() {
    if (3*front->size() < back->size() || 3*back->size() < front->size()) {
      int n = front->size() + back->size();
      int nf = n/2;

      auto new_front = new RootishArrayDeque<T>;
      for (int i = 0; i < nf; i++) {
        new_front->add(i, get(nf-i-1));
      }

      int nb = n - nf;
      auto new_back = new RootishArrayDeque<T>;
      for (int i = 0; i < nb; i++) {
        new_back->add(i, get(nf+i));
      }

      delete front;
      delete back;
      front = new_front;
      back = new_back;
    }
  }

  template <class T>
  void DualRootishArrayDeque<T>::clear() {
    front->clear();
    back->clear();
  }

  template <class T> inline
  void DualRootishArrayDeque<T>::print_all() {
    cout << front->size() << "-" << back->size() << ": ";
    for (int i=front->size()-1; i>=0; i--)
      cout << front->get(i) << ", ";
    for (int i=0; i<back->size(); i++)
      cout << back->get(i) << ", ";
    cout << endl;
  }
}
#endif
