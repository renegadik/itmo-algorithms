#include <iostream>
#include <algorithm>

class AVL {
public:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;

        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    AVL() : root(nullptr) {}

    ~AVL() {
        clear(root);
    }

    void insert(int key) {
        root = insert_rec(root, key);
    }

    void erase(int key) {
        root = erase_rec(root, key);
    }

    bool contains(int key) const {
        return search_rec(root, key) != nullptr;
    }

    void print_inorder() const {
        inorder_rec(root);
        std::cout << "\n";
    }

    void print_preorder() const {
        preorder_rec(root);
        std::cout << "\n";
    }

    void print_postorder() const {
        postorder_rec(root);
        std::cout << "\n";
    }

private:
    Node* root;

    static int node_height(Node* n) {
        return n ? n->height : 0;
    }

    static int get_balance(Node* n) {
        if (!n) return 0;
        return node_height(n->left) - node_height(n->right);
    }

    static void update_height(Node* n) {
        if (n) {
            n->height = 1 + std::max(node_height(n->left),
                                     node_height(n->right));
        }
    }

    static Node* right_rotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        update_height(y);
        update_height(x);

        return x;
    }

    static Node* left_rotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // вращаем
        y->left = x;
        x->right = T2;

        update_height(x);
        update_height(y);

        return y;
    }


    static void clear(Node* n) {
        if (!n) return;
        clear(n->left);
        clear(n->right);
        delete n;
    }

    static Node* search_rec(Node* n, int key) {
        if (!n) return nullptr;
        if (key == n->key) return n;
        if (key < n->key) return search_rec(n->left, key);
        return search_rec(n->right, key);
    }

    static Node* min_node(Node* n) {
        if (!n) return nullptr;
        while (n->left) n = n->left;
        return n;
    }

    static Node* insert_rec(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert_rec(node->left, key);
        } else if (key > node->key) {
            node->right = insert_rec(node->right, key);
        } else {
            return node;
        }

        update_height(node);

        int balance = get_balance(node);

        if (balance > 1 && key < node->left->key) {
            return right_rotate(node);
        }

        if (balance < -1 && key > node->right->key) {
            return left_rotate(node);
        }

        if (balance > 1 && key > node->left->key) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

    static Node* erase_rec(Node* node, int key) {
        if (!node) return nullptr;

        if (key < node->key) {
            node->left = erase_rec(node->left, key);
        } else if (key > node->key) {
            node->right = erase_rec(node->right, key);
        } else {
            if (!node->left || !node->right) {
                Node* tmp = node->left ? node->left : node->right;

                if (!tmp) {
                    delete node;
                    return nullptr;
                } else {
                    Node* old = node;
                    node = tmp;
                    delete old;
                }
            } else {
                Node* succ = min_node(node->right);
                node->key = succ->key;
                node->right = erase_rec(node->right, succ->key);
            }
        }

        if (!node) return nullptr;

        update_height(node);

        int balance = get_balance(node);

        if (balance > 1) {
            if (get_balance(node->left) >= 0) {
                return right_rotate(node);
            } else {
                node->left = left_rotate(node->left);
                return right_rotate(node);
            }
        }

        if (balance < -1) {
            if (get_balance(node->right) <= 0) {
                return left_rotate(node);
            } else {
                node->right = right_rotate(node->right);
                return left_rotate(node);
            }
        }

        return node;
    }

    static void inorder_rec(Node* n) {
        if (!n) return;
        inorder_rec(n->left);
        std::cout << n->key << " ";
        inorder_rec(n->right);
    }

    static void preorder_rec(Node* n) {
        if (!n) return;
        std::cout << n->key << " ";
        preorder_rec(n->left);
        preorder_rec(n->right);
    }

    static void postorder_rec(Node* n) {
        if (!n) return;
        postorder_rec(n->left);
        postorder_rec(n->right);
        std::cout << n->key << " ";
    }
};