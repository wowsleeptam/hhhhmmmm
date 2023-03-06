#include <iostream>
#include <string>
#include <vector>

bool check_letter(char letter);
bool check_sign(char letter);
int main(){
  std::string str;
  static std::vector<std::string> Quant;
  std::string add_str = "";

// Ввод строки
    std::cout << "Write text, please \n";
    std::getline(std::cin, str);


  for (size_t i = 0; i < std::size(str); i++) {

// Проверка каждой буквы (строчные и заглавные)
// Основная идея: если итерируемый сивол - буква, то просто добавляем во вспомогательную строку add_str. Когда встречаем знак применания, заносим данные из add_str в первую ячейку Quant, затем заносим знак преминания

    if (check_letter(str.at(i)) == 1) {

// Проверяем последнюю букву

      if (i == (std::size(str))-1){
        add_str += str.at(i);
        Quant.push_back(add_str);
      }
      add_str += str.at(i);
    }
// Проверка Знаков преминания
    else if (check_sign(str.at(i)) == 1){
      if (add_str.size() != 0){
        Quant.push_back(add_str);
        add_str.clear();
        add_str += str.at(i);
        Quant.push_back(add_str);
        add_str.clear();
      }

      else {
        add_str += str.at(i);
        Quant.push_back(add_str);
        add_str.clear();

      }
    }

// Проверка пробелаю.
    else if (static_cast<int>(str.at(i)) == static_cast<int>(' ')){
      if (add_str.size() != 0){
        Quant.push_back(add_str);
        add_str.clear();
      }
    }

// Проверка дефиса "-"
    else if (static_cast<int>(str.at(i)) == static_cast<int>('-')){
      if (check_letter(str.at(i-1)) == 1){
        add_str += str.at(i);
      }
      else {
        add_str += str.at(i);
        Quant.push_back(add_str);
        add_str.clear();
      }
    }

// Вывод vector из символов строки
  }
  std::cout << "Your sorted array = { ";
  for (std::string n : Quant) {
      std::cout << n << " | ";
  }
  std::cout << "}";

}


bool check_letter(char letter){
  if (((static_cast<int>(letter) <= static_cast<int>('z')) && (static_cast<int>(letter) >= static_cast<int>('a')))  || ((static_cast<int>(letter) <= static_cast<int>('Z')) && (static_cast<int>(letter) >= static_cast<int>('A'))))
    return 1;
  else
    return 0;
}

bool check_sign(char letter){
  if((static_cast<int>(letter) == static_cast<int>('!') || (static_cast<int>(letter) == static_cast<int>('.')) || (static_cast<int>(letter) == static_cast<int>('?')) || (static_cast<int>(letter) == static_cast<int>(','))))
    return 1;
  else
    return 0;
}
