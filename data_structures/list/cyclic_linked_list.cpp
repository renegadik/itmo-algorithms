#include <iostream>

class CyclicLinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
    };

    Node* head;
    int size;

public:
    CyclicLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~CyclicLinkedList() {
        clear();
    }

    bool is_empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }

    void push_front(int value) {
        Node* n = new Node;
        n->value = value;

        if (is_empty()) {
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

    void push_back(int value) {
        if (is_empty()) {
            push_front(value);
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

    bool pop_front() {
        if (is_empty()) return false;

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

    bool pop_back() {
        if (is_empty()) return false;

        if (size == 1) return pop_front();

        Node* tail = head->prev;
        Node* new_tail = tail->prev;

        new_tail->next = head;
        head->prev = new_tail;

        delete tail;
        size--;
        return true;
    }

    Node* find(int value) {
        if (is_empty()) return nullptr;

        Node* cur = head;
        do {
            if (cur->value == value) return cur;
            cur = cur->next;
        } while (cur != head);

        return nullptr;
    }

    bool remove(int value) {
        Node* node = find(value);
        if (node == nullptr) return false;

        if (size == 1) {
            delete node;
            head = nullptr;
            size = 0;
            return true;
        }

        if (node == head) {
            return pop_front();
        }

        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;

        delete node;
        size--;
        return true;
    }

    void clear() {
        if (is_empty()) return;

        Node* cur = head;
        for (int i = 0; i < size; i++) {
            Node* t = cur;
            cur = cur->next;
            delete t;
        }

        head = nullptr;
        size = 0;
    }

    void print_forward() {
        if (is_empty()) {
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

    void print_backward() {
        if (is_empty()) {
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
