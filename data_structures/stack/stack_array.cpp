#include <iostream>

class Stack {
private:
    int* data;
    int top;
    int capacity;

    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < top; i++)
            new_data[i] = data[i];

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Stack(int cap = 16) {
        capacity = cap;
        data = new int[capacity];
        top = 0;
    }

    ~Stack() {
        delete[] data;
    }

    bool is_empty() const {
        return top == 0;
    }

    int get_size() const {
        return top;
    }

    void clear() {
        top = 0;
    }

    void push(int value) {
        if (top == capacity)
            resize(capacity * 2);
        data[top++] = value;
    }

    void pop() {
        if (is_empty()) {
            std::cerr << "underflow" << std::endl;
            return;
        }
        top--;
        
        if (top > 0 && top < capacity / 4)
            resize(capacity / 2);
    }

    int peek() const {
        if (is_empty()) {
            std::cerr << "empty" << std::endl;
            return -1;
        }
        return data[top - 1];
    }
};
