#include <iostream>
#include <vector>
#include <iomanip>

struct Date {
  unsigned short m_id    : 14;    // 0..16 383
  bool m_inhand     : 1;    // 0..1
  unsigned short m_Day : 9;    // 0..511
  unsigned short m_Month    : 4;    // 0..15
  unsigned short m_Year     : 11;    // 0..2047
  unsigned short m_section     : 4;    // 0..15
  unsigned short m_chapter     : 7;    // 0..127
  unsigned short m_pages  : 15;    // 0..32 767

// Конструктор
  Date(int id = 0, int inhand = 0, int Day = 0, int Month = 0, int Year = 0, int section = 0, int chapter = 0, int pages = 0):
  m_id(id), m_inhand(inhand), m_Day(Day), m_Month(Month),
  m_Year(Year), m_section(section), m_chapter(chapter), m_pages(pages){
  }

// Фукнция вывода времени
  void print(){
    std::cout << "The book: 1)Id - "  <<m_id << "; 2)Inhand - " << std::boolalpha << m_inhand << "; 3) Date - " << m_Day << ':' << m_Month << ':' << m_Year << "; 4)Section - " << m_section << "; 5)Chapter -  " << m_chapter << "; 6) Pages - " << m_pages <<  '\n';

  }
};

int main(){
  int count;
  std::cout << "How many book do you want to add? ";
  std::cin >> count;


  std::vector<std::string> names = {"Id", "Inhand", "Day", "Month", "Year", "Section", "Chapter", "Pages"};
  std::cout << "Write information about the book: Id, it is inhand, the date, section, chapter, pages \n";

  std::vector<int> Values(8);
  std::vector<Date> Save_Data;

// Делаем цикл, в котором считываем данные и засовываем их в Save_Data
  for (size_t j = 0; j < count; j++) {
    {
    for (size_t i = 0; i < std::size(Values); i++) {
      std::cout << names.at(i) << " ";
      std::cin >> Values.at(i);

    }
    std::cout << "Next \n";
    Date time = {Values.at(0), Values.at(1), Values.at(2), Values.at(3), Values.at(4), Values.at(5), Values.at(6), Values.at(7)};

    Save_Data.push_back(time);
  }
}

// Вывод таблицы
  for (size_t i = 0; i < std::size(Save_Data); i++) {
    Save_Data.at(i).print();
  }
}
