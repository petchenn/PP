#include <iostream>
#include <future>
#include <windows.h>
#include <algorithm>
#include <ctime>

using namespace std;

const size_t gCount1 = 200;
const size_t gCount2 = 100000;



int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void quick_sort_async(int* arr, int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        auto left_future = std::async(std::launch::async, quick_sort_async, arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }
}


void init_array(int* arr, size_t gCount) {
    for (size_t i = 0; i < gCount; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    cout << gCount1 << " elem" << endl;
    int arr[gCount1];
    srand(static_cast<unsigned>(GetTickCount64()));
    double s = 0.0;
    for (int i = 0; i < 50; i++) {
        init_array(arr, gCount1);
        clock_t time;
        time = clock();
        quickSort(arr, 0, gCount1 - 1);
        time = clock() - time;
        s += time;
        cout << static_cast<float>(time) / CLOCKS_PER_SEC << " ";
    };
    cout << '\n';
    cout << "QuickSort: " << s / gCount1 / CLOCKS_PER_SEC << endl;
    s = 0.0;
    for (int i = 0; i < 50; i++) {
        init_array(arr, gCount1);
        clock_t time;
        time = clock();
        quick_sort_async(arr, 0, gCount1 - 1);
        time = clock() - time;
        s += time;
        cout << static_cast<float>(time) / CLOCKS_PER_SEC << " ";
    }
    cout << '\n';
    cout <<"QuickSort Async: " << s / gCount1 / CLOCKS_PER_SEC << endl;

    cout << endl << gCount2 << " elem" << endl;
    int arr2[gCount2];

    s = 0.0;
    for (int i = 0; i < 50; i++) {
        init_array(arr2, gCount2);
        clock_t time;
        time = clock();
        quickSort(arr2, 0, gCount2 - 1);
        time = clock() - time;
        s += time;
        cout << static_cast<float>(time) / CLOCKS_PER_SEC << " ";
    };
    cout << '\n';
    cout << "QuickSort: " << s / gCount2 / CLOCKS_PER_SEC << endl;
    s = 0.0;
    for (int i = 0; i < 50; i++) {
        init_array(arr2, gCount2);
        clock_t time;
        time = clock();
        quick_sort_async(arr2, 0, gCount2 - 1);
        time = clock() - time;
        s += time;
        cout << static_cast<float>(time) / CLOCKS_PER_SEC << " ";
    }
    cout << '\n';
    cout << "QuickSort Async: " << s / gCount2 / CLOCKS_PER_SEC << endl;
    return 0;
}

