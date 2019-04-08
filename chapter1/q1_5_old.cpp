#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
#include <string>

using namespace std;

template <typename T>
struct BagElement {
public:
  vector<T>* pContents;

  BagElement(T newContent) : pContents(new vector<T>) {
    pContents->push_back(newContent);
  }

  BagElement<T> push_back(T newContent) {
    pContents->push_back(newContent);
  }

  bool operator == (const BagElement<T>& right) const {
    return hash<T>() (*pContents->front) == hash<T>() (*right->pContents->front);
  }
};

// namespace std {
//   template<typename T>
//   struct hash<BagElement<T>> {
//     size_t operator() (const BagElement<T>& element) const {
//       return hash<T>() (element.content);
//     }
//   };
// }


// template <typename T>
// class Bag {
// public:
//   unordered_set<BagElement<T>>* pContainer;
 
//   Bag() : pContainer(new unordered_set<BagElement<T>>) {};
//   ~Bag() {
//     delete pContainer;
//   }

//   void add(T element) {
//     Bag<T>* pResult = this->find(element);

//     if (pResult == nullptr) {
//       BagElement<T> const newElement(element, 0);
//       pContainer->insert(newElement);
//       cout << element << " is newly added!" << endl;
//     } else {
//       (*pResult)++;
//       cout << element << " is incremented!" << endl;
//     }
//   }

//   const T* find(T element) {
//     BagElement<T> const searchable(element, 0);
//     auto searchResult = pContainer->find(searchable);
//     // delete &searchable;
//     // return searchResult == pContainer->end() ? nullptr : &searchResult->content;
//     if (searchResult == pContainer->end()) {
//       return nullptr;
//     } else {
//       return &searchResult->content;
//     }
//   }
// };

// template<typename T>
// void print(T* ptr) {
//   if (ptr !=  nullptr) {
//     cout << *ptr << endl;
//   } else {
//     cout << "[can't find any]" << endl;
//   }
// }

int main() {
  BagElement<string> element("hoge");
  element.push_back("Foo");
}


