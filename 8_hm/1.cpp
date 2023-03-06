#include <iostream>
#include <string>
#include <vector>
#include <cmath>

const double pi = 3.141592653589793238;
const double p = 1.6075;

// Координаты точек (для окружности и эллипса будут точки пересечения с осями)
class Two_D{
protected:
  double m_1[2] = {0,0};
  double m_2[2] = {0,0};
  double m_3[2] = {0,0};
  double m_4[2] = {0,0};

public:
  virtual void print_inf() const = 0;
  virtual double Per() const = 0;
  virtual double sqr() const = 0;
};
// Эллипс. Родительский класс Two_D. Вывод периметра и площади
class Ellipse: public Two_D{
private:
  double m_a, m_b;
public:
  // Ввод значений координат пересечения
  Ellipse(double a = 0, double b = 0): m_a(a), m_b(b){
    *m_1 = a; *(m_1+1) = 0;
    *m_2 = 0; *(m_2+1) = b;
    *m_3 = -a; *(m_3+1) = 0;
    *m_4 = 0; *(m_4+1) = -b;
  };
  virtual double Per() const override {return 4*(pi*m_a*m_b + (m_a-m_b)*(m_a-m_b))/(m_a+m_b);}
  virtual double sqr() const override {return pi*m_a*m_b;};
  virtual void print_inf() const override{
    // вывод (добавлены координаты пересечения)
  std::cout << "\nEllipse, with a = " << m_a << " and b = " << m_b << ". Perimeter = " << Per() << "; Square = " << sqr() << '\n'
  << "Intersection with x in ("<<m_1[0] << ',' << m_1[1] <<") and (" << m_3[0] << ',' << m_3[1]<<") . Intersection with y in ("<<m_2[0] << ',' << m_2[1] << ") and (" << m_4[0] << ',' << m_4[1]<<")\n" ;}
  virtual ~Ellipse(){}
};
class Circle: public Ellipse{
public:
  Circle(double r = 0): m_r(r){
    *m_1 = r; *(m_1+1) = 0;
    *m_2 = 0; *(m_2+1) = r;
    *m_3 = -r; *(m_3+1) = 0;
    *m_4 = 0; *(m_4+1) = -r;
    }
  virtual ~Circle(){}
  virtual double Per() const override {return 2*pi*m_r;}
	virtual double sqr() const override {return pi*m_r*m_r;}
	virtual void print_inf() const override {
    std::cout << "\nCircle, r = " << m_r << ". Perimeter = " << Per() << ". Square = " << sqr() << '\n'
    << "Intersection with x in ("<<m_1[0] << ',' << m_1[1] <<") and (" << m_3[0] << ',' << m_3[1]<<") . Intersection with y in ("<<m_2[0] << ',' << m_2[1] << ") and (" << m_4[0] << ',' << m_4[1]<<")\n" ;}

private:
  double m_r;
};
// Родительский класс 2
class Three_D{
public:
  virtual void print_inf() const = 0;
  virtual double vol() const = 0;
  virtual double sur() const = 0;
protected:
  // Аналогично здесь. Для шара и эллиспоида - точки пересечения с осями. Для куба, параллелепипила и пирамиды - координаты концов фигуры
  double m_1[3] = {0,0,0};
  double m_2[3] = {0,0,0};
  double m_3[3] = {0,0,0};
  double m_4[3] = {0,0,0};
  double m_5[3] = {0,0,0};
  double m_6[3] = {0,0,0};
  double m_7[3] = {0,0,0};
  double m_8[3] = {0,0,0};
};



