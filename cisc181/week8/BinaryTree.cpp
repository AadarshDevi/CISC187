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

    Node *insert(Node *node, int value);

    bool search(Node *node, int value) const;

    void inorder(Node *node) const;

    void preorder(Node *node) const;

    void postorder(Node *node) const;

    Node *findMin(Node *node) const;

    Node *findMax(Node *node) const;

    Node *remove(Node *node, int value);

    void deleteTree(Node *node);

public:
    BinarySearchTree();

    ~BinarySearchTree();

    bool empty() const;

    void insert(int value);

    bool search(int value) const;

    bool remove(int value);

    void inorder() const;

    void preorder() const;

    void postorder() const;

    int minimum() const;

    int maximum() const;
};

int main() {
    return 0;
}
