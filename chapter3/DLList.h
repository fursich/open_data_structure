#ifndef DLLIST_H_
#define DLLIST_H_

#include <iostream>

using namespace std;

namespace data_structure {
  template <class T>
  class DLList {
  protected:
    class Node {
      public:
        T x;
        Node *prev, *next;
    };
    Node dummy;
    int n;
    void remove(Node *w);
    Node* addBefore(Node *w, T x);
    Node* getNode(int i);
  public:
    DLList();
    virtual ~DLList();

    int size();
    T get(int i);
    T set(int i, T x);

    virtual void add(int i, T x);
    virtual void add(T x);
    virtual T remove(int i);
    virtual void clear();

    void print_all();
  };

  template <class T>
  DLList<T>::DLList() {
    dummy.next = &dummy;
    dummy.prev = &dummy;
    n = 0;
  }

  template <class T>
  DLList<T>::~DLList() {
    clear();
  }

  template <class T>
  void DLList<T>::clear() {
    Node *u = dummy.next;
    while(u != &dummy) {
      Node *w = u;
      u = u->next;
      delete w;
    }
    n = 0;
  }

  template <class T>
  int DLList<T>::size() {
    return n;
  }

  template <class T>
  typename DLList<T>::Node* DLList<T>::getNode(int i) {
    Node *p;
    if (i < n/2) {
      p = dummy.next;
      for (int j=0; j < i; j++) {
        p = p->next;
      }
    } else {
      p = &dummy;
      for (int j=n; j > i; j--) {
        p = p->prev;
      }
    }
    return p;
  }

  template <class T>
  typename DLList<T>::Node* DLList<T>::addBefore(Node* w, T x) {
    Node *u = new Node;
    u->x    = x;
    u->prev = w->prev;
    u->next = w;
    u->next->prev = u;
    u->prev->next = u;
    n++;
    return u;
  }

  template <class T>
  void DLList<T>::remove(Node *w) {
    w->next->prev = w->prev;
    w->prev->next = w->next;
    delete w;
    n--;
  }

  template <class T>
  T DLList<T>::get(int i) {
    return getNode(i)->x;
  }

  template <class T>
  T DLList<T>::set(int i, T x) {
    Node *u = getNode(i);
    T y = u->x;
    u->x = x;
    return y;
  }

  template <class T>
  void DLList<T>::add(int i, T x) {
    addBefore(getNode(i), x);
  }

  template <class T>
  void DLList<T>::add(T x) {
    add(size(), x);
  }

  template <class T>
  T DLList<T>::remove(int i) {
    Node *w = getNode(i);
    T x = w->x;
    remove(w);
    return x;
  }

  template <class T> inline
  void DLList<T>::print_all() {
    cout << size() << " : ";
    for (int i=0; i<size(); i++)
      cout << get(i) << ", ";
    cout << endl;
  }
}
#endif
