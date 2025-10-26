void Merge(int* arr, int left, int pivot, int right) {
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

void MergeSort(int* arr, int left, int right) {
    if (right - left <= 1) return;
    
    int pivot = left + (right - left) / 2;
    MergeSort(arr, left, pivot);
    MergeSort(arr, pivot, right);

    Merge(arr, left, pivot, right);
}

// MergeSort(arr, 0, size);