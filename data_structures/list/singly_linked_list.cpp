#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* head;
    int size;

public:
    SinglyLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~SinglyLinkedList() {
        Clear();
    }

    bool Empty() {
        return size == 0;
    }

    int Size() {
        return size;
    }

    Node* Head() {
        if (head == nullptr) {
            std::cout << "zero elements" << std::endl;
            return -1;
        }
        return head;
    }

    void PushFront(int value) {
        Node* n = new Node;
        n->value = value;
        n->next = head;
        head = n;
        size++;
    }

    bool PopFront() {
        if (Empty()) return false;

        Node* t = head;
        head = head->next;
        delete t;
        size--;
        return true;
    }

    Node* Find(int value) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->value == value) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    bool Remove(int value) {
        if (Empty()) return false;

        if (head->value == value) {
            return PopFront();
        }

        Node* cur = head;
        while (cur->next != nullptr) {
            if (cur->next->value == value) {
                Node* t = cur->next;
                cur->next = t->next;
                delete t;
                size--;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void Clear() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* t = cur;
            cur = cur->next;
            delete t;
        }
        head = nullptr;
        size = 0;
    }

    void Print() {
        if (Empty()) {
            std::cout << "empty" << std::endl;
            return;
        }

        Node* cur = head;
        while (cur != nullptr) {
            std::cout << cur->value << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};