class Pyramid: public Three_D {
public:
  // Считаем, что центр расположен в центре вписанной и описанной окружностей основания пиромиды.
  Pyramid(double a = 0, double h = 0): m_a(a), m_h(h){
    *m_1 = 0; *(m_1+1) = a*std::pow(3,2)/3; *(m_1+2) = 0;
    *m_2 = a*std::pow(3,0.5)/3; *(m_2+1) = -a*std::pow(3,0.5)/3; *(m_2+2) = 0;
    *m_3 = -a*std::pow(3,0.5)/3; *(m_3+1) = -a*std::pow(3,0.5)/3; *(m_3+2) = 0;
    *m_4 = 0; *(m_4+1) = 0; *(m_4+2) = h;
  }
  virtual ~Pyramid(){}
  virtual double vol() const override {return m_h*m_a*m_a*std::pow(3,0.5)/4;}
  virtual double sur() const override {return 1/2*std::pow(3,0.5)/2*m_a*m_a+3*1/2*m_a*m_a*std::pow(m_h*m_h+(m_a*std::pow(3,0.5)/6)*(m_a*std::pow(3,0.5)/6),0.5);}
  virtual void print_inf() const override {
    std::cout << "\nRight Pyramid (center is in the center of inscribed circle of triangle), a = " << m_a <<". Volume = " << vol() <<". Surface = " << sur() << '\n' <<
    "Coordinates of piramid: A("<<m_1[0]<<','<<m_1[1]<<','<<m_1[2]<<") B("<<m_2[0]<<','<<m_2[1]<<','<<m_2[2]<<") C("<<m_3[0]<<','<<m_3[1]<<','<<m_3[2]<<") D("<<m_4[0]<<','<<m_4[1]<<','<<m_4[2]<<")\n";
  }
private:
  double m_a, m_b, m_c, m_h;
};

class Ellipsoid: public Three_D{
public:
  Ellipsoid(double a = 0, double b = 0, double c = 0): m_a(a), m_b(b), m_c(c){
    *m_1 = a; *(m_1+1) = 0; *(m_1+2) = 0;
    *m_2 = 0; *(m_2+1) = b; *(m_2+2) = 0;
    *m_3 = -a; *(m_3+1) = 0; *(m_3+2) = 0;
    *m_4 = 0; *(m_4+1) = -b; *(m_4+2) = 0;
    *m_5 = 0; *(m_5+1) = 0; *(m_5+2) = c;
    *m_6 = 0; *(m_6+1) = 0; *(m_6+2) = -c;

  }
  virtual ~Ellipsoid(){}
  virtual double sur() const override {return 4*pi*std::pow(std::pow(m_a*m_b,p)+std::pow(m_a*m_c,p)+std::pow(m_b*m_c,p),1/p)/3;}
  virtual double vol() const override {return 4/3*pi*m_a*m_b*m_c;}
  virtual void print_inf() const override {
    std::cout << "\nEllipsoid with a = " << m_a << ", b = " << m_b <<", c = " <<m_c<<". Volume = " << vol() <<". Surface = " <<sur()<< '\n'
    << "Intersection with x in ("<<m_1[0] << ',' << m_1[1] <<','<< m_1[2] << ") and (" << m_3[0] << ',' << m_3[1]<<','<< m_3[2] <<"). Intersection with y in ("<<m_2[0] << ',' << m_2[1] <<','<< m_2[2] << ") and (" << m_4[0] << ',' << m_4[1]<< ','<< m_4[2] <<
    "). Intersection with z in ("<<m_5[0] << ',' << m_5[1] <<','<< m_5[2] << ") and (" << m_6[0] << ',' << m_6[1]<< ','<< m_6[2] <<")\n" ;}
private:
  double m_a, m_b, m_c;
};
// Шар. Родитеский класс Ellipsoid. Вывод объема шара
class Ball: public Ellipsoid{
public:
  Ball(double r = 0): m_r(r){
    *m_1 = r; *(m_1+1) = 0; *(m_1+2) = 0;
    *m_2 = 0; *(m_2+1) = r; *(m_2+2) = 0;
    *m_3 = -r; *(m_3+1) = 0; *(m_3+2) = 0;
    *m_4 = 0; *(m_4+1) = -r; *(m_4+2) = 0;
    *m_5 = 0; *(m_5+1) = 0; *(m_5+2) = r;
    *m_6 = 0; *(m_6+1) = 0; *(m_6+2) = -r;
  }
  virtual ~Ball(){}
  virtual double sur() const override {return 4*pi*m_r*m_r;}
  virtual double vol() const override {return 4/3*pi*m_r*m_r*m_r;}
  virtual void print_inf() const override {
    std::cout << "\nBall, r = " << m_r <<". Volume = " << vol() <<" Surface = " << sur() <<'\n'
    << "Intersection with x in ("<<m_1[0] << ',' << m_1[1] <<','<< m_1[2] << ") and (" << m_3[0] << ',' << m_3[1]<<','<< m_3[2] <<"). Intersection with y in ("<<m_2[0] << ',' << m_2[1] <<','<< m_2[2] << ") and (" << m_4[0] << ',' << m_4[1]<< ','<< m_4[2] <<
    "). Intersection with z in ("<<m_5[0] << ',' << m_5[1] <<','<< m_5[2] << ") and (" << m_6[0] << ',' << m_6[1]<< ','<< m_6[2] <<")\n" ;}

private:
  double m_r;
};

