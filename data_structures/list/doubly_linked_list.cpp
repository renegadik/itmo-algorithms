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

    void RemoveNode(Node* node) {
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
        n->prev = nullptr;
        n->next = head;

        if (head != nullptr) 
            head->prev = n;
        head = n;

        if (tail == nullptr) 
            tail = n;
        size++;
    }

    void PushBack(int value) {
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

    bool PopFront() {
        if (Empty()) return false;

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

    bool PopBack() {
        if (Empty()) return false;

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

    Node* Find(int value) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->value == value) 
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    bool Remove(int value) {
        Node* node = Find(value);
        if (node == nullptr) 
            return false;

        RemoveNode(node);
        return true;
    }

    Node* InsertAfter(Node* pos, int value) {
        if (pos == nullptr) {
            PushFront(value);
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

    Node* InsertBefore(Node* pos, int value) {
        if (pos == nullptr) {
            PushBack(value);
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

    void Clear() {
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

    void PrintForward() {
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

    void PrintBackward() {
        if (Empty()) {
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
