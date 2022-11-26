#include <iostream>
#include <ctime>    // для подсчета времени
using namespace std;
template <typename T>
void inserter(T arr[], int N) {     // сортировка вставками
    for (int i = 1; i < N; i++) {
        int a = i;
        while (arr[a] < arr[a - 1]){
            std::swap(arr[a], arr[a - 1]);
            a -= 1;                     //  сдвиг i-го элемента влево, пока каждый предыдущий больше
            if (a == 0) {
                break;          // если элемент сдвинут до начала массива, то переходим к (i+1)-му элементу
            }
        }
    }
}
int main()
{
    unsigned int start_time1 = clock();
    double arr1[] = { 6,5,31,1,4,7,1,8,7,2,2,3,-7,4.4,7.7,31.1,4.4,4.4,4,-1.333 };
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    inserter(arr1, N1);
    for (int i = 0; i < N1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n";
    unsigned int end_time1 = clock();
    std::cout << "Time: " << end_time1 - start_time1 << std::endl;  // сортировка с подсчетом времени double-массива
    unsigned int start_time2 = clock();
    int arr2[] = { 6,5,31,1,4,7,1,8,7,2,2,3,-7,4,4,7,7,31,4,-2,-1 };
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    inserter(arr2, N2);
    for (int i = 0; i < N2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << "\n";
    unsigned int end_time2 = clock();
    std::cout << "Time: " << end_time2 - start_time2 << std::endl;  // сортировка с подсчетом времени int-массива
}
