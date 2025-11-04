#include <iostream>

class CyclicDoublyLinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
    };

    Node* head;
    int size;

public:
    CyclicDoublyLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~CyclicDoublyLinkedList() {
        Clear();
    }

    bool Empty() {
        return size == 0;
    }

    int Size() {
        return size;
    }

    void PushFront(int value) {
        Node* n = new Node;
        n->value = value;

        if (Empty()) {
            n->next = n;
            n->prev = n;
            head = n;
        } else {
            Node* tail = head->prev;

            n->next = head;
            n->prev = tail;

            tail->next = n;
            head->prev = n;

            head = n;
        }

        size++;
    }

    void PushBack(int value) {
        if (Empty()) {
            PushFront(value);
            return;
        }

        Node* n = new Node;
        n->value = value;

        Node* tail = head->prev;

        n->next = head;
        n->prev = tail;

        tail->next = n;
        head->prev = n;

        size++;
    }

    bool PopFront() {
        if (Empty()) return false;

        Node* t = head;

        if (size == 1) {
            head = nullptr;
        } else {
            Node* tail = head->prev;

            head = head->next;
            head->prev = tail;
            tail->next = head;
        }

        delete t;
        size--;
        return true;
    }

    bool PopBack() {
        if (Empty()) return false;

        if (size == 1) return PopFront();

        Node* tail = head->prev;
        Node* new_tail = tail->prev;

        new_tail->next = head;
        head->prev = new_tail;

        delete tail;
        size--;
        return true;
    }

    Node* Find(int value) {
        if (Empty()) return nullptr;

        Node* cur = head;
        do {
            if (cur->value == value) return cur;
            cur = cur->next;
        } while (cur != head);

        return nullptr;
    }

    bool Remove(int value) {
        Node* node = Find(value);
        if (node == nullptr) return false;

        if (size == 1) {
            delete node;
            head = nullptr;
            size = 0;
            return true;
        }

        if (node == head) {
            return PopFront();
        }

        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;

        delete node;
        size--;
        return true;
    }

    void Clear() {
        if (Empty()) return;

        Node* cur = head;
        for (int i = 0; i < size; i++) {
            Node* t = cur;
            cur = cur->next;
            delete t;
        }

        head = nullptr;
        size = 0;
    }

    void PrintForward() {
        if (Empty()) {
            std::cout << "empty" << std::endl;
            return;
        }

        Node* cur = head;
        do {
            std::cout << cur->value << " ";
            cur = cur->next;
        } while (cur != head);
        std::cout << std::endl;
    }

    void PrintBackward() {
        if (Empty()) {
            std::cout << "empty" << std::endl;
            return;
        }

        Node* cur = head->prev;
        do {
            std::cout << cur->value << " ";
            cur = cur->prev;
        } while (cur != head->prev);
        std::cout << std::endl;
    }
};
