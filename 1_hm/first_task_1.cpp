#include <iostream>
#include <string>
#include <iomanip>

int main(){
  std::string name;
  std::string cash;
  int price;
  int temp;


    std::cout <<"Product\'s name: ";
    std::cin >> name;

    std::cout <<"Product\'s price: ";
    std::cin >> price;

    std::cout <<"Is cash-back available for this product: ";
    std::cin >> cash;

    std::cout <<"Maximum storing temperature: ";
    std::cin >> temp;

    std::cout << std::endl << name << std::endl;
    std::cout <<"Price:........";
    std::cout << std::setfill('0') << std::setw(8)<< std::right << std::uppercase << std::hex << price << std::endl;
    std::cout << "Has cash-back:" <<  std::setw(8) << std::setfill('.') << std::right << cash << std::endl;
    std::cout << "Max temerature:" << std::setw(7) << std::dec << std::right <<
    std::showpos << temp;
    return 0;
}
