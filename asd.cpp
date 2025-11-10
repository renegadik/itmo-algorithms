#include <utility>
#include <iostream>

int partitions(int* arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (true) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (j <= i) {
            return j;
        }

        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void quick_sort(int* arr, int left, int right) {
    if (left >= right) return;

    int pivot = partitions(arr, left, right);
    quick_sort(arr, left, pivot);
    quick_sort(arr, pivot + 1, right);
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
}