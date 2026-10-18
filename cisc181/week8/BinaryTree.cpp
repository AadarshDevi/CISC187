//
// Created by CryosArtic on 10/18/2026.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node *root = nullptr;

    Node *insert(Node *node, int value) {
        // node given is null = add new value
        if (node == nullptr) return new Node(value);

        // add new node
        if (node->data > value) node->left = insert(node->left, value);
        else if (node->data < value) node->right = insert(node->right, value);

        std::cout << "Node added: " << node->data << "\n";
        return node;
    }

    bool search(Node *node, int value) const { return false; }

    void inorder(Node *node) const {
        if (empty()) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node) const {
    }

    void postorder(Node *node) const {
    }

    Node *findMin(Node *node) const {
        // empty node
        if (node == nullptr) return nullptr;

        // get the left most node
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    Node *findMax(Node *node) const {
        // empty node
        if (node == nullptr) return nullptr;

        // get the left most node
        while (node->right != nullptr)
            node = node->right;

        return node;
    }

    Node *remove(Node *node, int value) { return nullptr; }

    void deleteTree(Node *node) {
    }

public:
    BinarySearchTree() {
    }

    ~BinarySearchTree() {
    }

    bool empty() const {
        return root == nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) const {
        return false;
    }

    bool remove(int value) {
        return false;
    }

    void inorder() const {
        inorder(root);
    }

    void preorder() const {
        if (empty()) return;
        preorder(root);
    }

    void postorder() const {
        if (empty()) return;
        postorder(root);
    }

    int minimum() const {
        // no value found
        if (empty()) return -1;

        // Node with min val
        Node *minNode = findMin(root);

        // node DNE
        if (minNode == nullptr) return -1;

        // min val
        int minVal = minNode->data;

        return minVal;
    }

    int maximum() const {
        // no value found
        if (empty()) return -1;

        // Node with min val
        Node *maxNode = findMax(root);

        // node DNE
        if (maxNode == nullptr) return -1;

        // min val
        int maxVal = maxNode->data;

        return maxVal;
    }
};

int main() {
    BinarySearchTree tree;

    tree.insert(50);
    tree.insert(25);
    tree.insert(5);
    tree.insert(10);

    tree.inorder();

    std::cout << tree.minimum() << " is the min value.\n";
    std::cout << tree.maximum() << " is the max value.\n";

    return 0;
}
