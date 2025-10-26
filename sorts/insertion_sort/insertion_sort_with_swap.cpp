#include <utility>

void InsertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;

        while (j > 0 && arr[j] < arr[j-1]) {
            std::swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

// InsertionSort(arr, size)