#include <iostream>
#include "../list/doubly_linked_list.cpp"

class Queue {
private:
    DoublyLinkedList list;

public:
    bool Empty() {
        return list.Empty();
    }

    int Size() {
        return list.Size();
    }

    void Push(int value) {
        list.PushBack(value);
    }

    bool Pop() {
        return list.PopFront();
    }

    int Front() {
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