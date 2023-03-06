#include <iostream>
#include <string>
#include <vector>
class Group {
public:

// Везде поменял работу с указателями на работу с векторами

  Group(std::string name, std::string surname, int age , int curr_marks , int prev_marks): m_name(name), m_surname(surname), m_age(age),
  m_curr_marks(curr_marks), m_prev_marks(prev_marks){
  m_compare_marks[0] = curr_marks;
  m_compare_marks[1] = prev_marks;
  m_compare_marks[2] = curr_marks - prev_marks;
}

  Group():  m_name("None"), m_surname("None"), m_age(0),
  m_curr_marks(0), m_prev_marks(0){
    m_compare_marks[0] = 0;
    m_compare_marks[1] = 0;
    m_compare_marks[2] = 0;}

// Фунция, которая проверяет значения m_compare_marks на изменения
bool check(){
  if ((m_compare_marks[0] != m_curr_marks) || (m_compare_marks[1] != m_prev_marks))
    return 0;
  else return 1;
}

  void print_average_mark(){
    // Сначала мы проверяем, изменялось ли значение. Если изменялось. то присваиваем новые значения.
    if (check() == 1) std::cout << "Sum previos marks = " << m_compare_marks[0] <<  ", Compare: " << m_compare_marks[2];
    else{
      m_compare_marks[0] = m_curr_marks;
      m_compare_marks[1] = m_prev_marks;
      m_compare_marks[2] = m_curr_marks - m_prev_marks;
      std::cout << "Sum previos marks = " << m_compare_marks[0] <<  ", Compare: " << m_compare_marks[2];
    }
  }


  void print_information(){
    if (check() == 1) std::cout << "Name: "<< m_name <<", Surname: "<< m_surname << ", Age: " << m_age << '\n';
    else{
      m_compare_marks[0] = m_curr_marks;
      m_compare_marks[1] = m_prev_marks;
      m_compare_marks[2] = m_curr_marks - m_prev_marks;
      std::cout << "Name: "<< m_name <<", Surname: "<< m_surname << ", Age: " << m_age << '\n';
    }
  }
// Сеттеры и геттеры
 int get_curr_mark() {return m_curr_marks;}
 int get_prev_mark() {return m_prev_marks;}
 void set_curr_mark(int curr_mark) { m_curr_marks = curr_mark;}
 void set_prev_mark(int prev_mark) { m_prev_marks = prev_mark;}

  void compare(){
    if (m_compare_marks[2] > 0)
      std::cout << ". This student improved his marks";
    else if (m_compare_marks[2] < 0)
      std::cout << ". He failed to improve his marks";
    else
      std::cout << ". He neither improve, nor fail";
  }

// Здесь заменил деструктор. Не знаю, зачем он здесь нужен, ибо вектор сам удаляется, но пусть будет)
  ~Group(){
  }
private:
  std::string m_name, m_surname;
  int m_age;
  int m_curr_marks;
  int m_prev_marks;
// Заменил прямую работу с памятью на стандартный вектор
  std::vector<int> m_compare_marks = {0,0,0};

  friend void print_curr_marks(Group person);
};
