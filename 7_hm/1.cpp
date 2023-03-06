#include<iostream>
#include<vector>
#include<utility>
#include<string>

class Class{

public:


  Class(int *array, int count_1, std::vector<int> v, int count_2, std::string str):
  m_array(array), m_count_1(count_1), m_v(v), m_count_2(count_2), m_str(str){
    std::cout <<"\nConstuctor";
  };


  Class(): m_array(nullptr), m_count_1(0), m_v(0), m_count_2(0), m_str(){
    std::cout <<"\nDefault Constuctor";
  };


  Class(const Class &group) :
  m_array(group.m_array), m_count_1(group.m_count_1), m_v(group.m_v), m_count_2(group.m_count_2), m_str(group.m_str){};


  Class(const Class &&group) :
  m_array(group.m_array), m_count_1(group.m_count_1), m_v(group.m_v), m_count_2(group.m_count_2), m_str(group.m_str){};


  ~Class(){
    std::cout << "\nDestuctor";
    delete m_array;
  }

  void print_array(){
    if (m_array != nullptr){
      std::cout << "\nArray: ";
      for (size_t i = 0; i < m_count_1; i++) {
        std::cout << *(m_array+i) << ' ';
      }
    }
    else std::cout << "\nNo values";
  }


//Функция-член выводы длины динамического массива и вектора
  void print_count_1(){
    std::cout << "\nLength of your dinamic array = " << m_count_1;
  }
  void print_count_2(){
    std::cout << "\nLength of vector = " << m_count_2;
  }

// Вывод вектора
  void print_vector(){
    std::cout << "\nValues of vector are: ";
    for (size_t i = 0; i < m_v.size(); i++) {
      std::cout << std::move(m_v.at(i)) << " ";
    }
  }
// Вывод строки
  void print_str(){
    std::cout << "\nString: ";
    for (size_t i = 0; i < m_str.size(); i++) {
      std::cout << std::move(m_str.at(i)) << " ";
    }
  }

//Фукнция-член суммирования массива и вектора
  void sum(){
    int sum_1 = 0, sum_2 = 0;
    for (size_t i = 0; i < m_count_1; i++) {
      sum_1 += *(m_array+i);
    }
    for (size_t i = 0; i < m_v.size(); i++) {
      sum_2 += m_v.at(i);
    }
    std::cout << "\nSum of array = "<< sum_1 << ". Sum of vector = " << sum_2;
  }


private:
  int *m_array = new int(m_count_1);
  int m_count_1;
  int m_amount;
  std::vector<int> m_v;
  int m_count_2;
  std::string m_str;

};


int main(){
  
  // Заполнения массива, вектора, строки и так далее
  std::string str;
  int count_1, count_2;
  std::cout << "Write your string ";
  std::getline(std::cin, str);
  std::cout << "Write count_1 of array and count_1 of your vector ";
  std::cin >> count_1 >> count_2;
  int value;
  int *array = new int(count_1);
  std::cout << "Your values of dinamic array are: ";
  for (size_t i = 0; i < count_1; i++) {
    std::cin >> value;
    *(array+i) = value;
  }
  std::vector<int> v;
  std::cout << "Your values of vector: ";
  for (size_t i = 0; i < count_2; i++) {
    std::cin >> value;
    v.push_back(std::move(value));
  }


  Class group_1(array, count_1, v, count_2, str);
  Class group_2;
  Class group_3(group_1);
  Class group_4(group_3);
  Class full_group[4] = {group_1, group_2, group_3, group_4 };
  Class *ptr = full_group;

// Вывод всех фукнций-членов
  for (size_t i = 0; i < 4; i++) {
    Class group = *(ptr + i);
    std::cout << "\nFor " << i+1 << " group";
    group.print_array();
    group.print_count_1();
    group.print_vector();
    group.print_str();
    group.sum();
    std::cout << '\n';
  }


//Освобождаем память
  delete[] array;

}
