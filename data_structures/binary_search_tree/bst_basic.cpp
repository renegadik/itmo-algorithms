#include <iostream>
#include <limits>

class BST {
public:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node* parent;

        Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(int key) {
        root = insert_rec(root, nullptr, key);
    }

    void erase(int key) {
        root = erase_rec(root, key);
        if (root) root->parent = nullptr;
    }

    bool contains(int key) {
        return search_rec(root, key) != nullptr;
    }

    Node* find_node(int key) {
        return search_rec(root, key);
    }

    Node* min() {
        return min_node(root);
    }

    Node* max() {
        return max_node(root);
    }

    Node* next(Node* x) {
        if (!x) return nullptr;

        if (x->right)
            return min_node(x->right);

        Node* p = x->parent;
        while (p && x == p->right) {
            x = p;
            p = p->parent;
        }

        return p;
    }

    Node* prev(Node* x) {
        if (!x) return nullptr;

        if (x->left) return max_node(x->left);

        Node* p = x->parent;
        while (p && x == p->left) {
            x = p;
            p = p->parent;
        }

        return p;
    }

    void print_inorder() {
        inorder_rec(root);
        std::cout << std::endl;
    }

    void print_preorder() {
        preorder_rec(root);
        std::cout << std::endl;
    }

    void print_postorder() {
        postorder_rec(root);
        std::cout << std::endl;
    }

private:
    Node* root;

    void clear(Node* v) {
        if (!v) return;
        clear(v->left);
        clear(v->right);
        delete v;
    }

    Node* search_rec(Node* v, int key) {
        if (!v) return nullptr;
        if (v->key == key) return v;

        if (key < v->key)
            return search_rec(v->left, key);

        return search_rec(v->right, key);
    }

    Node* insert_rec(Node* v, Node* parent, int key) {
        if (!v) {
            Node* n = new Node(key);
            n->parent = parent;
            return n;
        }

        if (key < v->key) {
            v->left = insert_rec(v->left, v, key);
        }
        else if (key > v->key) {
            v->right = insert_rec(v->right, v, key);
        }

        return v;
    }

    Node* min_node(Node* v) {
        if (!v) return nullptr;

        while (v->left)
            v = v->left;

        return v;
    }

    Node* max_node(Node* v) {
        if (!v) return nullptr;

        while (v->right)
            v = v->right;

        return v;
    }

    Node* erase_rec(Node* v, int key) {
        if (!v) return v;

        if (key < v->key) {
            v->left = erase_rec(v->left, key);
            if (v->left) v->left->parent = v;
        }
        else if (key > v->key) {
            v->right = erase_rec(v->right, key);
            if (v->right) v->right->parent = v;
        }
        else {
            if (v->left && v->right) {
                Node* m = min_node(v->right);
                v->key = m->key;
                v->right = erase_rec(v->right, m->key);
                if (v->right) v->right->parent = v;
            } else {
                Node* child = v->left ? v->left : v->right;
                if (child) child->parent = v->parent;
                delete v;
                return child;
            }
        }
        return v;
    }

    void inorder_rec(Node* v) {
        if (!v) return;
        inorder_rec(v->left);
        std::cout << v->key << " ";
        inorder_rec(v->right);
    }

    void preorder_rec(Node* v) {
        if (!v) return;
        std::cout << v->key << " ";
        preorder_rec(v->left);
        preorder_rec(v->right);
    }

    void postorder_rec(Node* v) {
        if (!v) return;
        postorder_rec(v->left);
        postorder_rec(v->right);
        std::cout << v->key << " ";
    }
};