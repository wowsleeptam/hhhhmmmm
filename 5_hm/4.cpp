#include <iostream>

// Добавил область видимости сюды
enum class Months { Jan = 1, Feb, Mar, Apr, May, Jun,
        Jul, Aug, Sep, Oct, Nov, Dec };

int func(months mon);
int main()
{
    int n;

    std::cout << "Write your month: \n";
    std::cin >> n;
    months mn = static_cast<months>(n);
    func(mn);

}



int func(months mon){
  const int day31 = 31, day28 = 28, day30 = 30;
  switch (mon)
  {
    //Чтобы мы имели доступ к enum, добавил months
      case months::Jan: std::cout << "January has " << day31 << " days" << std::endl; break;
      case months::Feb: std::cout << "February has "<< day28 << " days" << std::endl; break;
      case months::Mar: std::cout << "March has "<< day31<<" days" << std::endl; break;
      case months::Apr: std::cout << "April has "<<day30<<" days" << std::endl; break;
      case months::May: std::cout << "May has "<<day31<<" days" << std::endl; break;
      case months::Jun: std::cout << "June has "<<day30<< " days" << std::endl; break;
      case months::Jul: std::cout << "July has "<<day31<< " days" << std::endl; break;
      case months::Aug: std::cout << "August has "<<day31<<" days" << std::endl; break;
      case months::Sep: std::cout << "September has "<<day30<<" days" << std::endl; break;
      case months::Oct: std::cout << "October has "<<day31<< " days" << std::endl; break;
      case months::Nov: std::cout << "November has "<<day30<<" days" << std::endl; break;
      case months::Dec: std::cout << "December has "<<day31<<" days" << std::endl; break;
      default:
        std::cout << "You wrote a wrong number";
        break;
  }
  return 0 ;
}
