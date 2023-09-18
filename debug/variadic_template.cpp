#include <iostream>

template<typename... Values>
class tuple;

template<>
class tuple<> {};

template<typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
  using interited = tuple<Tail...>;
 public:
  tuple() = default;
  tuple(Head v, Tail... vtail) : head_(v), inherited(vtail...) {}
  Head& head() {return head_};
 protected:
  Head head_;
};