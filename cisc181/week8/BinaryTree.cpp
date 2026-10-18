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
    Node *root;
    Node *root = nullptr;

    Node *insert(Node *node, int value) {

    Node *insert(Node *node, int value);
    }

    bool search(Node *node, int value) const { return false; }

    void inorder(Node *node) const;
    void inorder(Node *node) const {

    void preorder(Node *node) const;
    }

    void preorder(Node *node) const {
    }

    void postorder(Node *node) const {
    }

    Node *findMin(Node *node) const { return nullptr; };

    Node *findMax(Node *node) const { return nullptr; };

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

    void insert(int value);
    void insert(int value) {

    bool search(int value) const;

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
    }

    void postorder() const {
    }

    int minimum() const {
        return -1;
    }

    int maximum() const {
        return -1;
    }
};

int main() {
    BinarySearchTree tree;

    tree.insert(50);
    tree.insert(25);
    tree.insert(5);
    tree.insert(10);

    tree.inorder();

    return 0;
}
