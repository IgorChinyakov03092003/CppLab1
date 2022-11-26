#include <iostream>
#include <ctime>    // для времени
using namespace std;
template <typename T>
void freeinserter(T arr[], int d, int N) {  // вспомогательная функция грубых проходов для сортировки Шелла
    for (int i = d; i < N; i++) {
        int a = i;
        while (arr[a] < arr[a - d]) {
            std::swap(arr[a], arr[a - d]);
            a -= d;
            if (a - d < 0) {
                break;        // сдвиги и обмены осуществляются с произвольным шагом d
            }
        }
    }       // при d=1 функция идентична сортировке вставками
}
template <typename T>
void shellsort(T arr[], int N) {    // сортировка Шелла
    int d = N / 2;        
    while (d >= 1) {        
        freeinserter(arr, d, N);    // Предварительные грубые проходы
        d = d / 2;                  // Последовательность Шелла: d1=N/2, d[i+1]=d[i]/2
    }                               // Заканчивается все обычной сортировкой вставками при d=1
}
int main()
{
    unsigned int start_time1 = clock();
    int arr1[] = {6,5,31,1,4,7,1,8,7,2,2,3,-7,4,4,0,7,7,31,1,-2,0};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    shellsort(arr1, N1);
    for (int i = 0; i < N1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n";
    unsigned int end_time1 = clock();
    std::cout << "Time: " << end_time1 - start_time1 << std::endl;      // сортировка Шелла с подсчетом времени int-массива
    unsigned int start_time2 = clock();
    double arr2[] = { 6,5,31,1,4,7,1,8,7,2,2,3,-7,4.4,7.7,31.1,4.4,4.4,4,-1.333,-7,0 };
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    shellsort(arr2, N2);
    for (int i = 0; i < N2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << "\n";
    unsigned int end_time2 = clock();
    std::cout << "Time: " << end_time2 - start_time2 << std::endl;      // сортировка Шелла с подсчетом времени double-массива
}

