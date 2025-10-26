void CountingSort(int* arr, int size) {
    if (size <= 1) {
        return;
    }

    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int range = max_val + 1;
    int* count = new int[range]();

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    int* new_arr = new int[size];
    
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            new_arr[index] = i;
            count[i]--;
            index++;
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = new_arr[i];
    }

    delete[] count;
    delete[] new_arr;
}

// CountingSort(arr, size)