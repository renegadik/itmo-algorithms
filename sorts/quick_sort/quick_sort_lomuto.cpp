#include <utility>

int partition(int* arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quick_sort(int* arr, int left, int right) {
    if (left >= right) return;

    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot + 1, right);
}

// quick_sort(arr, 0, size - 1);
