#include <iostream>
#include <vector>
#include <utility>


std::vector<int> sort(std::vector<int> array);
int main()
{
    int number, value;
// Ввод количества элементов массива
    std::cout << "Write a quantity of number in array \n";
    std::cin >> number;
    std::vector<int> array(number);

// Заполение массива
    for (size_t i = 0; i < number; i++) {
      std::cin >> value;
      array.at(i) = value;
    }
// Сортировка
    array = sort(array);

// Вывод массива
    std::cout << "Your sorted array = { ";
    for (int n : array) {
        std::cout << n << " ";
    }
    std::cout << "}";
}

std::vector<int> sort(std::vector<int> array){
  int j;
  for (size_t i = 1; i < array.size(); i++) {
    j = i;
    while ((j>0) && (array.at(j-1) > array.at(j))) {
        std::swap(array.at(j-1), array.at(j));
        j = j - 1;
    }
  }
  return array;
}
