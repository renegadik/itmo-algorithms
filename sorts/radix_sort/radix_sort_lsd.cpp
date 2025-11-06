void radix_sort(int* arr, int size) {
    if (size <= 1) return;

    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    int* count = new int[10];
    int* buffer = new int[size];

    for (int exp = 1; max_val / exp > 0; exp *= 10) {

        for (int i = 0; i < 10; i++)
            count[i] = 0;

        for (int i = 0; i < size; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        int sum = 0;
        for (int i = 0; i < 10; i++) {
            int tmp = count[i];
            count[i] = sum;
            sum += tmp;
        }

        for (int i = 0; i < size; i++) {
            int digit = (arr[i] / exp) % 10;
            buffer[count[digit]] = arr[i];
            count[digit]++;
        }

        for (int i = 0; i < size; i++)
            arr[i] = buffer[i];
    }

    delete[] count;
    delete[] buffer;
}

// radix_sort(arr, size);
