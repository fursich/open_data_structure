#ifndef SLLIST_H_
#define SLLIST_H_

#include <iostream>
using namespace std;

namespace data_structure {

template <class T>
class SLList {
protected:
  class Node {
  public:
    T* pValue;
    Node* next;

    Node (T* pNewValue) {
      pValue = pNewValue;
      next = (Node*) nullptr;
    }
  };

  Node* head;
  size_t len;

  Node* fetch(size_t n) {
    if (n>=0 && n < len) {
      Node* pNode = head;
      for (size_t i=0; i< n; ++i) {
        pNode = pNode->next;
      }
      return pNode;
    } else {
      return nullptr;
    }
  }

public:
  SLList<T>() {
    len = 0;
    head = (Node*) nullptr;
  }

  virtual ~SLList() {
    Node* pNode = head;
    while (pNode != nullptr) {
      Node* tmp = pNode;
      pNode = pNode->next;
      delete tmp;
    }
  }

  size_t size() {
    return len;
  }

  T* get(size_t n) {
    Node* pNode = fetch(n);
    if (pNode == nullptr) {
      return nullptr;
    } else {
      return pNode->pValue;
    }
  }

  bool set(size_t n, T* pNewValue) {
    Node* pNode = fetch(n);
    if (pNode == nullptr) {
      return false;
    } else {
      pNode->pValue = pNewValue;
      return true;
    }
  }

  bool add(size_t n, T* pNewValue) {
    if (n>=0 && n <= len) {
      Node* pNewNode = new Node(pNewValue);
      Node* pPrev = fetch(n-1);

      if (pPrev == nullptr) {
        pNewNode->next = head;
        head = pNewNode;
      } else {
        pNewNode->next = pPrev->next;
        pPrev->next = pNewNode;
      }
      len += 1;
      return true;
    } else {
      return false;
    }
  }

  T* remove(size_t n) {
    if (n>=0 && n < len) {
      Node* pNode = fetch(n);
      Node* pPrev = fetch(n-1);
      T* pRemovedValue = pNode->pValue;

      if (pPrev == nullptr) {
        head = pNode->next;
      } else {
        pPrev->next = pNode->next;
      }
      len -= 1;
      delete pNode;
      return pRemovedValue;
    } else {
      return nullptr;
    }
  }

private:
  void print_pValue(T* pVal) {
    if (pVal !=  (T *) nullptr) {
      cout << *pVal << "    ";
    } else {
      cout << "[can't find any]" << " ";
    }
  }

  void print(T val) {
    cout << val << endl;
  }
public:
  void print_list() {
    cout << "[size] " << size() << endl;

    cout << "[data]" << endl;
    Node* pNode = head;

    while (pNode != nullptr) {
      print_pValue(pNode->pValue);
      pNode = pNode->next;
    }
    cout << endl;
  }
};

}

#endif /* SLLIST_H_ */
