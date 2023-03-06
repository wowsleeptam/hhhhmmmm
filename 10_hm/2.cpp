#include <iostream>
#include <vector>
template<typename T>
class Base{
private:
	int m_count;
  T *m_base = new T[m_count];
	T *m_backup = new T[m_count];

public:
	Base<T>(int count) : m_count(count){};

	friend std::ostream& operator<< (std::ostream &out, const Base &Base){
		// std::cout << "\nYour data is: ";
    for (size_t i = 0; i < Base.m_count; i++) {
      out << Base.m_base[i] << " ";
    }

    return out; }

	friend std::istream& operator>>(std::istream& in, Base &Base){
		for (size_t i = 0; i < Base.m_count; i++){
			T tmp;
			in >> tmp;
			Base.m_base[i] = tmp;
			Base.m_backup[i] = tmp;}
		std::cout << '\n';
		return in;}

	friend void operator*( Base& arr, const T& num)
	{
		for (size_t i = 0; i < arr.m_count; i++) {
			arr.m_base[i] = arr.m_base[i] * num;
			arr.m_backup[i] = arr.m_base[i];
		}
	}

	friend void operator+(const Base& arr, const T& num)
	{
		for (size_t i = 0; i < arr.m_count; i++) {
			arr.m_base[i] = arr.m_base[i] + num;
			arr.m_backup[i] = arr.m_base[i];
		}
	}

	friend void operator/( Base& arr, const T& num)
	{
		for (size_t i = 0; i < arr.m_count; i++) {
			arr.m_base[i] = arr.m_base[i] / num;
			arr.m_backup[i] = arr.m_base[i];
		}
	}

	friend void operator-( Base& arr, const T& num)
	{
		for (size_t i = 0; i < arr.m_count; i++) {
			arr.m_base[i] = arr.m_base[i] - num;
			arr.m_backup[i] = arr.m_base[i];
		}
	}

	void print_backup(){
		std::cout << "\nYour back_up is: ";
		for (size_t i = 0; i < m_count; i++) {
			std::cout << m_backup[i] << " ";
		}
	}

	~Base(){
		delete[] m_base;
		delete[] m_backup;
	}
};


int main() {
	int count;
	std::cout << "Write quantity of your array ";
	std::cin >> count;
  Base<int> v1(count);
	Base<float> v2(count);
  std::cin >> v1 >> v2;
	v1 + 2;
	std::cout << v1 << '\n';
	v1 * 5;
	std::cout << v1 << '\n';
	v1 / 5;
	std::cout << v1 << '\n';
	v2 * 3;
	std::cout << v2 << '\n';
	v2 - 0;
	std::cout << v2 << '\n';
	v2 / 2;
	std::cout << v2 << '\n';
	v1.print_backup();
	v2.print_backup();
  return 0;
}
