#include <iostream>
#include <string>
#include <cstring>
#include<type_traits>

// База рекурсии

bool print_without_op(){return 0;}

// Реализация "в лоб". По рекурсии достигаем самого последнего элемента, а уже после возвращаем сумму последнего
// элемента и предыдущего
template <typename Head, typename... Tail>
bool print_without_op(const Head& head, const Tail&... tail){
  if ((sizeof...(tail)) == 0) return std::is_same<decltype(head), int>::value;
  else return print_without_op(tail...) + print_without_op(head);
  std::cout <<
}

int main(){
int a = 2;
  std::cout << print_without_op("asd", "sssssss", a) << '\n';
}
