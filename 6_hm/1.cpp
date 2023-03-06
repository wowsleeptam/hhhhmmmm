#include "1.hpp"


void print_curr_marks(Group person);

int main(int argc, char*argv[]){
  Group Maxim("Maxim", "Maximov", 18, 45,34);
  Group Alexey("Alexey", "Kozlov", 19, 50, 50);
  Group Lisa{"Lisa", "Pavlovna", 17, 49, 50};
  Group Slava{"Slava", "Ivanova", 20, 10, 15};
  Group Matvey{"Matvey", "Popkin", 18, 36, 43};
  Group Pavel{"Pavel", "Snejok", 19, 19, 35};
  Group Unknown;
  int first_value, second_value;

// Заменил размер массива с 8 на 7
  Group value, array[7] = {Maxim, Alexey, Lisa, Slava, Matvey, Pavel, Unknown};
  for (size_t i = 0; i < 7; i++) {
  // Заменил итерацию по массиву с указателя на обращение к значению []
    value = array[i];
    value.print_information();
    value.print_average_mark();
    print_curr_marks(value);
    value.compare();
    std::cout << '\n' << '\n';
  }
  // Изменяем значение оценок Maxim'а
  std::cout << "Write new values to Maxim's marks ";
  std::cin >> first_value >> second_value;
  Maxim.set_curr_mark(first_value);
  Maxim.set_prev_mark(second_value);

  std::cout << "Maxim's current marks = " << Maxim.get_curr_mark() << "; and previous marks = " << Maxim.get_prev_mark();


}
// Описание функции вывода текущих оценок
void print_curr_marks(Group person){
  std::cout <<". Curr " << person.m_prev_marks;
}
