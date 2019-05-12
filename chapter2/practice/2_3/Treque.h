#ifndef TREQUE_H_
#define TREQUE_H_

#include <iostream>
#include "ArrayDeque.h"

using namespace std;

namespace data_structure {
  template <class T>
  class Treque {
  protected:
    ArrayDeque<T>* front;
    ArrayDeque<T>* back;
    void balance();
  public:
    Treque<T>();
    virtual ~Treque();
    int size();
    T get(int i);
    T set(int i, T x);


    virtual void add(int i, T x);
    virtual T remove(int i);
    virtual void clear();
    void print_all();
  };

  template <class T>
  Treque<T>::Treque() {
    front = new ArrayDeque<T>;
    back  = new ArrayDeque<T>;
  }

  template <class T>
  Treque<T>::~Treque() {
    delete front;
    delete back;
  }

  template <class T>
  int Treque<T>::size() {
    return front->size() + back->size();
  }

  template <class T> inline
  T Treque<T>::get(int i) {
    if (i < front->size()) {
      return front->get(front->size() - i - 1);
    } else {
      return back->get(i - front->size());
    }
  }

  template <class T> inline
  T Treque<T>::set(int i, T x) {
    if (i < front->size()) {
      return front->set(front->size() - i - 1, x);
    } else {
      return back->set(i - front->size(), x);
    }
  }

  template <class T>
  void Treque<T>::add(int i, T x) {
    if (i < front->size()) {
      front->add(front->size() - i, x);
    } else {
      back->add(i - front->size(), x);
    }
    balance();
  }

  template <class T>
  T Treque<T>::remove(int i) {
    T x;
    if (i < front->size()) {
      x = front->remove(front->size() - i - 1);
    } else {
      x = back->remove(i - front->size());
    }
    balance();
    return x;
  }

  template<class T>
  void Treque<T>::balance() {
    if (3 * front->size() < back->size() || 3 * back->size() < front->size()) {
      int n = front->size() + back->size();
      int nf = n / 2;

      auto new_front = new ArrayDeque<T>;
      for (int i = 0; i < nf; i++) {
        new_front->add(nf-i-1, get(i));
      }

      int nb = n - nf;
      auto new_back  = new ArrayDeque<T>;
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
  void Treque<T>::clear() {
    front->clear();
    back->clear();
  }

  template <class T> inline
  void Treque<T>::print_all() {
    cout << size() << " : ";
    for (int i=0; i<size(); i++)
      cout << get(i) << ", ";
    cout << endl;
  }
}
#endif
