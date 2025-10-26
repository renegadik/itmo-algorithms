#include <utility>

int Partition(int* arr, int left, int right) {
    int pivot = arr[(left + right) / 2];

    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) 
            i++;
        
        while (arr[j] > pivot) 
            j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return j;
}

void QuickSort(int* arr, int left, int right) {
    if (left >= right) return;

    int pivot = Partition(arr, left, right);
    QuickSort(arr, left, pivot);
    QuickSort(arr, pivot + 1, right);
}

// QuickSort(arr, 0, size - 1);