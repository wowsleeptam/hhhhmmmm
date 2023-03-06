#include<iostream>
#include<vector>
#include<utility>

template<typename type>
class A{
public:
    // Конструктор, который иницализирует введенные данные
    A(type a, type b, type c) : m_a(a), m_b(b), m_c(c) {std::cout << "constr\n";}
    // Конструктор по умолчанию
    A() : m_a(4), m_b(4), m_c(4){std::cout << "Default constr\n";}

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const A& base){
      out << "Values of constructor data: " << base.m_a << ' ' << base.m_b << ' ' << base.m_c << '\n';
        return out;}
    ~A(){}
private:
  type m_a, m_b, m_c;
};

// Функция, возвращающаяся пару указателей на массивы
template<typename T1, typename T2, typename ... Types>
std::pair<A<T1>*, A<T2>*> func(Types... args){
  A<T1>* elem1 = new A<T1>(args...);
  A<T2>* elem2 = new A<T2>();
  std::pair<A<T1>*,A<T2>*> answer(elem1,elem2);
  return answer;
}

int main(){
  std::pair<A<int>*,A<int>*> p = func<int, int>(4,37,2);
  std::cout << *p.first << ' ' << *p.second;
}
