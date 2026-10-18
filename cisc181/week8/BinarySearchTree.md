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

Implement `bool search(int value) const;`. For every test, manually predict the search path before running the program. Test:
1. [x] The root.
2. [x] A leaf.
3. [x] An internal node.
4. [x] A value not stored in the tree.

### Search

```c++  
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

bool search(int value) const {  
    return search(root, value);;  
}
```
### Test Suite

```c++
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
```

### Complexity

***Question:*** Explain why search is best expressed as `O(H)` where `H` is tree height. Then explain why this is approximately `O(log N)` for a reasonably balanced tree but may become `O(N)` for a highly skewed tree.

***Answer:***

$$\text{Let: } h = \text{Depth of Binary Tree}$$
***Here, $H = h$, the same thing.***

If we are searching for a value, it can be in the range $[0,H]$ .

Because we are in a balanced tree, we can assume that half of the tree can be eliminated when the value is greater than or less than the root value.
$$\text{Let: } N = \text{Number of items}$$
In our tree, there are only 2 child nodes for a parent node so:
$$\text{Height 0} = \text{1 Node}$$
$$\text{Height 1} = 1 + 2 = 3\text{ Nodes}$$
$$\text{Height 2} = 1 + 2 + 4 = 7\text{ Nodes}$$
$$...$$
$$\text{Height H} = 2^{h+1} - 1\text{ Nodes}$$
So we find $h$:
$$N = 2^{h+1} - 1$$
$$N + 1 = 2^{h+1}$$
$$log(N + 1) = log(2^{h+1})$$
$$\log_2(N+1) = (h+1)log_2(2)$$
$$\log_2(N+1) -1 = h$$
With this, we can now see that time complexity of the ***Binary Tree*** being $O(h)$. If we reduce $O(h)$, we get:
$$\log_2(N+1) -1$$
$$\log(N)$$
$$O\log(N)$$
So this how we get the time complexity for the `Binary Tree`.
## Part 7 — Tree Traversals

Implement:

```c++
void inorder() const;        // Left → Root → Right
void preorder() const;       // Root → Left → Right
void postorder() const;      // Left → Right → Root
```

For the tree:

```
        50
       /  \
     30    70
    / \    / \
   20 40  60 80
```

predict all three traversal outputs **before running your program**.

| Traversal | Predicted Output                                                                                         | Actual Output          |
| --------- | -------------------------------------------------------------------------------------------------------- | ---------------------- |
| Inorder   | $$20\rightarrow 30\rightarrow 40\rightarrow 50\rightarrow 60\rightarrow 70\rightarrow 80$$               | `20 30 40 50 60 70 80` |
| Preorder  | $$50\rightarrow 30\rightarrow 20\rightarrow 40\rightarrow 70\rightarrow 60\rightarrow 80$$               | `50 30 20 40 70 60 80` |
| Postorder | $$20\rightarrow 40\rightarrow 30\rightarrow 30\rightarrow 60\rightarrow 80\rightarrow 70\rightarrow 50$$ | `20 40 30 60 80 70 50` |
### `inorder()`

```c++  
void inorder() const {  
    if (empty()) return;  
    inorder(root);  
    std::cout << "\n";  
}  

void inorder(Node *node) const {  
    if (node == nullptr) return;  
  
    inorder(node->left);  
    cout << node->data << " ";  
    inorder(node->right);  
}  
```
### `preorder()`

```c++
void preorder() const {  
    if (empty()) return;  
    preorder(root);  
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
```
### `postorder()`

```c++
void postorder() const {  
    if (empty()) return;  
    postorder(root);  
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
```
### Analysis

***Question:*** Explain why inorder traversal of a valid BST produces values in sorted order.

***Answer:*** In-order Traversal of BST produces sorted values because the algorithm goes to the left first which is the lowest value of the three (Left, Root, and Right) then is recursively goes down till the last depth/height. Since the lowest value comes first, it then goes to root, which is the middle value and then right, the highest value. So each step up prints the larger numbers in the tree.

## Part 8 — Minimum and Maximum

Implement the methods below. Your implementation should use the structure of the BST rather than traversing every node.

```
int minimum() const;
int maximum() const;
```

### `minimum()`

```c++
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

Node *findMin(Node *node) const {  
    // empty node  
    if (node == nullptr) return nullptr;  
  
    // get the left most node  
    while (node->left != nullptr)  
        node = node->left;  
  
    return node;  
}
```
### `maximum()`

```c++
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

Node *findMax(Node *node) const {  
    // empty node  
    if (node == nullptr) return nullptr;  
  
    // get the left most node  
    while (node->right != nullptr)  
        node = node->right;  
  
    return node;  
}
```
### Analysis

