#include <utility>

int partition(int* arr, int left, int right) {
    int pivot = arr[(left + right) / 2];

    int i = left;
    int j = right;

    while (true) {
        while (arr[i] < pivot) 
            i++;
        
        while (arr[j] > pivot) 
            j--;

        if (j <= i)
            return j;
        
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }

    return j;
}

void quick_sort(int* arr, int left, int right) {
    if (left >= right) return;

    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot);
    quick_sort(arr, pivot + 1, right);
}

// quick_sort(arr, 0, size - 1);
