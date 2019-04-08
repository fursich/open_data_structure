#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
#include <string>

using namespace std;

template <typename T>
class Element {
public:
  Element<T>* next;
  T* value;

  Element<T> (T* newValue) {
    value = newValue;
    next = nullptr;
  }

  void set_next(Element<T>* nextElement) {
    next = nextElement;
  }
};

template <typename T>
class List {
public:
  Element<T>* head;
  size_t len;

  List<T>() {
    Element<T>* pFirstElement = new Element<T> (NULL);
    head = pFirstElement;
    pFirstElement->next = nullptr;
    len = 0;
  }

  size_t size() {
    return len;
  }

  Element<T>* get(size_t n) {
    if (n>=0 && n < len) {
      Element<T>* ptr = head->next;
      for (size_t i=0; i< n; ++i) {
        ptr = ptr->next;
      }
      return ptr;
    } else {
      return nullptr;
    }
  }

  bool set(size_t n, T* x) {
    Element<T>* ptr = get(n);
    if (ptr == nullptr) {
      return false;
    } else {
      ptr->value = x;
      return true;
    }
  }

  bool add(size_t n, T* x) {
    if (n>=0 && n <= len) {
      Element<T>* pNewElement = new Element<T> (x);
      Element<T>* pPrev = n == 0 ? head : get(n-1);
      pNewElement->next = pPrev->next;
      pPrev->next = pNewElement;
      len += 1;
      return true;
    } else {
      return false;
    }
  }

  Element<T>* remove(size_t n) {
    if (n>=0 && n < len) {
      Element<T>* pElement = get(n);
      Element<T>* pPrev = n == 0 ? head : get(n-1);

      pPrev->next = pElement->next;
      pElement->next = nullptr;
      len -= 1;
      return pElement;
    } else {
      return nullptr;
    }
  }
};

template<typename T>
void print_value(T* ptr) {
  if (ptr !=  nullptr) {
    cout << *ptr->value << endl;
  } else {
    cout << "[can't find any]" << endl;
  }
}

template<typename T>
void print(T value) {
  cout << value << endl;
}


int main() {
  string a = "HOGE HGOE", b = "FUGA fuga";
  Element<string> elem1(&a);
  Element<string> elem2(&b);
  elem1.set_next(&elem2);

  List<string> list;
  list.head->next = &elem1;
  list.len = 2;
  print_value(list.get(0));
  print_value(list.get(1));
  print_value(list.get(2));

  cout << "-------" << endl;

  string x = "FOOOOOOooooo!", y = "barrrrrrr";
  print(list.set(10, &x));
  print(list.set(1, &x));
  print_value(list.get(0));
  print_value(list.get(1));
  print_value(list.get(2));

  cout << "-------" << endl;

  print(list.add(0, &y));
  print_value(list.get(0));
  print_value(list.get(1));
  print_value(list.get(2));

  cout << "-------" << endl;

  print_value(list.remove(1));
  print_value(list.get(0));
  print_value(list.get(1));
  print_value(list.get(2));
}

