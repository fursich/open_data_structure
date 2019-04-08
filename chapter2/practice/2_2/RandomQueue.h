#ifndef RANDOM_QUEUE_H_
#define RANDOM_QUEUE_H_

#include <random>
#include "../common/ArrayStack.h"

using namespace std;

namespace data_structure {

  template <class T>
  class RandomQueue : public ArrayStack<T> {
  protected:
    using ArrayStack<T>::a;
    using ArrayStack<T>::n;
    std::random_device rnd;
  public:
    RandomQueue<T>();
    virtual ~RandomQueue();
    // T get(int i);
    // T set(int i, T x);
    // virtual void add(int i, T x);
    // virtual T remove(int i);

    void append(T x);
    T take();
  };

  template <class T>
  RandomQueue<T>::RandomQueue() : ArrayStack<T>() {
  }

  template <class T>
  RandomQueue<T>::~RandomQueue() {
  }

  template <class T>
  void RandomQueue<T>::append(T x) {
    this->add(n, x);
  }

  template <class T>
  T RandomQueue<T>::take() {
    int i = rnd() % n;
    T x = this->get(i);
    this->set(i, this->remove(n-1));
    return x;
  }
}
#endif
