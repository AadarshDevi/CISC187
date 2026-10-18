# Binary Search Tree

## Table of Contents

## Part 1 — Is It a Binary Search Tree?

***Question:*** For each tree:

1. [x] Determine whether it is a valid BST.
2. [x] Justify your answer using the BST invariant.
3. [x] If it is invalid, identify the value that violates the ordering property.
4. [x] Explain why checking only a node and its immediate children is insufficient for validating a BST.

***Binary Trees***

1. Tree A: ***Yes***
   ```
       50
      /  \
    30    70
   / \    / \
  20 40  60 80
   ```

2. Tree B: ***No***
   ```
       50
      /  \
    30    70
      \
       60
   ```

3. Tree C: ***Yes***
   ```
       40
      /  \
    20    70
   / \    /
  10 30  50
   ```

***Answer:***

| Tree | Binary Tree? | Reason                                                                                  | BST Invariant                                                                                                                            |
| ---- | ------------ | --------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| 1    | Yes          | Each number in the leaf nodes are in the right place. There are no misplaced leaves.    | ***Depth 0:***<br>30 < 50<br>70 > 50<br><br>***Depth 1:***<br>20 < 30<br>40 > 30<br><br>60 < 70<br>80 > 70                               |
| 2    | No           | The leaf node 60 should be the left leaf node under 70 and not a right leaf node of 20. | ***Depth 0:***<br>30 < 50<br>70 > 50<br><br>***Depth 1:***<br>But this is wrong:<br>$60 > 30 < 50$ which means $60 < 50$. That is wrong. |
| 3    | Yes          | The nodes are in the right places. No misplaced leaves.                                 | ***Depth 0:***<br>20 < 40<br>70 > 40<br><br>***Depth 1:***<br>10 < 20<br>30 > 20<br><br>50 < 70                                          |
## Part 2 — Construct a BST
Starting with an empty BST, insert the following values **in this exact order**: `45, 25, 70, 15, 35, 60, 90, 30, 40, 80` Draw the final BST. Use a root depth of `0`. Measure tree height using the number of edges on the longest path from the root to a leaf.
```
			45 
	  /		       \
	25				70
  /    \		  /    \
15		35		60		90
	  /	   \	       /
	30		40		 80
```
Then identify:
1. Root: 45
2. Leaf nodes: 25, 70
3. Parent of `30`: 35
4. Children of `25`: 15, 35
5. Left subtree of `45`
	```
	45 
	   \
		70
	  /    \
	60		90
		   /
		  80
	```
6. Right subtree of `45`
	```
		45 
	   /
	25
  /    \
15		35
	  /	   \
	30		40
	```
7. Depth of `40`: 3
8. Depth of `80`: 3
9. Height of the tree: 3
## Part 3 — Trace BST Search

***Question:*** Using the BST from Part 2, manually trace searches for `40` and `75`. For the unsuccessful search, identify the point at which the algorithm determines that the target does not exist.

***Answer:***

| Current Node | Target | Comparison | Direction     |
| ------------ | ------ | ---------- | ------------- |
| 45           | 40     | $40 < 45$  | left          |
| 25           | 40     | $25 < 40$  | right         |
| 35           | 40     | $35 < 40$  | right         |
| 40           | 40     | $40 == 40$ | ***`Found`*** |

| Current Node | Target | Comparison | Direction       |
| ------------ | ------ | ---------- | --------------- |
| 45           | 75     | $75 > 45$  | right           |
| 70           | 75     | $75 > 70$  | right           |
| 90           | 75     | $75< 90$   | right           |
| 80           | 75     | $75 < 80$  | ***`nullptr`*** |

### Analysis

***Question:*** Explain why BST search does not need to examine both subtrees after comparing the target with the current node.

***Answer:*** There are only 2 possible ways for the number to be in: left or right. So if it is not left, then it is right and vice versa. This is also because this binary tree can only have 2 child nodes.
## Part 4 — Implement a BST Class

Implement a BST from scratch. Do **not** use `std::set` or `std::map` for the main implementation. You may add private helper functions if necessary. Do not copy or assign `BinarySearchTree` objects in this lab because the implementation uses raw owning pointers.

### Template Given

```c++
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int value);
    bool search(Node* node, int value) const;

    void inorder(Node* node) const;
    void preorder(Node* node) const;
    void postorder(Node* node) const;

    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;

    Node* remove(Node* node, int value);
    void deleteTree(Node* node);

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
```

### BST Implementation

```c++
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
  
    bool search(Node *node, int value) const { return false; }  
  
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
            // so save the right node and check later            // delete the parent node. (safely deleted)            if (node->left == nullptr) {  
                Node *temp = node->right;  
                delete node;  
                return temp;  
            }  
  
            // check if there is a right node,  
            // if there exists, delete it.            // same as the above condition but for right            if (node->right == nullptr) {  
                Node *temp = node->left;  
                delete node;  
                return temp;  
            }  
  
            // if the node has two children  
            // get the lowest value of right subtree            Node *temp = findMin(node->right);  
  
            // replace root value with this value  
            node->data = temp->data;  
  
            // slowly delete the right subtree by assigning the right subtree  
            // then we send in the temp value so we can reduce the leaves            node->right = remove(node->right, temp->data);  
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
        return false;  
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
```
## Part 5 — BST Insertion

Implement `void insert(int value);` and its recursive helper. Your insertion must preserve: `Left subtree values < Node < Right subtree values`. Example insertion sequence: `50, 30, 70, 20, 40` should produce:

```
        50
       /  \
     30    70
    / \
   20 40
```

### Code

```c++
private:
Node *insert(Node *node, int value) {  
    // node given is null = add new value  
    if (node == nullptr) return new Node(value);  
  
    // add new node  
    if (node->data > value) node->left = insert(node->left, value);  
    else if (node->data < value) node->right = insert(node->right, value);  
  
    return node;  
}

public:
void insert(int value) {  
    root = insert(root, value);  
}
```
### Analysis

1. ***Why does insertion follow only one path through the tree?*** There exists only 2 paths. The value is either greater or lower than the node's value. So it has only one option (also, duplication is ignored).
2. ***Why does the recursive helper return a `Node*`?*** Because it builds the links. It links the new node to the old/parent node.
3. ***What happens when insertion reaches `nullptr`?*** A new node is created for the new value and this will be inserted to the previous node.
4. ***What happens if the value already exists?*** The current `node -> data == value` means that the node itself will be returned cause it will bypass the 2 conditionals.

## Part 6 — Search

Implement:

```
bool search(int value) const;
```

Test:

- The root.
- A leaf.
- An internal node.
- A value not stored in the tree.

For every test, manually predict the search path before running the program.

### Complexity

Explain why search is best expressed as:

```
O(H)
```

where `H` is tree height.

Then explain why this is approximately `O(log N)` for a reasonably balanced tree but may become `O(N)` for a highly skewed tree.