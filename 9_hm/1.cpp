#include <cmath> // для sqrt()
#include <iostream>
enum class Exception {
  Int = '>',
  Not_int = '<'
};

void f(int){std::cout << "enum";};

int main() {
 std::cout << "Enter a number: ";
 double a_double;
 int a_int;
 std::cin >> a_double >> a_int;
 try {
   throw a_int;
   throw a_double;
 }
 catch (int) // обработка исключений типа const char*
 {
   std::cerr << "Error: " << std::endl;
 }
 catch (double){
   f(a_int);
 }
 return 0;
}
