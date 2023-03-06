#include <iostream>
#include <vector>
template<typename T>
class Base{
private:
	int m_count = 1;
  T *m_arr = new T[m_count];

public:
	Base(int count) : m_count(count){};
	void print(){
    for (size_t i = 0; i < m_count; i++) {
      /* code */
    }
  }
    return out; };

int main(){
  int count = 3;
  Base(count);
}
