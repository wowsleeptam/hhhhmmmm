#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class A{
protected:
  int m_int = 0;
};

int main(){

  A a;
  std::cout << a.m_int;
  /*int n = 41;
  std::vector<std::vector<std::string>> v(n);
  for (int i = 0; i < n; i++ )
   {
       for (int j = 0; j < n; j++ )
       {
            v.at(i).push_back("   ");
       }
   }
   for  (int i = 0; i < n; i++ )
    {   for (int j = 0; j < n; j++ ){
      if ((j == 0) || (j == n-1) || (i == 0) || (i == n-1))
          v.at(i).at(j) = " * ";
      if ((j == (n-1)/2) || (i == (n-1)/2))
        v.at(i).at(j) = " * ";
      }
    }
   for  (int i = 0; i < n; i++ )
    {   for (int j = 0; j < n; j++ ){
          std::cout << v.at(i).at(j);
        }
        std::cout << "\n";
    }
    */
  }
