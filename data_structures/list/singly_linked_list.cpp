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
        clear();
    }

    bool is_empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }

    Node* get_head() {
        if (head == nullptr) {
            std::cout << "zero elements" << std::endl;
            return nullptr;
        }
        return head;
    }

    void push_front(int value) {
        Node* n = new Node;
        n->value = value;
        n->next = head;
        head = n;
        size++;
    }

    bool pop_front() {
        if (is_empty()) return false;

        Node* t = head;
        head = head->next;
        delete t;
        size--;
        return true;
    }

    Node* find(int value) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->value == value) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    bool remove(int value) {
        if (is_empty()) return false;

        if (head->value == value) {
            return pop_front();
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

    void clear() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* t = cur;
            cur = cur->next;
            delete t;
        }
        head = nullptr;
        size = 0;
    }

    void print() {
        if (is_empty()) {
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
