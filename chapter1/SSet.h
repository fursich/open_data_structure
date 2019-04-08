#ifndef SSET_H_
#define SSET_H_

#include <iostream>
#include <string>
#include <cmath>
#include <climits>

#include "SLList.h"
using namespace std;

namespace data_structure {

template <class T>
class SSet {

protected:
  class SortedList : SLList<T> {
  public:
    typename SLList<T>::Node* fetch_by_value(T* pValue) {
      typename SLList<T>::Node* pNode = this->head;

      while (pNode != nullptr) {
        if (*pValue <= *pNode->pValue) return pNode;
        pNode = pNode->next;
      }
      return nullptr;
    }

    signed int fetch_position_by_value(T* pValue) {
      typename SLList<T>::Node* pNode = this->head;
      signed int n=0;

      while (pNode != nullptr) {
        if (*pValue < *pNode->pValue) return -(n+1); // new position to add(insert): -1, -2, ...
        if (*pValue == *pNode->pValue) return n;
        pNode = pNode->next;
        n++;
      }
      return -1;
    }

    T* remove_by_value(T* pValue) {
      size_t n = fetch_position_by_value(pValue);
      if (n < 0) {
        return nullptr;
      } else {
        return this->remove(n);
      }
    }

    bool append_value(T* pValue) {
      signed int n = fetch_position_by_value(pValue);
      if (n < 0) {
        return this->add(-(n+1), pValue);
      } else {
        return false;
      }
    }

    T* find_by_value(T* pValue) {
      typename SLList<T>::Node* pResult = fetch_by_value(pValue);
      if (pResult == nullptr) {
        return (T*) nullptr;
      } else {
        return pResult->pValue;
      }
    }
  };

public:
  SortedList* slist;
  size_t totalSize;

  SSet<T>() {
    totalSize = 0;
    slist = new SortedList;
  }

  virtual ~SSet() {
    delete slist;
  }

  size_t size() {
    return totalSize;
  }

  T* find(T* pValue) {
    return slist->find_by_value(pValue);
  }

  bool add(T* pValue) {
    if (slist->append_value(pValue)) {
      totalSize++;
      return true;
    }
    return false;
  }

  T* remove(T* pValue) {
    T* pResult = slist->remove_by_value(pValue);
    if (pResult == nullptr) {
      return nullptr;
    } else {
      totalSize--;
      return pResult;
    }
  }
};
}

#endif /* SSET_H_ */
