#ifndef SELIST_H_
#define SELIST_H_

#include <iostream>
#include "BDeque.h"

using namespace std;

namespace data_structure {
  template <class T>
  class SEList {
  protected:
    int n;
    int b;
    class Node {
      public:
      BDeque<T> d;
      Node *prev, *next;
      Node(int b) : d(b) { }
      Node() : d(1) { }
    };

    Node dummy;

    class Location {
      public:
      Node *u;
      int j;
      Location() { }
      Location(Node *u, int j) {
        this->u = u;
        this->j = j;
      }
    };

    Node* addBefore(Node *w);
    void getLocation(int i, Location &ell);
    void spread(Node *u);
    void gather(Node *u);
    void add(T x);
    void remove(Node *w);

  public:
    SEList(int b);
    ~SEList();

    int size();
    T get(int i);
    T set(int i, T x);
    virtual void clear();

    void add(int i, T x);
    T remove(int i);

    void print_all();
  };

  template <class T>
  void SEList<T>::getLocation(int i, Location &ell) {
    if (i < n/2) {
      Node *u = dummy.next;
      while(i >= u->d.size()) {
        i -= u->d.size();
        u = u->next;
      }
      ell.u = u;
      ell.j = i;
    } else {
      Node *u = &dummy;
      int idx = n;
      while(i < idx) {
        u = u->prev;
        idx -= u->d.size();
      }
      ell.u = u;
      ell.j = i - idx;
    }
  }

  template <class T>
  typename SEList<T>::Node* SEList<T>::addBefore(Node* w) {
    Node* u = new Node(b);
    u->prev = w->prev;
    u->next = w;
    u->next->prev = u;
    u->prev->next = u;
    return u;
  }

  template <class T>
  void SEList<T>::remove(Node* w) {
    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;
  }

  template <class T>
  void SEList<T>::spread(Node* u) {
    Node *w = u;
    for (int j =0; j<b; j++) {
      w = w->next;
    }
    w = addBefore(w);
    while (w != u) {
      while (w->d.size() < b)
        w->d.add(0, w->prev->d.remove(w->prev->d.size()-1));
      w = w->prev;
    }
  }

  template <class T>
  void SEList<T>::gather(Node* u) {
    Node *w = u;
    for (int j=0; j<b-1; j++) {
      while (w->d.size() < b)
        w->d.add(0, w->next->d.remove(0));
      w = w->next;
    }
  }

  template <class T>
  void SEList<T>::add(T x) {
    Node *last = dummy.prev;
    if (last == &dummy || last->d.size() == b+1) {
      last = addBefore(&dummy);
    }
    last->d.add(x);
    n++;
  }


  template <class T>
  SEList<T>::SEList(int b) {
    dummy.prev = &dummy;
    dummy.next = &dummy;
    n = 0;
  }

  template <class T>
  SEList<T>::~SEList() {
    clear();
  }

  template <class T>
  void SEList<T>::clear() {
    Node *u = dummy.next;
    while (u != &dummy) {
      Node *w = u;
      u = u->next;
      delete w;
    }
    n = 0;
  }

  template <class T>
  int SEList<T>::size() {
    return n;
  }

  template <class T>
  T SEList<T>::get(int i) {
    Location l;
    getLocation(i, l);
    return l.u->d.get(l.j);
  }

  template <class T>
  T SEList<T>::set(int i, T x) {
    Location l;
    getLocation(i, l);
    T y = l.u->d.get(l.j);
    l.u->d.set(l.j, x);
    return y;
  }

  template <class T>
  void SEList<T>::add(int i, T x) {
    if (i == n) {
      add(x);
      return;
    }

    Location l;
    getLocation(i, l);

    Node *u = l.u;
    int r = 0;
    while (r < b && u != &dummy && u->d.size() == b+1) {
      u = u->next;
      r++;
    }
    if (r == b) {
      spread(l.u);
      u = l.u;
    }
    if (u == &dummy) {
      u = addBefore(u);
    }
    while (u != l.u) {
      u->d.add(0, u->prev->d.remove(u->prev->d.size()-1));
      u = u->prev;
    }
    u->d.add(l.j, x);
    n++;
  }

  template <class T>
  T SEList<T>::remove(int i) {
    Location l;
    getLocation(i, l);
    T y = l.u->d.get(l.j);

    Node *u = l.u;
    int r = 0;
    while (r < b && u != &dummy && u->d.size() == b-1) {
      u = u->next;
      r++;
    }
    if (r == b) {
      gather(l.u);
    }
    u = l.u;
    u->d.remove(l.j);

    while (u->d.size() < b-1 && u->next != &dummy) {
      u->d.add(u->next->d.remove(0));
      u = u->next;
    }
    if (u->d.size() == 0)
      remove(u);
    n--;
    return y;
  }

  template <class T>
  inline void SEList<T>::print_all() {
    cout << size() << " : ";
    for (int i=0; i<size(); i++)
      cout << get(i) << ", ";
    cout << endl;
  }

}
#endif
