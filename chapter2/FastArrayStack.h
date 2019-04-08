#ifndef FAST_ARRAY_STACK_H_
#define FAST_ARRAY_STACK_H_

#include "ArrayStack.h"

using namespace std;

namespace data_structure {

  template <class T>
  class FastArrayStack : public ArrayStack<T> {
  protected:
    using ArrayStack<T>::a;
    using ArrayStack<T>::n;
    virtual void resize();
  public:
    FastArrayStack<T>();
    virtual ~FastArrayStack();
    virtual void add(int i, T x);
    virtual T remove(int i);
  };

  template <class T>
  FastArrayStack<T>::FastArrayStack() : ArrayStack<T>() {
  }

  template <class T>
  FastArrayStack<T>::~FastArrayStack() {
  }

  template <class T>
  void FastArrayStack<T>::add(int i, T x) {
    if (n + 1 > a.length) resize();
    std::copy_backward(a+i, a+n, a+n+1);
    a[i] = x;
    n++;
  }

  template <class T>
  T FastArrayStack<T>::remove(int i) {
    T x = a[i];
    std::copy(a+i+1, a+n, a+i);
    n--;
    if (3 * n <= a.length) resize();
    return x;
  }

  template<class T>
  void FastArrayStack<T>::resize() {
    array<T> b(max(2 * n, 1));
    std::copy(a+0, a+n, b+0);
    a = b;
  }
}
#endif
