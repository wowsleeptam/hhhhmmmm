#include <iostream>
#include <string>
#include <iomanip>

int main(){
  int variant=1, variant_1=1;
  int measure, wanted_tranfer;
  double value = 0;
  std::string answer;
  std::cout << "Write your value" << std::endl;
  std::cin >> value;
  while (variant!=0){
    std::cout << "In what system do you want to transfer" << std::endl;
    std::cout << "1) SI; 2)CGS; 3)-G, -M, -k and others; 4)Reset your value 0)exit" << std::endl;
    std::cin >> variant;
    switch(variant){
      case 1:
        std::cout << std::endl << "Write first letters of name of measure and value " << std::endl;
        std::cout << "1) cm -> m "  << std::setfill(' ') << std::setw(8) << "7) dyne -> N" << std::endl;
        std::cout << "2) g - > kg "  << std::setfill(' ') << std::setw(8) << "8) erg -> J"<< std::endl;
        std::cout << "3) s -> s "  << std::setfill(' ') << std::setw(8) << "9) erg/s -> W`" << std::endl;
        std::cout << "4) cm/c -> m/s "  << std::setfill(' ') << std::setw(8) << "10) Ba -> Pa" << std::endl;
        std::cout << "5) gal - > m/s^2 "  << std::setfill(' ') << std::setw(8) << "11) P -> Pa*s" << std::endl;
        std::cout << "6) St -> m^2/s " << std::endl;
        std::cin >> measure;
        switch(measure) {
          case 1:
            value = value / 100;
            answer = "m";
          break;
          case 2:
            value = value / 1000;
            answer = "kg";
          break;
          case 3:
            value = value;
            answer = "s";
          break;
          case 4:
            value = value / 100;
            answer = "m/s";
          break;
          case 5:
            value = value / 100;
            answer = "m/s^2";
          break;
          case 6:
            value = value * 0.0001;
            answer = "m^2/s";
          break;
          case 7:
            value = value * 0.00001;
            answer = "N";
          break;
          case 8:
            value = value / 10000000;
            answer = "J";
          break;
          case 9:
            value = value / 10000000;
            answer = "W";
          break;
          case 10:
            value = value / 10;
            answer = "Pa";
          break;
          case 11:
            value = value / 10;
            answer = "Pa*s";
        }
        std::cout << "You answer is " << value << answer;
      break;
      case 2:
      std::cout << "Write first letters of name of measure and value " << std::endl;
      std::cout << "1) cm <- m"  << std::setfill(' ') << std::setw(8) << "7) dyne <- N" << std::endl;
      std::cout << "2) g <-  kg"  << std::setfill(' ') << std::setw(8) << "8) erg <- J"<< std::endl;
      std::cout << "3) s <- s"  << std::setfill(' ') << std::setw(8) << "9) erg/s <- W`" << std::endl;
      std::cout << "4) cm/c <- m/s"  << std::setfill(' ') << std::setw(8) << "10) Ba <- Pa" << std::endl;
      std::cout << "5) gal <-  m/s^2"  << std::setfill(' ') << std::setw(8) << "11) P <- Pa*s" << std::endl;
      std::cout << "6) St <- m^2/s" << std::endl;
      std::cin >> measure;


      switch(measure) {
        case 1:
          value = value * 100;
          answer = "cm";
        break;
        case 2:
          value = value * 1000;
          answer = "g";
        break;
        case 3:
          value = value;
          answer = "s";
        break;
        case 4:
          value = value * 100;
          answer = "cm/s";
        break;
        case 5:
          value = value * 100;
          answer = "gal";
        break;
        case 6:
          value = value / 0.0001;
          answer = "St";
        break;
        case 7:
          value = value / 0.00001;
          answer = "dyne";
        break;
        case 8:
          value = value * 10000000;
          answer = "erg";
        break;
        case 9:
          value = value * 10000000;
          answer = "erg/s";
        break;
        case 10:
          value = value * 10;
          answer = "Ba";
        break;
        case 11:
          value = value * 10;
          answer = "P";
        }
      break;
      case 3:
        std::cout << "Write first letters of name of measure, value and in what first lettres of name you want to tranfer" << std::endl;
        std::cout << "1) G"  << std::setfill(' ') << std::setw(8) << "6) d" << std::endl;
        std::cout << "2) M"  << std::setfill(' ') << std::setw(8) << "7) c"<< std::endl;
        std::cout << "3) k"  << std::setfill(' ') << std::setw(8) << "8) m" << std::endl;
        std::cout << "4) h"  << std::setfill(' ') << std::setw(8) << "9) u" << std::endl;
        std::cout << "5) da"  << std::setfill(' ') << std::setw(8) << "10) n" << std::endl;
        std::cout << "11) SI" << std::endl;
        std::cin >> measure >> wanted_tranfer;

        switch(measure) {
          case 1:
            value = value * 1000000000;
          break;
          case 2:
            value = value * 1000000;
          break;
          case 3:
            value = value * 1000;
          break;
          case 4:
            value = value * 100;
          break;
          case 5:
            value = value * 10;
          break;
          case 6:
            value = value * 0.1;
          break;
          case 7:
            value = value * 0.01;
          break;
          case 8:
            value = value * 0.001;
          break;
          case 9:
            value = value * 0.000001;
          break;
          case 10:
            value = value * 0.000000001;
          break;
          case 11:
            value = value;
        }


        switch(wanted_tranfer) {
          case 1:
            value = value / 1000000000;
            answer = "G";
          break;
          case 2:
            value = value / 1000000;
            answer = "M";
          break;
          case 3:
            value = value / 1000000;
            answer = "k";
          break;
          case 4:
            value = value / 1000;
            answer = "h";
          break;
          case 5:
            value = value / 100;
            answer = "da";
          break;
          case 6:
            value = value / 10;
            answer = "d";
          break;
          case 7:
            value = value / 0.1;
            answer = "c";
          break;
          case 8:
            value = value / 0.001;
            answer = "m";
          break;
          case 9:
            value = value / 0.000001;
            answer = "u";
          break;
          case 10:
            value = value / 0.000000001;
            answer = "n";
          break;
          case 11:
            value = value;
            answer = "in SI system";
          break;
        }

        std::cout << "The answer = " << std::scientific << value << " " << answer << std::endl;

      break;
      case 4:
        std::cout << "Write your value" << std::endl;
        std::cin >> value;
      break;
    }

  }
  return 0;
}