1. ***Why is the minimum found by repeatedly following `left`?*** The minimum value for a node will always be it's left leaf. So by traversing the left nodes, we get to the final leaf. This leaf will have the min value in the tree.
2. ***Why is the maximum found by repeatedly following `right`?*** Like `minimum()`, the max value for a node is the right node. So traversing it will lead to the rightmost leaf. This leaf will have the largest value.
3. ***What should the functions do if the tree is empty?*** If there are no items in the tree, aka empty, we `return -1` to say that the tree was empty.
4. ***Why are these operations O(H)?*** The largest and smallest values will always be in the bottom of the tree. When traversing the tree, they go deeper into the tree. If the tree is $H$ deep, then these values will be $H$ deep.
## Part 9 — BST Deletion

Implement `bool remove(int value);`. Deletion must correctly handle all three structural cases. For the two-child case, use the **`inorder` successor**: the smallest value in the right subtree. Before implementing deletion, draw the tree **before and after** each case.
### Case 1 — Leaf Node

```
	50
   /  \
 30    70
```

***Question:*** Delete `30`

***Answer:***

```
50
  \
   70
```

### Case 2 — Node With One Child

```
	50
   /
 30
 /
20
```

***Question:*** Delete `30`

***Answer:***

```
	50
  /
20
```

### Case 3 — Node With Two Children

```
	 50
    /  \
  30    70
 / \    / \
20 40  60 80
```

***Question:*** Delete `50`

***Answer:*** Least value in right subtree.

```
	 60
    /  \
  30    70
 / \      \
20 40     80
```
### Analysis

1. ***Explain why deleting a node with two children requires more work than deleting a leaf.*** When a node has two children, we have to make sure that both children don't vanish. We have to connect them to the tree so we do not lose the information. For a single leaf, we set the parent node to have the value of the child node. After that, we delete the child node. There is no moving nodes, only changing parent node value. With `inorder` successor, we get the least smallest value from the right subtree of the node. By doing the same thing, we can delete the old value.
2. ***Also explain why simply deleting a node without reconnecting its subtree would corrupt the tree.*** If we delete a node, the links to and from the node are disconnected. If the node had child nodes, all information under the node is lost. That is a memory leak.
## Part 10 — Verify Deletion

Construct a binary tree with the given values: `50, 30, 70, 20, 40, 60, 80`. Then perform:

```
remove(20)
remove(30)
remove(50)
```

After **each deletion**:

1. [ ] Draw the resulting tree.
2. [ ] Run `inorder` traversal.
3. [ ] Verify that the values remain sorted.
4. [ ] Verify that the deleted value can no longer be found.
5. [ ] Verify that all other expected values remain accessible.
### Test Suite

```c++
BinarySearchTree tree;  
  
tree.insert(50);  
tree.insert(30);  
tree.insert(70);  
tree.insert(20);  
tree.insert(40);  
tree.insert(60);  
tree.insert(80);
tree.inorder();
  
tree.remove(20);  
tree.inorder();  
  
tree.remove(30);  
tree.inorder();  
  
tree.remove(40);  
tree.inorder();
```

### Output

```terminalOutput
20 30 40 50 60 70 80      // Initial Binary Tree
30 40 50 60 70 80         // tree.remove(20);
40 50 60 70 80            // tree.remove(30);
50 60 70 80               // tree.remove(40);
```

### Reasoning

1. ***Why is `inorder` traversal a useful correctness check after deletion?*** The `inorder` goes from the smallest value to the largest. If the nodes are placed wrong, we can see the values misplaced in the order. If `60` and `70` were swapped, we can deduce that something went wrong.
2. ***Is sorted `inorder` output alone enough to prove that the complete implementation is correct? Briefly explain.*** No. This is because memory leaks cannot be detected. If we lose nodes, or not delete nodes from memory, we will not know. The nodes could also have been inserted wrong even though the `inorder` shows the order is right.

## Part 11 — Balanced vs. Skewed Trees

***Question:*** Draw each tree and answer the questions given.

***Question: Tree A - *** Insert `40, 20, 60, 10, 30, 50, 70`

***Answer:***

```
		 40
	  /      \
	20        60
   /  \      /  \
 10    30  50   70
```

1. ***Number of nodes:*** 7
2. ***Height:*** 2
3. ***Search path for `70`:*** $40\rightarrow 60\rightarrow 70$
4. ***Number of nodes examined while searching for `70`:*** 3

***Question: Tree B - *** Insert `10, 20, 30, 40, 50, 60, 70`

***Answer:***

```
10
  \
   20
	 \
	  30
		\
		 40
		   \
			50
			  \
			   60
			     \
				  70
```

