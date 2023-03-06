#include <iostream>
#include <cmath>
int main(){
  double a,b,c;
  double Discr;
  double x1,x2;
  std::cout << "You have a*x^2 + b*x + c = 0. Write a,b,c" << std::endl << "a = ";
  std::cin >> a;
  std::cout << "b = ";
  std::cin >> b;
  std::cout<<  "c = ";
  std::cin >> c;

  Discr = b*b - 4*a*c;
  if ((a == 0) && (b == 0) && (c != 0)){
    std::cout << "The equation can not be solved";
  }
  else if ((a == 0) && (b == 0) && (c == 0)){
    std::cout << "The equation is always right ";
  }
  else if (a == 0){
    x1 = -c/b;
    std::cout << "The solution is " << x1;
    return 0;
  }
  else if (Discr < 0)
    std::cout << "The equation can not be solved in real numbers";
  else if (Discr == 0){
    x1 = -b/(2*a);
    std::cout << "The solution is " << x1;
  }
  else if (Discr > 0){
    x1 = (-b+sqrt(Discr))*0.5/a;
    x2 = (-b-sqrt(Discr))*0.5/a;
    std::cout << "The solutions are " << x1 << " and " << x2;
  }

  return 0;
}
