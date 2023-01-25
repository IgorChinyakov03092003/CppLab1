#include <iostream>
#include <ctime>    // для времени
#include <cstdlib>  // для random
using namespace std;
template <typename T>
void quicksort(T arr[], int start, int end) {   // быстрая сортировка
    srand(time(NULL));  // чтобы каждый запуск программы числа генерировались по-разному
    int left, right;
    double pivot; // инициализация границ и опорного элемента
    left = start;
    right = end;
    int R = rand() % (end - start + 1);
    std::cout << R << std::endl;
    pivot = arr[start + R];     // рандомный выбор опорного элемента
    do {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    } while (left <= right);      // partition, сдвиг границ друг к другу
    if (start < right) {
        quicksort(arr, start, right);
    }
    if (end > left) {
        quicksort(arr, left, end);
    }                               // сортировка подмассивов
}
int main()
{
    unsigned int start_time1 = clock();
    int arr1[] = { 6,5,31,1,4,7,1,8,7,2,2,3,-7,4,4,7,31,-4,-4,4,-1,-2,0,6,5,44,-6,-5,12,-15,33 }; // сортировка int-массива
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    quicksort(arr1, 0, N1 - 1);
    for (int i = 0; i < N1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n";
    unsigned int end_time1 = clock();
    std::cout << "Time: " << end_time1 - start_time1 << std::endl;   // подсчет времени
    unsigned int start_time2 = clock();
    double arr2[] = {6.6,5.5,31.1,1.1,4.44,7.77,1.1,8.8,7.77,2.2,2.2,3.33,-7.67,4.52,4.51,7.17,31.11,-4.4,-4.4,4.05,-1.16,-2.2,0,0,9.91,44.8,-14.41,-17.3,12.19,-15.01,33.33}; // сортировка double-массива
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    quicksort(arr2, 0, N2 - 1);
    for (int i = 0; i < N2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << "\n";
    unsigned int end_time2 = clock();
    std::cout << "Time: " << end_time2 - start_time2 << std::endl; // подсчет времени
    return 0;
}
