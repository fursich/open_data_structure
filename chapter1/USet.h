
#ifndef USET_H_
#define USET_H_

#include <iostream>
#include <string>
#include <cmath>
#include <climits>

#include "SLList.h"
using namespace std;

namespace data_structure {

template <class T>
class USet {

protected:
  class HashList : SLList<T> {
  public:
    typename SLList<T>::Node* fetch_by_value(T* pValue) {
      typename SLList<T>::Node* pNode = this->head;

      while (pNode != nullptr) {
        if (*pNode->pValue == *pValue) {
          return pNode;
        }
        pNode = pNode->next;
      }
      return nullptr;
    }

    size_t fetch_position_by_value(T* pValue) {
      typename SLList<T>::Node* pNode = this->head;
      size_t n=0;

      while (pNode != nullptr) {
        if (*pNode->pValue == *pValue) {
          return n;
        }
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
      if (this->add(this->len, pValue)) {
        return true;
      } else {
        return false;
      }
    }

    T* retrieve_value(T* pValue) {
      typename SLList<T>::Node* pResult = fetch_by_value(pValue);
      if (pResult == nullptr) {
        return (T*) nullptr;
      } else {
        return pResult->pValue;
      }
    }
  };
  HashList** table;

public:
  static const int    hashSizeOrder = 4; // hash table of 2^5 in size
  static const int    hashSize      = (1 << hashSizeOrder);
  static const size_t bitmask       = (1 << hashSizeOrder) - 1;
  size_t totalSize;

  USet<T>() {
    totalSize = 0;
    table = new HashList*[hashSize];
    for (int i=0; i<hashSize; ++i) {
      table[i] = new HashList;
    }
  }

  virtual ~USet() {
    for (int i=0; i<hashSize; ++i) {
      if (table[i] != nullptr) {
        delete table[i];
      }
    }
    delete[] table;
  }

  size_t size() {
    return totalSize;
  }

  T* find(T* pValue) {
    size_t key = hash(pValue);
    return table[key]->retrieve_value(pValue);
  }

  bool add(T* pValue) {
    size_t key = hash(pValue);
    if (table[key]->fetch_by_value(pValue) == nullptr) {
      if (table[key]->append_value(pValue)) {
        totalSize++;
        return true;
      }
    }
    return false;
  }

  T* remove(T* pValue) {
    size_t key = hash(pValue);
    T* pResult = table[key]->remove_by_value(pValue);
    if (pResult == nullptr) {
      return nullptr;
    } else {
      totalSize--;
      return pResult;
    }
  }

  size_t hash(T* pValue) {
    size_t origHashValue = std::hash<T>()(*pValue);
    size_t hashValue = 0;

    for (size_t i=0; i < sizeof(size_t) * CHAR_BIT; i+=hashSizeOrder ) {
      hashValue ^= origHashValue & bitmask;
      origHashValue = origHashValue >> hashSizeOrder;
    }
    return hashValue;
  }
};
}

#endif /* USET_H_ */
