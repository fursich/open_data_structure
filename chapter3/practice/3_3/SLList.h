#ifndef SLLIST_H_
#define SLLIST_H_

#include <iostream>
// #include "../common/ArrayDeque.h"

using namespace std;

namespace data_structure {
  template <class T>
  class SLList {
    T null;
  protected:
    class Node {
      public:
        T x;
        Node *next;
        Node(T x0);
    };
    Node* head;
    Node* tail;
    int n;
  public:
    SLList<T>();
    virtual ~SLList();

    int size();
    T peek();
    T get(int i);
    T set(int i, T x);

    T pop();
    T push(T x);
    bool add(T x);
    T remove();

    T secondLast();

    void print_all();
  };

  template <class T>
  SLList<T>::Node::Node(T x0) {
    x = x0;
    next = NULL;
  }

  template <class T>
  SLList<T>::SLList() {
    null = (T)NULL;
    n = 0;
    head = tail = nullptr;
  }

  template <class T>
  SLList<T>::~SLList() {
    Node *u = head;
    while(u != nullptr) {
      Node *w = u;
      u = u->next;
      delete w;
    }
  }

  template <class T>
  int SLList<T>::size() {
    return n;
  }

  template <class T>
  T SLList<T>::get(int i) {
    Node *u = head;
    for (int j=0; j<i; j++) {
      if (u == nullptr) return null;
      u = u->next;
    }
    return u->x;
  }

  template <class T>
  T SLList<T>::set(int i, T x) {
    Node *u = head;
    for (int j=0; j<i; j++) {
      if (u == nullptr) return null;
      u = u->next;
    }
    int y = u->x;
    u->x = x;
    return y;
  }

  template <class T>
  T SLList<T>::peek() {
    return head->x;
  }

  template <class T>
  T SLList<T>::push(T x) {
    Node *u = new Node(x);
    u->next = head;
    head = u;
    if (n==0)
      tail = u;
    n++;
    return x;
  }

  template <class T>
  T SLList<T>::pop() {
    if (n==0) return null;
    T x = head->x;
    Node *u = head;
    head = head->next;
    delete u;
    if (--n==0) tail = nullptr;
    return x;
  }


  template <class T>
  bool SLList<T>::add(T x) {
    Node *u = new Node(x);
    if (n==0) {
      head = u;
    } else {
      tail->next = u;
    }
    tail = u;
    n++;
    return true;
  }

  template <class T>
  T SLList<T>::remove() {
    if (n==0) return null;
    T x = head->x;
    Node *u = head;
    head = head->next;
    delete u;
    if (--n==0) tail = nullptr;
    return x;
  }

  template <class T>
  T SLList<T>::secondLast() {
    if (n < 2) return null;

    Node *u = head;
    while(u->next != tail) {
      u = u->next;
    }
    return u->x;
  }

  template <class T> inline
  void SLList<T>::print_all() {
    cout << size() << " : ";
    for (int i=0; i<size(); i++)
      cout << get(i) << ", ";
    cout << endl;
  }
}
#endif