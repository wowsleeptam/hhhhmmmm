#include <iostream>
class Base
{
private:
  int m_first_base, m_second_base, m_third_base;
public:
  Base(int first, int second, int third): m_first_base(first), m_second_base(second), m_third_base(third){}
  friend class Protect;
};

class Protect {
private:
  int m_first_protect;
  int m_third_protect;
public:
  friend class User;
  Protect(Base &base){
  int m_first_protect = base.m_first_base;
  int m_third_protect = base.m_third_base;
}
};

class User {
public:
  User(Protect &protect){
  int m_first_user = protect.m_first_protect;
  //int m_second_user = m_second_portect;//
  int m_third_user = protect.m_third_protect;
  std::cout << m_third_user;
}

private:
  int m_first_user, m_third_user;
};