1. ***Number of nodes***: 7
2. ***Height***: 6
3. ***Search path for `70`:*** $10\rightarrow 20\rightarrow 30\rightarrow 40\rightarrow 50\rightarrow 60\rightarrow 70$
4. ***Number of nodes examined while searching for `70`:*** 7

### Analysis

***Question:*** Explain why the same set of values can produce dramatically different BST performance simply because the insertion order changed.

***Answer:*** Depending on how the values are inserted, they are placed differently. If a high number and a low number are placed, left tree will be the low and the right will be large tree. In the example above, if we have the  2 distant middle vales (2 middle values from their respective halves of the input), we will have trees that branch out. Like in the questions above, if we add values that are larger that the root and the next node, it will be a long tree with single branches.

## Part 12 — Complexity Analysis

Fill the table and then answer "why is saying “BST search is O(log N)" is incomplete or potentially incorrect? Use tree height in your explanation.

| Operation              | Balanced BST | Highly Skewed BST | Why?                                                                                                                                                      |
| ---------------------- | ------------ | ----------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Search                 | $O(log(N))$  | $O(N)$            | Balanced: Half of the nodes for the balanced are eliminated.<br><br>Highly Skewed: It has to go through many more nodes to find it.                       |
| Insert                 | $O(log(N))$  | $O(N)$            | We have to find the right insertion tree. From there determine the position for the new value. This means it has to dive deep into the tree (the height). |
| Delete                 | $O(log(N))$  | $O(N)$            | We have to find the right node in the tree to delete. This will traverse the tree to find it.                                                             |
| Minimum                | $O(log(N))$  | $O(N)$            | Going through each height to get the min value.                                                                                                           |
| Maximum                | $O(log(N))$  | $O(N)$            | Going through each height to get the max value.                                                                                                           |
| Full inorder traversal | $O(N)$       | $O(N)$            | We have to go through every single node in the tree. More nodes, the longer it takes.                                                                     |
## Part 13 — Ordered Operations

Consider this BST:

```
           50
          /  \
        30    70
       / \    / \
     20  40  60  80
```

You do **not** need to implement a complete range-search function. Suppose the query is `Find all values from 35 through 70`. Without performing a complete traversal:
1. ***Determine which values should be returned.*** Values to be returned are: `40, 50, 60, 70`
2. ***Identify branches that can be ignored.*** 30 left leaf and 70 right leaf.
3. ***Explain how the BST ordering property allows the algorithm to avoid exploring branches that cannot contain valid results.*** If the value is less than or greater than the max and min values of the range, we ignore them. By doing this, we can ignore the nodes that will guaranteed to not have the value int he range.
## Part 14 — Memory Management

Nodes in your BST are dynamically allocated. Implement the destructor so that all remaining nodes are released when the BST object is destroyed.

### `~BinarySearchTree()` and `deleteTree()`

Deconstructor: `~BinarySearchTree()`

```c++
```

Deletion: `deleteTree()`

```c++
```

### Analysis

1. ***Why should children be deleted before their parent?*** If the children are deleted then their memory will be removed. If the parent is deleted, the children will be in memory making it  memory leak.
2. ***Which traversal naturally supports this ordering?*** `postorder()` naturally supports this kind of traversing because it traverses from `left --> right --> root`.
3. ***What would happen if dynamically allocated nodes were never released?*** A memory leak will be created and will consume too much resources.
4. ***How does maximum recursion depth relate to tree height?*** The recursion depth will be equal the depth of the tree because it will go down each root and delete the children, come back up, delete the root and it will happen for each node in the tree.

## Part 15 — Complete BST Test

Write a `main()` function that demonstrates your completed BST. Your program output should make it possible to verify that the BST remains correctly ordered after structural changes. Your test should demonstrate:

1. [ ] An initially empty tree.
2. [ ] Multiple insertions.
3. [ ] Duplicate insertion behavior.
4. [ ] Successful search.
5. [ ] Unsuccessful search.
6. [ ] Inorder traversal.
7. [ ] Preorder traversal.
8. [ ] Postorder traversal.
9. [ ] Minimum.
10. [ ] Maximum.
11. [ ] Leaf deletion.
12. [ ] One-child deletion.
13. [ ] Two-child deletion.
14. [ ] Correct tree behavior after deletion.

## Analysis and Reflection

Briefly explain:

1. ***Why the BST invariant applies to entire subtrees.*** 
2. ***Why insertion order affects tree shape.***
3. ***Why search follows only one path.***
4. ***Why inorder traversal produces sorted output.***
5. ***Why deletion is more complicated than insertion.***
6. ***Why BST performance depends on height.***
7. ***Why a skewed BST can behave like a linked list.***
8. ***Why self-balancing trees such as AVL and Red-Black trees are useful.***

Connect your explanations to your implementation and observations rather than providing only definitions.