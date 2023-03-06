#include <iostream>
#include <string>
#include <cstring>

// База рекурсии
int print_without_op(){return 0;}

// Реализация "в лоб". По рекурсии достигаем самого последнего элемента, а уже после возвращаем сумму последнего
// элемента и предыдущего
template <typename Head, typename... Tail>
bool print_without_op(const Head& head, const Tail&... tail){
  if ((sizeof...(tail)) == 0) return head;
  else return print_without_op(tail...) + print_without_op(head);
}


int main(){
  std::cout << print_without_op(1,2,3,5,1) << '\n';

}
