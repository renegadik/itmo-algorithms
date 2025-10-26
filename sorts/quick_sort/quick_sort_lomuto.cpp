#include <utility>

int Partition(int* arr, int left, int right) {
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

void QuickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = Partition(arr, left, right);

    QuickSort(arr, left, pivot - 1);
    QuickSort(arr, pivot + 1, right);
}

// QuickSort(arr, 0, size - 1);