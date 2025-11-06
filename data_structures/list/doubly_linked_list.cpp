#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;
    int size;

    void remove_node(Node* node) {
        if (node == nullptr) return;

        if (node->prev != nullptr) 
            node->prev->next = node->next;
        else 
            head = node->next;

        if (node->next != nullptr) 
            node->next->prev = node->prev;
        else 
            tail = node->prev;

        delete node;
        size--;
    }

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoublyLinkedList() {
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
        n->prev = nullptr;
        n->next = head;

        if (head != nullptr) 
            head->prev = n;
        head = n;

        if (tail == nullptr) 
            tail = n;
        size++;
    }

    void push_back(int value) {
        Node* n = new Node;
        n->value = value;
        n->next = nullptr;
        n->prev = tail;

        if (tail != nullptr) 
            tail->next = n;

        tail = n;

        if (head == nullptr) head = n;
        size++;
    }

    bool pop_front() {
        if (is_empty()) return false;

        Node* t = head;
        head = head->next;
        if (head != nullptr) 
            head->prev = nullptr;
        else 
            tail = nullptr;

        delete t;
        size--;
        return true;
    }

    bool pop_back() {
        if (is_empty()) return false;

        Node* t = tail;
        tail = tail->prev;

        if (tail != nullptr) 
            tail->next = nullptr;
        else 
            head = nullptr;

        delete t;
        size--;
        return true;
    }

    Node* get_head() {
        if (head == nullptr) {
            std::cout << "zero elements" << std::endl;
            return nullptr;
        }
        return head;
    }

    Node* get_tail() {
        if (head == nullptr) {
            std::cout << "zero elements" << std::endl;
            return nullptr;
        }
        return tail;
    }

    Node* find(int value) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->value == value) 
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    bool remove(int value) {
        Node* node = find(value);
        if (node == nullptr) 
            return false;

        remove_node(node);
        return true;
    }

    Node* insert_after(Node* pos, int value) {
        if (pos == nullptr) {
            push_front(value);
            return head;
        }

        Node* n = new Node;
        n->value = value;
        n->prev = pos;
        n->next = pos->next;

        if (pos->next != nullptr) 
            pos->next->prev = n;

        pos->next = n;

        if (pos == tail) 
            tail = n;

        size++;
        return n;
    }

    Node* insert_before(Node* pos, int value) {
        if (pos == nullptr) {
            push_back(value);
            return tail;
        }

        Node* n = new Node;
        n->value = value;
        n->next = pos;
        n->prev = pos->prev;

        if (pos->prev != nullptr) 
            pos->prev->next = n;

        pos->prev = n;

        if (pos == head) 
            head = n;

        size++;
        return n;
    }

    void clear() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* t = cur;
            cur = cur->next;
            delete t;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void print_forward() {
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

    void print_backward() {
        if (is_empty()) {
            std::cout << "empty" << std::endl;
            return;
        }
        Node* cur = tail;
        while (cur != nullptr) {
            std::cout << cur->value << " ";
            cur = cur->prev;
        }
        std::cout << std::endl;
    }
};
