#include <iostream>


int main(){
  int x,y;
  std::cout << "Write x and y to swape ";
  std::cout << std::endl << "x = ";
  std::cin >> x;
  std::cout << "y = ";
  std::cin >> y;

  x+=y;
  y-=x;
  x+=y;
  y=-y;

  std::cout << "x = " << x << " and y = " << y;
}
