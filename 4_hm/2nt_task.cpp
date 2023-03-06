#include <iostream>
#include <vector>

// Объявление функции сортировки
void insertionSortRecursive(int* ptr, int n);

int main()
{

// Объявление и заполенение массива
    int n;
    std::cout << "Write quantity of array ";
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; i++) std::cin >> arr.at(i);

// Передаю в функцию указатель на первый элемент массива
    int* ptr = &arr.at(0);
    insertionSortRecursive(ptr, n);

// Вывод массива
    std::cout << "Your soted array: ";
    for (size_t i = 0; i < n; i++) {
      std::cout << *(ptr+i) << " ";
    }
    return 0;
}

// Описание функции сортировки
void insertionSortRecursive(int* ptr, int n)
{
// Это база !!!!
    if (n <= 1)
        return;


//Сортируем n-1 элемент
    insertionSortRecursive( ptr, n-1 );


// Переносим последний элемент на его "сортированную позицию"
    int last = *(ptr+n-1);
    int j = n-2;

/*Перемещаем элементы arr[0..i-1], которые
больше текущего зачения, на одну позицию впереди
их текущего положения*/
    while (j >= 0 && *(ptr+j) > last)
    {
        *(ptr+j+1) = *(ptr+j);
        j--;
    }
    *(ptr+j+1) = last;
}
