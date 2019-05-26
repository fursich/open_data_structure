#ifndef DLLIST_H_
#define DLLIST_H_

#include <iostream>
#include <assert.h>

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
    Node* addNode(Node *w);
    void removeNode(Node *w);
    void appendList(Node *first, Node *last, int m);
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
    void rotate(int r);
    DLList<T>* truncate(int i);
    DLList<T>* deal();
    bool isPalindrome();
    void absorb(DLList<T>* l2);

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
  bool DLList<T>::isPalindrome() {
    Node *u = dummy.next;
    Node *v = dummy.prev;
    while (u!=&dummy) {
      if (u->x != v->x) return false;
      u = u->next;
      v = v->prev;
    }
    return true;
  }

  template <class T>
  void DLList<T>::rotate(int r) {
    if (n == 0) return;

    Node *u = getNode((n-r%n) % n);
    Node *v = u->prev;

    // cout << n << "," << (n-r%n) % n << " | " << u->x << "," << v->x << endl;

    dummy.next->prev = dummy.prev;
    dummy.prev->next = dummy.next;

    dummy.prev = v;
    dummy.prev->next = &dummy;
    dummy.next = u;
    dummy.next->prev = &dummy;
  }

  template <class T>
  void DLList<T>::appendList(Node *first, Node *last, int m) {
    dummy.prev->next = first;
    first->prev = dummy.prev;
    dummy.prev = last;
    last->next = &dummy;
    n += m;
  }

  template <class T>
  void DLList<T>::absorb(DLList<T>* l2) {
    if (this == l2) return;

    appendList(l2->dummy.next, l2->dummy.prev, l2->size());
    l2->n = 0;
    l2->dummy.next = &l2->dummy;
    l2->dummy.prev = &l2->dummy;
  }

  template <class T>
  DLList<T>* DLList<T>::truncate(int i) {
    assert(i>0 && i<n);

    Node *first = getNode(i);
    Node *prev = first->prev;
    Node *last = dummy.prev;

    prev->next=&dummy;
    prev->next->prev=prev;
    int m = n-i;
    n = i;

    DLList<T>* list = new DLList<T>;
    list->appendList(first, last, m);
    return list;
  }

  template <class T>
  DLList<T>* DLList<T>::deal() {
    DLList<T>* list = new DLList<T>;

    Node *u = dummy.next;
    Node *p;
    int n0 = n;

    for (int i=1; i<=n0; i++) {

      if (i % 2 == 1) {
        u = u->next;
        continue;
      }
      p = u;
      u = u->next;
      removeNode(p);
      list->addNode(p);
    }
    return list;
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
  typename DLList<T>::Node* DLList<T>::addNode(Node* w) {
    Node *u = dummy.prev;

    w->next = u->next;
    w->next->prev = w;
    u->next = w;
    u->next->prev = u;
    n++;
    return w;
  }

  template <class T>
  void DLList<T>::removeNode(Node* w) {
    w->next->prev = w->prev;
    w->prev->next = w->next;
    n--;
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
