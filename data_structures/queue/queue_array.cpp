#include <iostream>

class Queue {
private:
    int* data;
    int count;
    int head;
    int tail;
    int capacity;

    void Resize(int new_capacity) {
        int* new_data = new int[new_capacity];

        for (int i = 0; i < count; i++) {
            new_data[i] = data[(head + i) % capacity];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
        head = 0;
        tail = count;
    }

public:
    Queue(int cap = 16) {
        capacity = cap;
        data = new int[capacity];
        head = 0;
        tail = 0;
        count = 0;
    }

    ~Queue() {
        delete[] data;
    }

    bool Empty() const {
        return count == 0;
    }

    int Size() const {
        return count;
    }

    void Push(int value) {
        if (count == capacity) {
            Resize(capacity * 2);
        }
        data[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
    }

    int Pop() {
        if (Empty()) {
            std::cerr << "underflow" << std::endl;
            return -1;
        }
        int result = data[head];
        head = (head + 1) % capacity;
        count--;

        if (count > 0 && count < capacity / 4) {
            Resize(capacity / 2);
        }

        return result;
    }

    int Head() const {
        if (Empty()) {
            std::cerr << "empty" << std::endl;
            return -1;
        }
        return data[head];
    }
};