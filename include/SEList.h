#ifndef SELIST_H_
#define SELIST_H_

#include <iostream>
#include <assert.h>
#include "BDeque.h"

using namespace std;

namespace data_structure {
  template <class T>
  class SEList {
  protected:
    int n;
    static const int b=3;
    class Node {
      public:
      BDeque<T> d;
      Node *prev, *next;
      Node(int b) : d(b+1) { } /* d.size() <= b+1 */
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
    T null;

  public:
    SEList();
    virtual ~SEList();

    int size();
    T get(int i);
    T set(int i, T x);
    virtual void clear();

    void add(int i, T x);
    T remove(int i);

    virtual void push(T x);
    virtual T pop();
    virtual T peek();

    SEList<T>* truncate(int i);
    void absorb(SEList<T>* l2);
    static SEList<T>* reverse(SEList<T>* l2);

    void print_all();
    void print_all_backward();
    void print_all_elements(bool is_forward_direction);
    static void print_dual_stacks_with_counter_order(SEList<T>* l1, SEList<T>* l2);
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
  SEList<T>* SEList<T>::truncate(int i) {
    assert(i >0 && i < size());

    SEList<T>* list = new SEList<T>;

    for(int j=i;j<size();j++) {
      list->push(get(j));
    }

    Location l;
    getLocation(i, l);

    Node *u = dummy.prev;
    while (u != l.u) {

      Node *v = u;
      u = u->prev;

      n -= v->d.size();
      remove(v);
    }

    for(int j=l.u->d.size()-1; j>=l.j; j--) {
      pop();
    }

    return list;
  }

  template <class T>
  void SEList<T>::absorb(SEList<T>* l2) {
    for(int j=0;j<l2->size();j++) {
      push(l2->get(j));
    }

    if (l2->size() > 0)
      l2->clear();
  }

  template <class T>
  SEList<T>* SEList<T>::reverse(SEList<T>* l2) {
    SEList<T>* list = new SEList<T>;

    for(int j=l2->size()-1;j>=0;j--) {
      list->push(l2->get(j));
    }
    l2->clear();

    return list;
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
  SEList<T>::SEList() {
    dummy.prev = &dummy;
    dummy.next = &dummy;
    null = (T) NULL;
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
    dummy.prev = &dummy;
    dummy.next = &dummy;
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
    if (size() == 0) return null;

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
  void SEList<T>::push(T x) {
    add(size(), x);
  }

  template <class T>
  T SEList<T>::pop() {
    return remove(size()-1);
  }

  template <class T>
  T SEList<T>::peek() {
    return get(size()-1);
  }

  template <class T>
  inline void SEList<T>::print_all() {
    print_all_elements(true);
    cout << endl;
  }

  template <class T>
  inline void SEList<T>::print_all_backward() {
    print_all_elements(false);
    cout << endl;
  }

  template <class T>
  inline void SEList<T>::print_dual_stacks_with_counter_order(SEList<T>* l1, SEList<T>* l2) {
    l1->print_all_elements(false);
    l2->print_all_elements(true);
    cout << endl;
  }

  template <class T>
  inline void SEList<T>::print_all_elements(bool is_forward_direction) {
    cout << " (" << size() << ") : ";
    if (is_forward_direction) {
      for (int i=0; i<size(); i++)
        cout << get(i) << ", ";
    } else {
      for (int i=size()-1; i>=0; i--)
        cout << get(i) << ", ";
    }
  }
}
#endif
