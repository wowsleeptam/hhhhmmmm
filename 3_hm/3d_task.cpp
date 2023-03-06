#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int number, value, answer, flag = 0;
// Ввод количества элементов массива
    std::cout << "Write a quantity of number in array \n" << "number is = ";
    std::cin >> number;
    std::vector<int> array(number);

// Заполение массива
    std::cout << "Write values of your array \n";
    for (size_t i = 0; i < number; i++) {
      std::cin >> value;
      array[i] = value;
    }

// Исследуем на монотонность
    for (size_t i = 1; i < number; i++) {
      if (array[i-1] > array[i]){
        std::cout << "Your array is not sorted. I do it inself. Bzzzzzzzz (start sorting) \n" ;
        int i = 1, j;
        while (i < array.size()){
          j = i;
          while ((j>0) && (array[j-1] > array[j])) {
              std::swap(array[j-1], array[j]);
              j = j - 1;
          }
          i = i + 1;
        }
        std::cout << "Your sorted array = { ";
        for (int n : array) {
            std::cout << n << " ";
        }
        std::cout << "} \n";
      }

    }
// Вводим число, которое нужно найти
  std::cout << "Write a number what you want to find in array \n";
  std::cin >> answer;

// Поиск
    int Left_value = 0, Right_value = number - 1, middle;
    while (Left_value <= Right_value){
      middle  = (Left_value + Right_value) / 2;
      if (array[middle] < answer)
        Left_value = middle + 1;
      else if (array[middle] > answer)
        Right_value = middle - 1;
      else {
        std::cout << "Your value is in array. The index is = " << middle + 1;
        return 0;
      }
    }
  std::cout <<"Your value is not in array";
}
