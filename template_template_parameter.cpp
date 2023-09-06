#include <iostream>
#include <vector>
#include <list>

// template<typename T>
// using Vec = std::vector<T>;

// template<typename T, template<typename> class Container>
// void TypeJudge(const std::initializer_list<T>& init_list) {
//   using Iterator = typename Container<T>::iterator;
//   using Type = typename std::iterator_traits<Iterator>::value_type;
//   if (std::is_same<Type, int>::value) {
//     std::cout << "type is same : int" << std::endl;
//   } else {
//     std::cout << "type is different" << std::endl;
//   }

//   Container<T> c = init_list;
//   std::cout << "print the elements of container" << std::endl;
//   for (const auto& elem : c) {
//     std::cout << elem << "\t";
//   }
//   std::cout << std::endl;
// }

// int main() {
//   TypeJudge<int, Vec>({1, 2 ,3});

//   return 0;
// }

using MyVector = std::vector<int>;

int main() {
  using Iterator = typename MyVector::iterator;
  using TypeValue = typename std::iterator_traits<Iterator>::value_type;
  // if (std::is_same<TypeValue, int>::value) {
  //   std::cout << "type is same : int" << std::endl;
  // } else {
  //   std::cout << "type is different" << std::endl;
  // }
  MyVector vec {1, 2, 3};

  // std::cout << decltype(vec[0]) << std::endl;

  std::cout << std::is_same<decltype(vec[0]), double>::value << std::endl;

  return 0;
}