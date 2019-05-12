
#ifndef ARRAY_H_
#define ARRAY_H_

#include <assert.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

namespace data_structure {
  template <class T>
  class array {
  protected:
    T* ary;
  public:
    int length;

    array(int len);
    virtual ~array();

    array<T>& operator=(array<T> &b) {
      if (ary != (T*) nullptr) delete[] ary;
      ary = b.ary;
      b.ary = (T *)nullptr;
      length = b.length;
      return *this;
    }

    T& operator[](int i) {
      assert(i >= 0 && i < length);
      return ary[i];
    }

    T* operator+(int i) {
      return &ary[i];
    }
  };

  template <class T>
  array<T>::array(int len) {
    length = len;
    ary = new T[length];
  }

  template <class T>
  array<T>::~array()
  {
    if (ary != (T*) nullptr) delete [] ary;
  }
}

#endif
