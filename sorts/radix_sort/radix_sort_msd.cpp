void RadixSortMSD(int* arr, int left, int right, int exp) {
    if (left >= right || exp == 0) return;

    int* count = new int[11];
    int* buffer = new int[right - left + 1];

    for (int i = 0; i < 11; i++)
        count[i] = 0;

    for (int i = left; i <= right; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit + 1]++;
    }

    for (int i = 1; i < 11; i++)
        count[i] += count[i - 1];

    for (int i = left; i <= right; i++) {
        int digit = (arr[i] / exp) % 10;
        buffer[count[digit]++] = arr[i];
    }

    for (int i = 0; i <= right - left; i++)
        arr[left + i] = buffer[i];

    for (int i = 0; i < 10; i++) {
        int bucket_left = left + count[i];
        int bucket_right = left + count[i + 1] - 1;

        if (bucket_left < bucket_right)
            RadixSortMSD(arr, bucket_left, bucket_right, exp / 10);
    }

    delete[] count;
    delete[] buffer;
}

void RadixSort(int* arr, int size) {
    if (size <= 1) return;

    int max_val = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max_val)
            max_val = arr[i];

    int exp = 1;
    while (max_val / exp >= 10)
        exp *= 10;

    RadixSortMSD(arr, 0, size - 1, exp);
}

// RadixSort(arr, size);
