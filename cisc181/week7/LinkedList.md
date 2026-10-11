# Week 7: Linked List

## Table of Contents

1. [Part 1 — Understanding Nodes and Pointers](#part-1--understanding-nodes-and-pointers)
    - [Part 1 Analysis](#part-1-analysis)
2. [Part 2 — Trace a Linked List](#part-2--trace-a-linked-list)
    - [Part 2 Complexity](#part-2-complexity)
3. [Part 3 — Build a LinkedList Class](#part-3--build-a-linkedlist-class)
4. [Part 4 — Initialize the List](#part-4--initialize-the-list)
5. [Part 5 — Insert at the Beginning](#part-5--insert-at-the-beginning)
    - [Pointer Analysis](#pointer-analysis)
    - [Complexity](#complexity)
6. [Part 6 — Insert at the End](#part-6--insert-at-the-end)
    - [Part 6 Analysis](#part-6-analysis)
7. [Part 7 — Search the List](#part-7--search-the-list)
    - [Complexity Analysis](#complexity-analysis)
8. [Part 8 — Insert After a Specific Value](#part-8--insert-after-a-specific-value)
    - [Pointer Reasoning](#pointer-reasoning)
    - [Complexity](#complexity)
9. [Part 9 — Delete a Node](#part-9--delete-a-node)
    - [Part 9 Analysis](#part-9-analysis)
10. [Part 10 — Test the Complete Linked List](#part-10--test-the-complete-linked-list)
11. [Part 11 — Memory Management](#part-11--memory-management)
    - [Part 11 Analysis](#part-11-analysis)
12. [Part 12 — Complexity Analysis](#part-12--complexity-analysis)
13. [Part 13 — Linked List vs. Array](#part-13--linked-list-vs-array)
    - [Part 13 Analysis](#part-13-analysis)
14. [Part 14 — Reasoning About a Tail Pointer](#part-14--reasoning-about-a-tail-pointer)
15. [Part 15 — Singly vs. Doubly Linked Lists](#part-15--singly-vs-doubly-linked-lists)
16. [Part 16 — Circular Linked Lists](#part-16--circular-linked-lists)
17. [Analysis and Reflection](#analysis-and-reflection)

## Part 1 — Understanding Nodes and Pointers

I have split the code into segments. Each statement will show what is happening individually.

We have a new node, first. It is the address of the node created in memory.

```
Node *first = new Node{7, nullptr};
-------------------------------------
first
  ↓
+---+---------+
| 7 | nullptr |
+---+---------+
```

Next we create out second node.

```
Node *second = new Node{13, nullptr};
-------------------------------------
second
  ↓
+----+---------+
| 13 | nullptr |
+----+---------+
```

And finally the third node.

```
Node *third = new Node{21, nullptr};
-------------------------------------
third
  ↓
+----+---------+
| 21 | nullptr |
+----+---------+
```

We now get a head node. It represents the start of the node.

```
Node *head = first;
-------------------------------------
head
  ↓
+---+---------+
| 7 | nullptr |
+---+---------+
```

We link node second to node first by setting `Node*` to point to second.

```
first->next = second;
-------------------------------------
+---+------+   +----+---------+
| 7 | next | ⟶ | 13 | nullptr |
+---+------+   +----+---------+
```

Just like linking `Node`s first and second, we do it for second and third.

```
second->next = third;
-------------------------------------
+----+------+   +----+---------+
| 13 | next | ⟶ | 21 | nullptr |
+----+------+   +----+---------+
```

Finally, we have a linked list.

```
head
  ↓
+---+------+   +----+------+   +----+---------+
| 7 | next | ⟶ | 13 | next | ⟶ | 21 | nullptr |
+---+------+   +----+------+   +----+---------+
```

Your diagram should identify:

1. [x] `head`
2. [x] Each node's `data`
3. [x] Each `next` pointer
4. [x] `nullptr`

### Part 1 Analysis

1. ***Does `head` contain the value `7`?*** No, `head` does not contain the data `7`.
2. ***What does `head` actually store?*** `head` contains the address of `Node first`.
3. ***What does `first->next` contain?*** It contains the address to `Node second`.
4. ***What does `third->next` contain?*** It is a `nullptr` which means it is pointing to nothing.
5. ***What would happen to your ability to access the list if `head` were lost?*** We would not be able access the data
   at all. The address of `Node first` is lost which subsequently means the rest of the Nodes' address are lost.

## Part 2 — Trace a Linked List

We are given a linked list:

```
head → 10 → 20 → 30 → 40 → nullptr
```

and the below program to iterate through it.

```c++
Node* temp = head;

while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
}
```

| Iteration | `temp->data` | `temp->next` |
|:---------:|:------------:|:------------:|
|     1     |      10      | Second Node  |
|     2     |      20      |  Third Node  |
|     3     |      30      | Fourth Node  |
|     4     |      40      |   nothing    |

***Question: Explain why the traversal stops.*** The traversal stops because the last Node, `fourth` does not have a
pointer to a valid Node. There is no node, so it points to nothing.

### Part 2 Complexity

***Question:*** If the list contains `N` nodes, determine the Big-O complexity of traversing the entire list and explain
your reasoning.

***Answer:*** $N$ Nodes contain $N-1$ pointers. So for each node, the iterator has to go from the front to the back. if
it misses it, it has to go to the start and then iterate. It cannot just go back a `Node`. So based on this information,

1. Best Case: $O (1)$ - The data needed is in the front
2. Worst Case: $O (N)$ - The data is at the end of the list.

## Part 3 — Build a `LinkedList` Class

Before implementing them, we will describe them.

1. `empty()`: is the linked list empty
2. `display()`: display the values of the linked list
3. `search(int value)`: Search the linked list for the value.
4. `insertFront(int value)`: add the value to the front of the list
5. `insertBack(int value)`: add the value to the back of the list
6. `insertAfter(int target, int value)`: add the value after the target value.
7. `remove(int value)`: remove the value

### Class: LinkedList

Below is my interpretation of the LinkedList class.

```c++  
struct Node {  
    int data;  
    Node *next;  
};  
  
class LinkedList {  
private:  
    Node *head;  
  
public:  
    LinkedList() {  
        head = nullptr;  
    }  
  
    bool empty() const {  
        return head == nullptr;  
    }  
  
    void display() const {  
        // check if the list is empty  
        if (empty()) {  
            std::cout << "Linked List is Empty\n";  
        }  
  
        // a node to hold the pointers for the next value  
        Node *current = head;  
  
        // loop over each item in the list  
        while (current != nullptr) {  
            // print out the value  
            std::cout << current->data << " ";  
  
            // go to the next node  
            current = current->next;  
        }  
        std::cout << "\n";  
    }  
  
    bool search(int value) const {  
        // check if list is empty  
        if (empty()) {  
            return false;  
        }  
  
        // pointer to the first node  
        Node *current = head;  
  
        // go through each node to check if the value exists  
        while (current != nullptr) {  
            if (current->data == value) {  
                // value found  
                return true;  
            }  
        }  
  
        // value not found  
        return false;  
    }  
  
    void insertFront(int value) {  
        // check if empty  
        if (empty()) {  
            Node *node = new Node{value, nullptr};  
            head = node;  
            return;  
        }  
  
        // get the first node of the list  
        Node *firstNode = head;  
  
        // create a new node that points to the first node  
        Node *newNode = new Node{value, firstNode};  
  
        // head points to new node (not first node)  
        head = newNode;  
    }  
  
    void insertBack(int value) {  
        // check if list is empty  
        if (empty()) {  
            Node *node = new Node{value, head};  
            head = node;  
            return;  
        }  
  
        // create new last node  
        Node *node = new Node{value, nullptr};  
  
        // find the last node  
        Node *lastNode = head;  
        while (lastNode->next != nullptr) {  
            lastNode = lastNode->next;  
        }  
  
        // set the last node to point at the new node  
        lastNode->next = node;  
    }  
  
    bool insertAfter(int target, int value) {  
        // node cannot be inserted after a value in an empty list  
        if (empty()) return false;  
  
  
        // find target node  
        Node *targetNode = head;  
  
        while (targetNode != nullptr) {  
            if (targetNode->data == target) {  
                break;  
            }  
        }  
  
        // get target's old next pointer  
        Node *oldNext = targetNode->next;  
  
        // create a new node with the pointer to the target's old next pointer  
        Node *newNode = new Node{value, oldNext};  
  
        // target node points to new node  
        targetNode->next = newNode;  
  
        // node inserted successfully  
        return true;  
    }  
  
    bool remove(int value) {  
        // list is empty  
        if (empty()) return false;  
  
        // keep track of current and previous node  
        Node *current = head;  
        Node *previous = nullptr;  
  
        while (current != nullptr) {  
            // node with the value to be removed found  
            if (current->data == value) {  
                // the node that has the value is not connected to the list anymore  
                previous->next = current->next;  
            }  
  
            // current node is now previous node  
            previous = current;  
  
            // the next node is the current node  
            current = current->next;  
  
            // delete current  
            delete current;  
        }  
  
        return false;  
    }  
  
    ~LinkedList() {  
        // get start of the node  
        Node *current = head;  
  
        // loop through list  
        while (head != nullptr) {  
            // get next node  
            Node *next = head->next;  
  
            // delete current node  
            delete current;  
  
            // current node is next node  
            current = next;  
        }  
  
        // make head point to nothing  
        head = nullptr;  
    }  
};
```

## Part 4 — Initialize the List

Implement:

1. Constructor
2. `empty()`

Creating an object

```c++
LinkedList list = LinkedList();
```

### Constructor: `LinkedList()`

```c++
LinkedList() {  
    head = nullptr;  
}
```

### Method: `empty()`

```c++
bool empty() const {  
    return head == nullptr;  
}
```

### Part 4 Analysis

***Question:*** Explain why `nullptr` is an appropriate representation of an empty linked list.

***Answer:*** `head` being `nullptr` means that the head (the start of the list) is pointing to nothing which means that
there is no data in the linked list. If `head` was not `nullptr`, it means that there are items in the list.

## Part 5 — Insert at the Beginning


### Pointer Analysis

1. ***Explain why the order of pointer updates matters.*** The order of the pointers matter because they dictate how the
   items in the list are ordered. If two pointers switch, then the two nodes will have their places switched. It means
   the values will also be in a different order. If the order in a list is $10\rightarrow20\rightarrow30$ then a pointer
   switch can change the order: $10\rightarrow30\rightarrow20$.
2. ***What could happen if `head` were changed before preserving the connection to the existing list?*** If head was
   changed before preserving the connection, the new node will be connected to the list, but the rest of the list will
   be lost to memory. Those links were severed and not saved.

### Complexity

## Part 6 — Insert at the End

### Part 6 Analysis

## Part 7 — Search the List

### Complexity Analysis

## Part 8 — Insert After a Specific Value

### Pointer Reasoning

### Complexity

## Part 9 — Delete a Node

### Part 9 Analysis

## Part 10 — Test the Complete Linked List

## Part 11 — Memory Management

### Part 11 Analysis

## Part 12 — Complexity Analysis

## Part 13 — Linked List vs. Array

### Part 13 Analysis

## Part 14 — Reasoning About a Tail Pointer

## Part 15 — Singly vs. Doubly Linked Lists

## Part 16 — Circular Linked Lists

## Analysis and Reflection

***Question:***

***Answer:***

***Question:***

***Answer:***

***Question:***

***Answer:***

***Question:***

***Answer:***

***Question:***

***Answer:***

***Question:***

***Answer:***

***Question:***

***Answer:***

***Question:***

***Answer:***