#include<iostream>
#include<string>
class Drob{

public:
  Drob(int up = 0, int down = 1): m_up(up), m_down(down){}
  double turn_into_double() const;
  int gcd(int a, int b) const;
  Drob cut() const;
  friend Drob operator+(const Drob& first_value, const Drob& second_value);
  friend Drob operator-(const Drob& first_value, const Drob& second_value);
  friend Drob operator*(const Drob& first_value, const Drob& second_value);
  friend Drob operator/(const Drob& first_value, const Drob& second_value);
  friend std::ostream& operator<< (std::ostream &out, const Drob& value);
  friend std::istream& operator>> (std::istream &in,  Drob& value);
  friend bool operator== (const Drob& first_value, const Drob& second_value);
  friend bool operator>= (const Drob& first_value, const Drob& second_value);
  friend bool operator<= (const Drob& first_value, const Drob& second_value);
  friend bool operator> (const Drob& first_value, const Drob& second_value);
  friend bool operator< (const Drob& first_value, const Drob& second_value);
  friend bool operator!= (const Drob& first_value, const Drob& second_value);
  int get_up() {return m_up;}
  int get_down() {return m_down;}
  void set_up(int value) {m_up = value;}
  void set_down(int value) {m_down = value;}
  Drob& operator++();
  Drob& operator--();
  Drob operator++(int);
  Drob operator--(int);

private:
  int m_up, m_down;
};
