#include <iostream>
#include <unordered_set>
#include <utility>
#include <string>

using namespace std;

template <typename T>
struct BagElement {
public:
  T* content;
  size_t size;

  BagElement(T* newContent, size_t newSize) : content(newContent), size(newSize) {}
  BagElement(const BagElement<T>& oldElement) {
    size = oldElement.size;
    content = new T(*oldElement.content);
  } 
  ~BagElement() { }

  bool operator == (const BagElement<T>& right) const {
    return hash<T>() (*content) == hash<T>() (*right.content);
  }
};

namespace std {
  template<typename T>
  struct hash<BagElement<T>> {
    size_t operator() (const BagElement<T>& element) const {
      return hash<T>() (*element.content);
    }
  };
}


template <typename T>
class Bag {
public:
  unordered_set<BagElement<T>>* pContainer;
 
  Bag() : pContainer(new unordered_set<BagElement<T>>) {};
  ~Bag() {
    delete pContainer;
  }

  bool add(T* element) {
    auto pElement = this->find_bag_element(element);
    if (pElement == this->pContainer->end()) {
      BagElement<T>* pNewElement = new BagElement<T> {element, 1};

      pContainer->insert(*pNewElement);
      cout << *element << " is newly added!" << endl;
      return true;
    } else {
      BagElement<T>* pNewElement = new BagElement<T> {element, pElement->size+1};

      pContainer->erase(*pElement);
      pContainer->insert(*pNewElement);
      cout << *element << " is updated!" << endl;
      return false;
    }
  }

  const T* remove(T* element) {
    auto pElement = this->find_bag_element(element);
    if (pElement == this->pContainer->end()) {

      cout << *element << " can't be removed (not exists)!" << endl;
      return nullptr;
    } else {
      if (pElement->size > 1) {
        BagElement<T>* pNewElement = new BagElement<T> {element, pElement->size-1};
        pContainer->erase(*pElement);
        pContainer->insert(*pNewElement);
        cout << *element << " was removed (decreased by 1)!" << endl;
      } else {
        pContainer->erase(*pElement);
        cout << *element << " was removed (dropped from the set)!" << endl;
      }
      return pElement->content;
    }
  }

  auto find_bag_element(T* element) {
    BagElement<T> searchable(element, 0);
    return pContainer->find(searchable);
  }

  const T* find(T* element) {
    auto searchResult = find_bag_element(element);
    if (searchResult == this->pContainer->end()) {
      cout << *element << " is NOT found" << endl;
      return nullptr;
    } else {
      cout << *element << " exists: " << searchResult->size << endl;
      return searchResult->content;
    }
  }
};


template<typename T>
void print(T* ptr) {
  if (ptr !=  nullptr) {
    cout << *ptr << endl;
  } else {
    cout << "[can't find any]" << endl;
  }
}

int main() {
  int a = 100, b=20, c = 100;

  Bag<int> bag;
  bag.add(&a);
  bag.remove(&a);
  bag.remove(&a);
  bag.add(&a);
  bag.add(&a);
  bag.remove(&a);

  print(bag.find(&b));
  print(bag.find(&c));


  string x = "Hoge hoge", y = "Foo Hoge", z = "Hoge hoge";

  Bag<string> bag_str;
  bag_str.add(&x);
  print(bag_str.remove(&x));
  print(bag_str.remove(&x));
  bag_str.add(&x);
  bag_str.add(&x);

  print(bag_str.find(&y));
  print(bag_str.find(&z));
}
