void counting_sort(int* arr, int size) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int range = max - min + 1;
    int* count = new int[range]{};

    for (int i = 0; i < size; i++)
        count[arr[i] - min]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    
    int* result = new int[size];
    for (int i = size - 1; i >= 0; i--)
        result[--count[arr[i] - min]] = arr[i];
    
    for (int i = 0; i < size; i++)
        arr[i] = result[i];

    delete[] count;
    delete[] result;
}

// counting_sort(arr, size);