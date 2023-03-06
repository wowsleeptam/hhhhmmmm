#include<iostream>
// Факториал
int fib(int n);

int main(){
  int n;

  std::cout << "Write index of Fibanachi numbers = ";
  std::cin >> n;
  std::cout << "Your number is " << fib(n);
}
int fib(int n){
  return (n > 2) ? fib(n-1)+fib(n-2) : 1;
}
