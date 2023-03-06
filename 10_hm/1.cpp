#include <iostream>
#include <vector>
#include <string>


template <typename T>
bool find(std::vector<T>& v, const T& b){
  int answer = 0;
  for (size_t i = 0; i < v.size(); i++) {
    if (v.at(i) == b) answer++;
  }
  return answer;
}
template <typename T>
bool find(T *v, const T& b, const int& count){
  int answer = 0;
  std::cout << "";
  for (size_t i = 0; i < count; i++) {
    if (*(v+i) == b) answer++;
  }
  return answer;
}

int main()
 {
 std::vector<int> v1 = {1,2,3,4};
 std::vector<char> v2 = {'c', 's', '\n'};
 int v3[5] = {0,-1,2,-6,-9};
 int a1 = 1000;
 std::cout << "Is "<< a1 << " in vector 1? " << std::boolalpha << find(v1,a1) << '\n';
 char a2 = 'c';
 std::cout << "Is "<< a2 << " in vector 2? " << std::boolalpha << find(v2,a2) << '\n';
 int a3 = 0;
 std::cout << "Is "<< a3 << " in vector 3? " << std::boolalpha << find(v3,a3,5) << '\n';

 return 0;
 }
