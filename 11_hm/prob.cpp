#include<iostream>
#include<vector>
#include<utility>

template<typename type>
class A{
public:
    // Конструктор, который иницализирует введенные данные
    A(type a, type b, type c) : m_a(a), m_b(b), m_c(c) {}
    // Конструктор по умолчанию
    A() : m_a(4), m_b(4), m_c(4){}

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const A& base){
      out << "Values of constructor data: " << base.m_a << ' ' << base.m_b << ' ' << base.m_c << '\n';
        return out;}
    ~A(){}
private:
  type m_a, m_b, m_c;
};
template<typename T1, typename T2, typename ... Types>
A<T2>* func(Types... args){
  A<T2>* elem2 = new A<T2>();
  A<T1>* elem1 = new A<T1>(args...);

  return elem1;
}

int main(){
  std::vector<int> a{1,2};
  std::cout << *(func<int, int>(1,2,4)) << '\n';
}
