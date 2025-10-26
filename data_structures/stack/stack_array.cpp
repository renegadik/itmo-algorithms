#include <iostream>

class Stack {
private:
    int* data;
    int top;
    int capacity;

    void Resize(int new_capacity) {
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

    bool Empty() const {
        return top == 0;
    }

    int Size() const {
        return top;
    }

    void Clear() {
        top = 0;
    }

    void Push(int value) {
        if (top == capacity)
            Resize(capacity * 2);
        data[top++] = value;
    }

    void Pop() {
        if (Empty()) {
            std::cerr << "underflow" << std::endl;
            return;
        }
        top--;
        
        if (top > 0 && top < capacity / 4)
            Resize(capacity / 2);
    }

    int Peek() const {
        if (Empty()) {
            std::cerr << "empty" << std::endl;
            return -1;
        }
        return data[top - 1];
    }
};
