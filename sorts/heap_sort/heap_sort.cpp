#include <utility>

void sift_down(int* heap, int size, int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest]) 
            largest = left;
        
        if (right < size && heap[right] > heap[largest]) 
            largest = right;

        if (largest == index) 
            return;

        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}

void build_heap(int* heap, int size) {
    for (int i = (size - 2) / 2; i >= 0; --i) 
        sift_down(heap, size, i);
}

void heap_sort(int* arr, int size) {
    build_heap(arr, size);

    for (int end = size - 1; end > 0; --end) {
        std::swap(arr[0], arr[end]);
        sift_down(arr, end, 0);
    }
}

// heap_sort(arr, size);
