#include <iostream>

class Queue {
private:
    int* data;
    int count;
    int head;
    int tail;
    int capacity;

    void resize(int new_capacity) {
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

    bool is_empty() const {
        return count == 0;
    }

    int get_size() const {
        return count;
    }

    void push(int value) {
        if (count == capacity) {
            resize(capacity * 2);
        }
        data[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
    }

    int pop() {
        if (is_empty()) {
            std::cerr << "underflow" << std::endl;
            return -1;
        }
        int result = data[head];
        head = (head + 1) % capacity;
        count--;

        if (count > 0 && count < capacity / 4) {
            resize(capacity / 2);
        }

        return result;
    }

    int get_head() const {
        if (is_empty()) {
            std::cerr << "empty" << std::endl;
            return -1;
        }
        return data[head];
    }
};
