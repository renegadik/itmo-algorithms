void counting_sort(int* arr, int size) {
    int max_val = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    int range = max_val + 1;
    int* count = new int[range]{};

    for (int i = 0; i < size; i++) 
        count[arr[i]]++;

    for (int i = 1; i < range; i++) 
        count[i] += count[i - 1];

    int* result = new int[size];
    for (int i = size - 1; i >= 0; i--)
        result[--count[arr[i]]] = arr[i];

    for (int i = 0; i < size; i++) 
        arr[i] = result[i];

    delete[] count;
    delete[] result;
}

// counting_sort(arr, size);
