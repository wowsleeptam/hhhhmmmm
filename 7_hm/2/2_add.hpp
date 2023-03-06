#include "2.hpp"
#include <iostream>
#include <string>

int Drob::gcd(int a, int b) const{
  if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);}

void Drob::cut() const{
  Drob value;
  value.m_up = m_up/gcd(m_up, m_down);
  value.m_down = m_down/gcd(m_up, m_down);
  return value;
}

double Drob::turn_into_double() const{
  double up_value = static_cast<double>(m_up), down_value = static_cast<double>(m_down);
  return double (up_value/down_value);}

std::istream& operator>> (std::istream &in, Drob &value)
{
    std::cout << "Write your you value without / = ";
    in >> value.m_up >> value.m_down >> ;

    return in;}

std::ostream& operator<< (std::ostream &out, const Drob& value)
{
    out << value.m_up << "/" << value.m_down << std::endl;
    return out;}

Drob operator-(const Drob& first_value, const Drob& second_value){
  Drob value;
  value.m_up = first_value.m_up * second_value.m_down - second_value.m_up * first_value.m_down;
  value.m_down = first_value.m_down * second_value.m_down;
  return value.cut();}

Drob operator+(const Drob& first_value, const Drob& second_value){
  Drob value;
  value.m_up = first_value.m_up * second_value.m_down + second_value.m_up * first_value.m_down;
  value.m_down = first_value.m_down * second_value.m_down;
  return value.cut();}

Drob operator*(const Drob& first_value, const Drob& second_value){
    Drob value;
    value.m_up = first_value.m_up * second_value.m_up;
    value.m_down = first_value.m_down * second_value.m_down;
    return value.cut();}

Drob operator/(const Drob& first_value, const Drob& second_value){
    Drob value;
    value.m_up = first_value.m_up * second_value.m_down;
    value.m_down = first_value.m_down * second_value.m_down;
    return value.cut();}

bool operator== (const Drob& first_value, const Drob& second_value){
  return first_value.turn_into_double() == second_value.turn_into_double();}
bool operator>= (const Drob& first_value, const Drob& second_value){
  return first_value.turn_into_double() >= second_value.turn_into_double();}
bool operator<= (const Drob& first_value, const Drob& second_value){
  return first_value.turn_into_double() <= second_value.turn_into_double();}
bool operator> (const Drob& first_value, const Drob& second_value){
  return first_value.turn_into_double() > second_value.turn_into_double();}
bool operator< (const Drob& first_value, const Drob& second_value){
  return first_value.turn_into_double() < second_value.turn_into_double();}
bool operator!= (const Drob& first_value, const Drob& second_value){
  return first_value.turn_into_double() != second_value.turn_into_double();}

Drob& Drob::operator++(){
  m_up = m_up + m_down;
  return *this;}

Drob& Drob::operator--(){
  m_up = m_up - m_down;
  return *this;}
