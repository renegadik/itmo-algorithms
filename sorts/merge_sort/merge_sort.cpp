void merge(int* arr, int left, int pivot, int right) {
    int it1 = 0;
    int it2 = 0;

    int* result = new int[right - left];

    int res_idx = 0;
    while (left + it1 < pivot && pivot + it2 < right) {
        if (arr[left + it1] <= arr[pivot + it2]) {
            result[res_idx++] = arr[left + it1++];
        } else {
            result[res_idx++] = arr[pivot + it2++];
        }
    }

    while (left + it1 < pivot) 
        result[res_idx++] = arr[left + it1++];
    
    while (pivot + it2 < right) 
        result[res_idx++] = arr[pivot + it2++];
    
    for (int i = 0; i < right - left; i++) 
        arr[left + i] = result[i];
    
    delete[] result;
}

void merge_sort(int* arr, int left, int right) {
    if (right - left <= 1) return;
    
    int pivot = (right + left) / 2;
    merge_sort(arr, left, pivot);
    merge_sort(arr, pivot, right);

    merge(arr, left, pivot, right);
}

// merge_sort(arr, 0, size);
