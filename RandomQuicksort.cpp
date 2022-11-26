#include <iostream>
#include <ctime>    // для времени
#include <cstdlib>  // для random
using namespace std;
template <typename T>
void quicksort(T arr[], int start, int end) {   // быстрая сортировка
    srand(time(NULL));  // чтобы каждый запуск программы числа генерировались по-разному
    int left, right, pivot; // инициализация границ и опорного элемента
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
    } while (left <= right);      // partition, сдвиг границ
    if (start < right) {
        quicksort(arr, start, right);
    }
    if (end > left) {
        quicksort(arr, left, end);
    }                               // сортировка подмассивов
}
int main()
{
    unsigned int start_time = clock();
    int arr[] = { 6,5,31,1,4,7,1,8,7,2,2,3,-7,4,4,7,31,-4,-4,4,-1,-2,0,6,5,44,-6,-5,12,-15,33 };
    int N = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, N - 1);
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    unsigned int end_time = clock();
    std::cout << "Time: " << end_time - start_time << std::endl;   // подсчет времени
    return 0;
}