// Параллелепипид. Родитеский класс Three_D. Вывод площади поверхности и объема
class Parallelepiped: public Three_D{
public:
  Parallelepiped(double a = 0, double b = 0, double c = 0): m_a(a), m_b(b), m_c(c){
    *m_1 = a; *(m_1+1) = b; *(m_1+2) = c;
    *m_2 = a; *(m_2+1) = b; *(m_2+2) = -c;
    *m_3 = a; *(m_3+1) = -b; *(m_3+2) = c;
    *m_4 = a; *(m_4+1) = -b; *(m_4+2) = -c;
    *m_5 = -a; *(m_5+1) = b; *(m_5+2) = c;
    *m_6 = -a; *(m_6+1) = b; *(m_6+2) = -c;
    *m_7 = -a; *(m_7+1) = -b; *(m_7+2) = c;
    *m_8 = -a; *(m_8+1) = -b; *(m_8+2) = -c;
  }
  virtual ~Parallelepiped(){}
  virtual double vol() const override {return m_a*m_b*m_c;}
  virtual double sur() const override {return 2*(m_a*m_b+m_c*m_b+m_a*m_c);}
  virtual void print_inf() const  override {
    std::cout << "\nParallelepiped, with a = " << m_a << ", b = "<< m_b << ", c = " << m_c<<
     ". Volume = " << vol() << ". Square of surface = " << sur() << '\n' <<
     "Coordinates of parallelepiped: A("<<m_1[0]<<','<<m_1[1]<<','<<m_1[2]<<") B("<<m_2[0]<<','<<m_2[1]<<','<<m_2[2]<<") C("<<m_3[0]<<','<<m_3[1]<<','<<m_3[2]<<") D("<<m_4[0]<<','<<m_4[1]<<','<<m_4[2]<<") E("
     <<m_5[0]<<','<<m_6[1]<<','<<m_6[2]<<") F("<<m_7[0]<<','<<m_7[1]<<','<<m_7[2]<<") G("<<m_8[0]<<','<<m_8[1]<<','<<m_8[2]<<")\n"
     ;}
private:
  double m_a, m_b, m_c;
};

class Cube: public Parallelepiped {
public:
  Cube(double a = 0): m_a(a){
    *m_1 = a; *(m_1+1) = a; *(m_1+2) = a;
    *m_2 = a; *(m_2+1) = a; *(m_2+2) = -a;
    *m_3 = a; *(m_3+1) = -a; *(m_3+2) = a;
    *m_4 = a; *(m_4+1) = -a; *(m_4+2) = -a;
    *m_5 = -a; *(m_5+1) = a; *(m_5+2) = a;
    *m_6 = -a; *(m_6+1) = a; *(m_6+2) = -a;
    *m_7 = -a; *(m_7+1) = -a; *(m_7+2) = a;
    *m_8 = -a; *(m_8+1) = -a; *(m_8+2) = -a;}
  virtual ~Cube(){}
  virtual double vol() const override {return m_a*m_a*m_a;}
  virtual double sur() const override {return 6*(m_a*m_a);}
  virtual void print_inf() const override {
    std::cout << "\nCube, a = " << m_a <<". Volume = " << vol() <<". Square of surface = " << sur() << '\n' <<
    "Coordinates of cube: A("<<m_1[0]<<','<<m_1[1]<<','<<m_1[2]<<") B("<<m_2[0]<<','<<m_2[1]<<','<<m_2[2]<<") C("<<m_3[0]<<','<<m_3[1]<<','<<m_3[2]<<") D("<<m_4[0]<<','<<m_4[1]<<','<<m_4[2]<<") E("
    <<m_5[0]<<','<<m_6[1]<<','<<m_6[2]<<") F("<<m_7[0]<<','<<m_7[1]<<','<<m_7[2]<<") G("<<m_8[0]<<','<<m_8[1]<<','<<m_8[2]<<")\n";}
private:
  double m_a;
};

int main(){
  Circle circ(10);
  Ellipse el(2,4);
  Cube cube(1);
  Ellipsoid elp(1,2,3);
  Parallelepiped par(2.3,4.1,3);
  Ball bl(5.222);
  Pyramid pyr(1,2);
  circ.print_inf();
  elp.print_inf();
  par.print_inf();
  el.print_inf();
  cube.print_inf();
  bl.print_inf();
  pyr.print_inf();

}
