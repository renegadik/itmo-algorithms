void CountingSort(int* arr, int size) {
    if (size <= 1) {
        return;
    }

    int max_val = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int range = max_val + 1;
    int* count = new int[range];

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    int* new_arr = new int[size];
    for (int i = size - 1; i >= 0; i--) {
        int value = arr[i];
        int position = --count[value];
        new_arr[position] = value;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = new_arr[i];
    }

    delete[] count;
    delete[] new_arr;
}

// CountingSort(arr, size)