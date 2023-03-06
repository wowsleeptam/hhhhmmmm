#include <functional>
#include <vector>
#include <iostream>
#include <string>
int main()
{
// Инициализация массива из лямбда-функций
  std::vector<std::function<double(double,double)>> v =
  {
      [](double x, double y) { return x * y; },
      [](double x, double y) { return x + y; },
      [](double x, double y) { return x - y; },
      [](double x, double y) { return x / y; }
  };
// Инициализация массива из названий операций
  std::vector<std::string> Name =  {"Сomposition" ,"Sum", "Subtraction", "Division"};

// Ввод значений
  double number_1, number_2;
  std::cout << "Write 2 double numbers \n";
  std::cin >> number_1 >> number_2;
  std::cout << "The results are \n";

// Вывод результата
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << Name.at(i) << " = " << v[i](number_1, number_2) << std::endl;
  }
}
