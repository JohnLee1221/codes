#include <iostream>

void print() {}

template <typename T, typename... Types>
void print(const T& firstArg, const Types... args) {
  std::cout << sizeof...(args) << "\t" << firstArg <<std::endl;
  print(args...);
}

template <typename T>
T my_max(T value) {
  return value;
}

template <typename T, typename... Types>
T my_max(const T& firstArg, const Types... Tail) {
  return std::max(firstArg, my_max(Tail...));
}

template <typename... Values> class tuple;
template<> class tuple<> {};

template<typename Head, typename... Tail>
class tuple<Head, Tail...>
  : private tuple<Tail...> {
  typedef tuple<Tail...> inherited;
 public:
  tuple() {}
  tuple(Head v, Tail... vtail) : head_(v), inherited(vtail...) {}
  Head& head() {return head_;}
  inherited& tail() {return *this;}
 protected:
  Head head_;
};

void func_01() {
  print(1, "Hello World", 'A', 3.1415926);
}

void func_02() {
  std::cout << my_max(5,8,6,4,2,7) << std::endl;
}

void func_03() {
	tuple<int, float, std::string> t(1, 2.3, "hello");
	std::cout << t.head() << " " << t.tail().head() << " " << t.tail().tail().head() << std::endl;
}

int main() {
  // func_01();
  // func_02();
  func_03();

	return 0;
}
