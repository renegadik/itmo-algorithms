#include <utility>
#include <iostream>

class Heap {
private:
    int* data;
    int size;
    int capacity;

    void Resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < size; i++)
            new_data[i] = data[i];

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    void SiftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index] < data[parent]) {
                std::swap(data[index], data[parent]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void SiftDown(int index) {
        while (true) {
            int left_kid = 2 * index + 1;
            int right_kid = 2 * index + 2;
            int largest = index;

            if (left_kid < size && data[left_kid] < data[largest]) 
                largest = left_kid;

            if (right_kid < size && data[right_kid] < data[largest]) 
                largest = right_kid;
            
            if (largest == index)
                return;
            
            std::swap(data[index], data[largest]);
            index = largest;
        }
    }

public:
    Heap(int cap = 16) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    ~Heap() {
        delete[] data;
    }

    bool Empty() {
        return size == 0
    }

    int Size() {
        return size;
    }

    int Top() {
        if (Empty()) return -1;
        return data[0];
    }

    void Insert(int value) {
        if (size == capacity) {
            Resize(capacity * 2);
        }

        data[size] = value;
        SiftUp(size++);
    }

    int ExtractMin() {
        if (Empty()) return -1;

        int min = data[0];
        std::swap(data[0], data[--size]);
        SiftDown(0);
        return min;
    }

    void Delete(int index) {
        if (index < 0 || index >= size) return;

        std::swap(data[index], data[--size]);

        int parent = (index - 1) / 2;
        if (index > 0 && data[index] < data[parent])
            SiftUp(index);
        else
            SiftDown(index);
    }

    void BuildHeap(int* arr, int n) {
        if (n > capacity)
            Resize(n);
        
        for (int i = 0; i < n; i++)
            data[i] = arr[i];
        
        size = n;
        for (int i = (size - 2) / 2; i >= 0; i--) 
            SiftDown(i);
    }

    void Print() {
        if (Empty()) {
            std::cout << "empty" << std::endl;
            return;
        }

        int level = 0;
        int count = 0;
        int next_level = 1;

        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";

            count++;
            if (count == next_level) {
                std::cout << std::endl;
                level++;
                next_level = 1 << level;
                count = 0;
            }
        }
        std::cout << std::endl;
    }
}