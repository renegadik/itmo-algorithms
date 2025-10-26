#include <utility>

void SiftDown(int* heap, int size, int index) {
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

void BuildHeap(int* heap, int size) {
    for (int i = (size - 2) / 2; i >= 0; --i) 
        SiftDown(heap, size, i);
}

void HeapSort(int* arr, int size) {
    BuildHeap(arr, size);

    for (int end = size - 1; end > 0; --end) {
        std::swap(arr[0], arr[end]);
        SiftDown(arr, end, 0);
    }
}

// HeapSort(arr, size);