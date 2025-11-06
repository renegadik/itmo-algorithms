#include <iostream>
#include "../list/singly_linked_list.cpp"

class Stack {
private:
    SinglyLinkedList list;

public:
    bool is_empty() {
        return list.is_empty();
    }

    int get_size() {
        return list.get_size();
    }

    void push(int value) {
        list.push_front(value);
    }

    bool pop() {
        return list.pop_front();
    }

    int get_top() {
        if (list.is_empty()) {
            std::cout << "empty" << std::endl;
            return -1;
        }
        return list.get_head()->value;
    }

    void clear() {
        list.clear();
    }
};
