#include <functional>
#include <vector>
#include <iostream>
#include <string>
int main()
{


// Объявление и заполенение массива
int n;
std::cout << "Write quantity of array ";
std::cin >> n;
std::vector<int> arr(n);
for (size_t i = 0; i < n; i++) std::cin >> arr.at(i);

auto sort1 = [](std::vector<int> v){return (v = std::sort(v.begin(), v.end()));};
auto sort2 = [](std::vector<int> v){return (v = std::sort(v.begin(), v.end(), std::greater<int>()));};

std::vector<int> answer1 = sort1(arr);
std::vector<int> answer2 = sort2(arr);

// Вывод массива
    std::cout << "Your soted array: ";
    for (size_t i = 0; i < n; i++) {
      std::cout << answer1.at(i) << " ";
    }
    std::cout << " ";
    std::cout << "Your soted array: ";
    for (size_t i = 0; i < n; i++) {
      std::cout << answer1.at(i) << " ";
    }
    return 0;
}

}
