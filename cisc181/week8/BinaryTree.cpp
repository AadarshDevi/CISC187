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

    Node *insert(Node *node, int value) {
        // node given is null = add new value
        if (node == nullptr) return new Node(value);

        // add new node
        if (node->data > value) node->left = insert(node->left, value);
        else if (node->data < value) node->right = insert(node->right, value);

        return node;
    }

    bool search(Node *node, int value) const {
        // node doesnt exists means the val doesnt exist
        if (node == nullptr) return false;

        // value found
        if (value == node->data) return true;

        // value is in left subtree
        if (value < node->data) return search(node->left, value);

        // value is in right subtree
        if (value > node->data) return search(node->right, value);

        // if something doesnt work, then, the value wasn't found
        return false;
    }

    void inorder(Node *node) const {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node) const {
        // null node
        if (node == nullptr)
            return;

        // print value
        cout << node->data << " ";

        // traverse the root's left subtree
        preorder(node->left);

        // traverse the root's right subtree
        preorder(node->right);
    }

    void postorder(Node *node) const {
        // null node
        if (node == nullptr) return;

        // traverse the root's left subtree
        postorder(node->left);

        // traverse the root's right subtree
        postorder(node->right);

        // print value
        cout << node->data << " ";
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

    Node *remove(Node *node, int value) {
        // empty node aka no children
        if (node == nullptr) return nullptr;

        // more nodes available: check which path to traverse
        if (value < node->data) node->left = remove(node->left, value);
        else if (value > node->data) node->right = remove(node->right, value);
        else {
            // no left node but there might be a right node
            // so save the right node and check later
            // delete the parent node. (safely deleted)
            if (node->left == nullptr) {
                Node *temp = node->right;
                delete node;
                return temp;
            }

            // check if there is a right node,
            // if there exists, delete it.
            // same as the above condition but for right
            if (node->right == nullptr) {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // if the node has two children
            // get the lowest value of right subtree
            Node *temp = findMin(node->right);

            // replace root value with this value
            node->data = temp->data;

            // slowly delete the right subtree by assigning the right subtree
            // then we send in the temp value so we can reduce the leaves
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

    void deleteTree(Node *node) {
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        deleteTree(root);
    }

    bool empty() const {
        return root == nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) const {
        return search(root, value);;
    }

    bool remove(int value) {
        root = remove(root, value);
        return true;
    }

    void inorder() const {
        if (empty()) return;
        inorder(root);
        std::cout << "\n";
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
    tree.insert(60);
    tree.insert(75);
    tree.insert(27);
    tree.insert(5);
    tree.insert(1);
    tree.insert(10);

    tree.inorder();

    std::cout << "Root (50): " << (tree.search(50) ? "true" : "false") << "\n";
    std::cout << "Leaf (10): " << (tree.search(10) ? "true" : "false") << "\n";
    std::cout << "Internal (5): " << (tree.search(5) ? "true" : "false") << "\n";
    std::cout << "Invalid Value (100): " << (tree.search(100) ? "true" : "false") << "\n";

    return 0;
}
