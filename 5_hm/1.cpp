#include <iostream>
#include <string>
#include <vector>


// Объялление данных и резервирование памяти для compare_marks
struct Group {
  std::string m_name, m_surname;
  int m_age;
  int m_curr_marks;
  int m_prev_marks;
  int *compare_marks = new int(3);

// Добавил списк инициализации. Также compare_marks инициализируется в конструкторе
  Group(std::string name = "None", std::string surname = "None", int age = 0, int curr_marks = 0, int prev_marks = 0 ): m_name(name), m_surname(surname), m_age(age),
  m_curr_marks(curr_marks), m_prev_marks(prev_marks){
  *compare_marks = curr_marks;
  *(compare_marks + 1) = prev_marks;
  *(compare_marks + 2) = curr_marks - m_prev_marks;

}

// Фукнция, которая выводит суммарную оценку за прошлый семест, за текущий семестр и разницу.
  void print_average_mark(){
    std::cout << "Sum previos marks = " << *compare_marks << ". Sum current marks: " << *(compare_marks + 1) << ", Compare: " << *(compare_marks + 2);
  }

// Выводит имя, фамилию и возраст студента
  void print_information(){
    std::cout << "Name: "<< m_name <<", Surname: "<< m_surname << ", Age: " << m_age << '\n';
  }

// Сравнивает суммарные оценкти за предыдущий и текущий семестры и делает вывод, все ок или не ок
  void compare(){
    if (*(compare_marks + 2) > 0)
      std::cout << ". This student improved his marks";
    else if (*(compare_marks + 2) < 0)
      std::cout << ". He failed to improve his marks";
    else
      std::cout << ". He neither improve, nor fail";
  }


  ~Group(){
    delete[] compare_marks;
  }
};


int main(){
  Group Maxim("Maxim", "Maximov", 18, 45,34);
  Group Alexey("Alexey", "Kozlov", 19, 50, 50);
  Group Lisa{"Lisa", "Pavlovna", 17, 49, 50};
  Group Slava{"Slava", "Ivanova", 20, 10, 15};
  Group Matvey{"Matvey", "Popkin", 18, 36, 43};
  Group Pavel{"Pavel", "Snejok", 19, 19, 35};
  Group Unknown;

  int n = 8;
// Вместо вектора сформировал статический массив
  Group array[8] = {Maxim, Alexey, Lisa, Slava, Matvey, Pavel, Unknown};
  Group *ptr = array;
  for (size_t i = 0; i < 7; i++) {

// Здесь пришлось пришлось обращаться через [], ибо метод .at() у меня не сработал
    array[i].print_information();
    array[i].print_average_mark();
    array[i].compare();
    std::cout << '\n' << '\n';
  }
}
