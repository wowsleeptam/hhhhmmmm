#include <iostream>

#include <type_traits>
#include <cstdint>
// База рекурсии
bool print_without_op(){return 0;}

// Реализация "в лоб". По рекурсии достигаем самого последнего элемента, а уже после возвращаем сумму последнего
// элемента и предыдущего
template <typename Head, typename... Tail>
bool print_without_op(const Head& head, const Tail&... tail){
  // std::cout << std::is_same<decltype(head), int>::value;
  // std::cout << typeid(head).name();
  if ((sizeof...(tail)) == 0) return std::is_same<decltype(head), int>::value;
  else return print_without_op(tail...) + print_without_op(head);
}

int main(){
  float a = 1;
  float e = 0;
  float b = 0.2;
  std::cout << print_without_op(a,e, b) << '\n';
  // std::cout << std::is_same<decltype(a), int>::value;

}
