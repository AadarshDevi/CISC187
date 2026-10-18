# Binary Search Tree

## Part 1 — Is It a Binary Search Tree?

Tree A
```
	50
   /  \
 30    70
/ \    / \
```
20 40 60 80

Tree B
```
   50
  /  \
30    70
  \
   60
```
Tree C

```
	40
   /  \
 20    70
/ \    /
```

10 30 50

For each tree:

    Determine whether it is a valid BST.
    Justify your answer using the BST invariant.
    If it is invalid, identify the value that violates the ordering property.
    Explain why checking only a node and its immediate children is insufficient for validating a BST.

## Part 2 — Construct a BST

Starting with an empty BST, insert the following values in this exact order:

45, 25, 70, 15, 35, 60, 90, 30, 40, 80

Draw the final BST.

Then identify:

    Root
    Leaf nodes
    Parent of 30
    Children of 25
    Left subtree of 45
    Right subtree of 45
    Depth of 40
    Depth of 80
    Height of the tree

Use a root depth of 0. Measure tree height using the number of edges on the longest path from the root to a leaf.

## Part 3 — Trace BST Search

Using the BST from Part 2, manually trace searches for:

40

and:

75

Current Node Target Comparison Direction

For the unsuccessful search, identify the point at which the algorithm determines that the target does not exist.
Analysis

Explain why BST search does not need to examine both subtrees after comparing the target with the current node.

## Part 4 — Implement a BST Class

Implement a BST from scratch.

Do not use std::set or std::map for the main implementation.

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
BinarySearchTree ();
~BinarySearchTree ();

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

You may add private helper functions if necessary.

Do not copy or assign BinarySearchTree objects in this lab because the implementation uses raw owning pointers.
Part 5 — BST Insertion

Implement:

void insert (int value);

and its recursive helper.

Your insertion must preserve:

Left subtree values < Node < Right subtree values

Example insertion sequence:

50, 30, 70, 20, 40

should produce:

        50
       /  \
     30    70
    / \

20 40

Analysis

    Why does insertion follow only one path through the tree?
    Why does the recursive helper return a Node*?
    What happens when insertion reaches nullptr?
    What happens if the value already exists?

Part 6 — Search

Implement:

bool search (int value) const;

Test:

    The root.
    A leaf.
    An internal node.
    A value not stored in the tree.

For every test, manually predict the search path before running the program.
Complexity

Explain why search is best expressed as:

O (H)

where H is tree height.

Then explain why this is approximately O (log N) for a reasonably balanced tree but may become O (N) for a highly skewed
tree.

## Part 7 — Tree Traversals

Implement:

void inorder () const;
void preorder () const;
void postorder () const;

Use recursive helper functions.

Inorder:
Left → Root → Right

Preorder:
Root → Left → Right

Postorder:
Left → Right → Root

For the tree:

        50
       /  \
     30    70
    / \    / \

20 40 60 80

predict all three traversal outputs before running your program.
Traversal Predicted Output Actual Output
Inorder		
Preorder		
Postorder		
Analysis

Explain why inorder traversal of a valid BST produces values in sorted order.

## Part 8 — Minimum and Maximum

Implement:

int minimum () const;
int maximum () const;

Your implementation should use the structure of the BST rather than traversing every node.
Analysis

    Why is the minimum found by repeatedly following left?
    Why is the maximum found by repeatedly following right?
    What should the functions do if the tree is empty?
    Why are these operations O(H)?

Part 9 — BST Deletion

Implement:

bool remove (int value);

Deletion must correctly handle all three structural cases.
Case 1 — Leaf Node

        50
       /  \
     30    70

Delete:

30

Case 2 — Node With One Child

        50
       /
     30
     /

20

Delete:

30

Case 3 — Node With Two Children

        50
       /  \
     30    70
    / \    / \

20 40 60 80

Delete:

50

For the two-child case, use the inorder successor: the smallest value in the right subtree.

Before implementing deletion, draw the tree before and after each case.
Analysis

Explain why deleting a node with two children requires more work than deleting a leaf.

Also explain why simply deleting a node without reconnecting its subtree would corrupt the tree.

## Part 10 — Verify Deletion

Construct:

50, 30, 70, 20, 40, 60, 80

Then perform:

remove (20)
remove (30)
remove (50)

After each deletion:

    Draw the resulting tree.
    Run inorder traversal.
    Verify that the values remain sorted.
    Verify that the deleted value can no longer be found.
    Verify that all other expected values remain accessible.

Reasoning

Why is inorder traversal a useful correctness check after deletion?

Is sorted inorder output alone enough to prove that the complete implementation is correct? Briefly explain.

## Part 11 — Balanced vs. Skewed Trees

Tree A

Insert:

40, 20, 60, 10, 30, 50, 70

Tree B

Insert:

10, 20, 30, 40, 50, 60, 70

Draw both trees.

For each tree determine:

    Number of nodes
    Height
    Search path for 70
    Number of nodes examined while searching for 70

Analysis

Explain why the same set of values can produce dramatically different BST performance simply because the insertion order
changed.

## Part 12 — Complexity Analysis

Operation Balanced BST Highly Skewed BST Why?
Search			
Insert			
Delete			
Minimum			
Maximum			
Full inorder traversal

Then answer:

    Why is saying “BST search is O(log N)” incomplete or potentially incorrect?

Use tree height in your explanation.

## Part 13 — Ordered Operations

Consider this BST:

           50
          /  \
        30    70
       / \    / \
     20  40  60  80

Suppose the query is:

Find all values from 35 through 70.

Without performing a complete traversal:

    Determine which values should be returned.
    Identify branches that can be ignored.
    Explain how the BST ordering property allows the algorithm to avoid exploring branches that cannot contain valid results.

You do not need to implement a complete range-search function.

## Part 14 — Memory Management

Nodes in your BST are dynamically allocated.

Implement the destructor so that all remaining nodes are released when the BST object is destroyed.
Analysis

    Why should children be deleted before their parent?
    Which traversal naturally supports this ordering?
    What would happen if dynamically allocated nodes were never released?
    How does maximum recursion depth relate to tree height?

## Part 15 — Complete BST Test

Write a main () function that demonstrates your completed BST.

Your test should demonstrate:

    An initially empty tree.
    Multiple insertions.
    Duplicate insertion behavior.
    Successful search.
    Unsuccessful search.
    Inorder traversal.
    Preorder traversal.
    Postorder traversal.
    Minimum.
    Maximum.
    Leaf deletion.
    One-child deletion.
    Two-child deletion.
    Correct tree behavior after deletion.

Your program output should make it possible to verify that the BST remains correctly ordered after structural changes.

## Analysis and Reflection

Briefly explain:

    Why the BST invariant applies to entire subtrees.
    Why insertion order affects tree shape.
    Why search follows only one path.
    Why inorder traversal produces sorted output.
    Why deletion is more complicated than insertion.
    Why BST performance depends on height.
    Why a skewed BST can behave like a linked list.
    Why self-balancing trees such as AVL and Red-Black trees are useful.

Connect your explanations to your implementation and observations rather than providing only definitions.