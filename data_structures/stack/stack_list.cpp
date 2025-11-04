#include <iostream>
#include "../list/singly_linked_list.cpp"

class Stack {
private:
    SinglyLinkedList list;

public:
    bool Empty() {
        return list.Empty();
    }

    int Size() {
        return list.Size();
    }

    void Push(int value) {
        list.PushFront(value);
    }

    bool Pop() {
        return list.PopFront();
    }

    int Top() {
        if (list.Empty()) {
            std::cout << "empty" << std::endl;
            return -1;
        }
        return list.Head()->value;
    }

    void Clear() {
        list.Clear();
    }
};