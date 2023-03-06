#ifndef DROB_H
#define DROB_H

#include <iostream>

class Drob
{
private:
    int m_numerator;
    int m_denominator;

    int gcd(int a, int b) const;

public:
    // Конструктор по умолчанию
    Drob(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        if (m_denominator == 0)
        {
            std::cout << "Error: denominator can't be zero.\n";
        }
    }

    // Копирующий конструктор
    Drob(const Drob&);

    // Бинарные математические операторы
    friend Drob operator+(const Drob& d1, const Drob& d2);
    friend Drob operator-(const Drob& d1, const Drob& d2);
    friend Drob operator*(const Drob& d1, const Drob& d2);
    friend Drob operator/(const Drob& d1, const Drob& d2);


    // Возведение в -1 степень
    Drob obr() const;

    // Сокращение
    Drob sokrat() const;

    // Конвертация в double
    double Drob_to_double() const;

    int get_num() { return m_numerator; }
    int get_denum() { return m_denominator; }

};

#endif // DROB_H
