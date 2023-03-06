#include<iostream>
#include<string>
#include "2_add.hpp"

int main(){
  Drob first_value, second_value;
  unsigned int first_up, first_down;
  std::cin >> first_value >> second_value;
  std::cout <<"first + second = "<<  first_value + second_value;
  std::cout <<"first - second = "<< first_value - second_value;
  std::cout <<"first * second = "<< first_value * second_value;
  std::cout <<"first / second = "<< first_value / second_value;
  std::cout <<"++first = "<< ++first_value;
  std::cout <<"--second = " << --second_value;
  std::cout << "Write new values to first = ";
  std::cin >> first_up >> first_down;
  first_value.set_up(first_up);
  first_value.set_down(first_down);
  std::cout <<"first value, using setter and getter = " <<first_value.get_up() <<"/"<<first_value.get_down() <<std::endl;
  std::cout <<"Is first == second " << std::boolalpha << (first_value == second_value) << '\n';
  std::cout <<"Is first >= second " << std::boolalpha << (first_value >= second_value) << '\n';
  std::cout <<"Is first <= second " << std::boolalpha << (first_value <= second_value) << '\n';
  std::cout << "Is first != second " << std::boolalpha << (first_value != second_value) << '\n';
  std::cout << "Is first > second " <<std::boolalpha << (first_value > second_value) << '\n';
  std::cout << "Is first < second " <<std::boolalpha << (first_value < second_value) << '\n';



}
