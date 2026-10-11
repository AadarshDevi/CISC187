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

>[!NOTE]
>The code for LinkedList is updated during each parts if there were any mistakes.

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

Implement `void insertFront(int value);` and the operation should:

1. [x] Dynamically create a new node.
2. [x] Make the new node point to the current first node.
3. [x] Update `head`.

```c++
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
```

### Test Suite

Testing to see if `insertfront()` works correctly.

```c++
LinkedList list = LinkedList();  
list.display();  
  
list.insertFront(30);  
list.insertFront(20);  
list.insertFront(10);  
list.display();  
  
list.insertFront(5);  
list.display();
```

### Output

```terminalOutput
Linked List is Empty
10 20 30
5 10 20 30
```

### Pointer Analysis

1. ***Explain why the order of pointer updates matters.*** The order of the pointers matter because they dictate how the
   items in the list are ordered. If two pointers switch, then the two nodes will have their places switched. It means
   the values will also be in a different order. If the order in a list is $10\rightarrow20\rightarrow30$ then a pointer
   switch can change the order: $10\rightarrow30\rightarrow20$.
2. ***What could happen if `head` were changed before preserving the connection to the existing list?*** If head was
   changed before preserving the connection, the new node will be connected to the list, but the rest of the list will
   be lost to memory. Those links were severed and not saved.

### Complexity

***Question:*** Determine the Big-O complexity of `insertFront()` and explain why traversal is not required.

***Answer:*** The time complexity to add an item in the front is $O(1)$. We are taking a node and we are getting the head's link and we are moving it to the new node. And the head now points to the new node. There is no moving of data, it is just added in the front where the pointers are changed.

## Part 6 — Insert at the End

Implement `void insertBack(int value);` Assume your class maintains only `Node* head;` and does **not** maintain a tail pointer. Your implementation must correctly handle:
1. [x] An empty list.
2. [x] A list containing one node.
3. [x] A list containing multiple nodes.

```c++
  
void insertBack(int value) {  
    // check if list is empty  
    if (empty()) {  
        Node *node = new Node{value, head};  
        head = node;  
        return;  
    }  
  
    // create new last node  
    Node *node = new Node{value, nullptr};  
  
    // check if the list has a single node  
    if (head->next == nullptr) {  
        head->next = node;  
        return;
    }  
      
    // find the last node  
    Node *lastNode = head;  
    while (lastNode->next != nullptr) {  
        lastNode = lastNode->next;  
    }  
  
    // set the last node to point at the new node  
    lastNode->next = node;  
}
```

### Test Suite

```c++
// Empty Linked List
LinkedList list = LinkedList();  
list.display();  
  
// Add 1 item to simulate single item
list.insertFront(20);  
list.display();  

list.insertBack(30);  
list.display();  

// Add another item to simulate multiple items
list.insertFront(10);
list.display();  
  
list.insertBack(40);  
list.display();
```

### Output

```terminalOutput
Linked List is Empty
20
20 30
10 20 30
10 20 30 40
```

### Part 6 Analysis

***Question:*** Explain why insertion at the end is O(N) when only a `head` pointer is maintained. Then explain how maintaining a `tail` pointer would change the complexity of insertion at the end.

***Answer:*** The insertion at the end of the `LinkedList` is $O(N)$ because we have to iterate through he entire list to get the last item on the list. Once we get it, we add the new node. A tail pointer will point to the last pointer. It is like the header but for the last item in the list. With this, we have direct access to the last item on the list. We can add it and update the tail pointer to the new last  node.

## Part 7 — Search the List

Implement `bool search(int value) const;`. Traverse the list starting from `head` and return `true` if the value exists and `false` otherwise. Test:

1. [x] ***10***: A value at the beginning.
2. [x] ***50***: A value in the middle
3. [x] ***100***: A value at the end.
4. [x] ***120***: A value not present.

```c++
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
        current = current->next; // next node
    }  
  
    // value not found  
    return false;  
}
```
### Test Suite

```c++
// Populate an Empty List
LinkedList list = LinkedList();  
for (int i = 1; i <= 10; i++) {  
	list.insertBack(i * 10);  
}  
list.display();
  
std::cout << "Found Value: 10 ? " << list.search(10) << "\n";
std::cout << "Found Value: 50 ? " << list.search(50) << "\n";  
std::cout << "Found Value: 100 ? " << list.search(100) << "\n";  
std::cout << "Found Value: 120 ? " << list.search(120) << "\n";
```

### Output

```terminalOutput
10 20 30 40 50 60 70 80 90 100
Found Value: 10 ? 1    // true
Found Value: 50 ? 1    // true
Found Value: 100 ? 1   // true
Found Value: 120 ? 0   // false
```

### Complexity Analysis

***Question:*** Determine the best-case and worst-case complexity. Explain what list arrangement produces each case.

***Answer:*** Time complexities:
1. ***Best Case: $O(1)$*** - The value is found at the first node. No need to traverse the entire list. From the test above, because `10` was in the first node, we did not have to go through the entire list.
2. ***Worst Case: $O(N)$*** - The value is at the last node in the list. We have to traverse the entire list to find the last value. The value `100` and `120` in the test shows the wort case. The former is in the last node of the list while the latter isn't in the list at all. For both, we still have to go through each node in the list.

## Part 8 — Insert After a Specific Value

Implement `bool insertAfter(int target, int value);`. Return `false` if `target` cannot be found.
### Example

```c++
// Before: 10 → 20 → 30 → 40 → nullptr
insertAfter(20, 25);
// After:  10 → 20 → 25 → 30 → 40 → nullptr
```

### Method `insertAfter()`

```c++
bool insertAfter(int target, int value) {  
    // node cannot be inserted after a value in an empty list  
    if (empty()) return false;  
  
    // find target node  
    Node *targetNode = head;  
  
    while (targetNode != nullptr) {  
        if (targetNode->data == target) {  
            break;  
        }  
        targetNode = targetNode->next;  
    }  
  
	// the target value doesn't exist
    if (targetNode == nullptr) return false;  
  
    // get target's old next pointer  
    Node *oldNext = targetNode->next;  
  
    // create a new node with the pointer to the target's old next pointer  
    Node *newNode = new Node{value, oldNext};  
  
    // target node points to new node  
    targetNode->next = newNode;  
  
    // node inserted successfully  
    return true;  
}
```

### Test

```c++
// Fill up empty list
LinkedList list = LinkedList();  
for (int i = 1; i <= 4; i++) {  
    list.insertBack(i * 10);  
}  
list.display();  

// insert a value after a value that does exists
std::cout << "Insert Successful: 20 -> 25 ? " << (list.insertAfter(20, 25) ? "true" : "false") << "\n";  
list.display();  

// insert a value after a value that doesn't exist
std::cout << "Insert Successful: 60 -> 80 ? " << (list.insertAfter(60, 80) ? "true" : "false") << "\n";  
list.display();
```
### Output

```terminalOutput
10 20 30 40
Insert Successful: 20 -> 25 ? true
10 20 25 30 40
Insert Successful: 60 -> 80 ? false
10 20 25 30 40
```
### Pointer Reasoning

***Question:*** Before writing the function, explain the two pointer changes required to insert the new node without disconnecting the remainder of the list.

***Answer:*** To insert a value, the pointer the current and previous nodes are needed. The previous node connects to the new node and the new node connects to the next node. ***(Answered before writing code)***
### Complexity

***Question:*** Explain why the actual pointer insertion is O(1), but the complete `insertAfter()` operation can still be O(N).

***Answer:*** Adding a value in the middle is taking the previous node's connection and the next node's connection and passing it through the new node instead of next node. This is an easy operation which give it $O(1)$. But getting to the previous and next node to insert new node means traversing the list. This is where the $O(N)$ comes from. We are traversing the list, $O(N)$ and inserting the new value, $O(1)$.

## Part 9 — Delete a Node

Implement `bool remove(int value);`. Before calling `delete`, make sure the remaining nodes are properly reconnected. Your function must correctly handle:
1. [ ] An empty list.
2. [ ] Removing the first node.
3. [ ] Removing a middle node.
4. [ ] Removing the last node.
5. [ ] Attempting to remove a value that does not exist.

### Example

```c++
// Before 10 → 20 → 30 → 40 → nullptr
remove(30);
// After: 10 → 20 → 40 → nullptr
```

### Method `delete()`

```c++
bool remove(int value) {  
    // list is empty  
    if (empty()) return false;  
  
    // keep track of current and previous node  
    Node *current = head;  
    Node *previous = nullptr;  
  
    while (current != nullptr) {  
        // node with the value to be removed found  
        if (current->data != value) {  
            previous = current; // current node is now previous node  
            current = current->next; // the next node is the current node  
            continue;  
        }  
  
        // the node that has the value is not connected to the list anymore  
        if (previous == nullptr) {  
            head = current->next;  
        } else {  
            previous->next = current->next;  
        }  
  
        // delete current  
        delete current;  
        return true;  
    }  
  
    return false;  
}
```

### Test

```c++
LinkedList list = LinkedList();  
list.display();  
  
// empty list  
std::cout << "Remove Node: 30 ? " << (list.remove(30) ? "true" : "false") << "\n";  
list.display();  
  
// delete from a single item list  
list.insertBack(1 * 10);  
list.display();  
  
std::cout << "Removed Node: 10 ? " << (list.remove(10) ? "true" : "false") << "\n";  
list.display();  
  
// populate list  
for (int i = 2; i <= 10; i++) {  
    list.insertBack(i * 10);  
}  
list.display();  
  
// remove first node  
std::cout << "Removed First Node: 10 ? " << (list.remove(10) ? "true" : "false") << "\n";  
list.display();  
  
// remove middle node  
std::cout << "Removed Middle Node: 50 ? " << (list.remove(50) ? "true" : "false") << "\n";  
list.display();  
  
// remove last node  
std::cout << "Removed Last Node: 100 ? " << (list.remove(100) ? "true" : "false") << "\n";  
list.display();  
  
// empty list  
std::cout << "Nonexistent Node: 120 ? " << (list.remove(120) ? "true" : "false") << "\n";  
list.display();
```

### Output

```terminalOutput
Linked List is Empty
Remove Node: 30 ? false
Linked List is Empty
10
Removed Node: 10 ? true
Linked List is Empty
20 30 40 50 60 70 80 90 100
Removed First Node: 10 ? false
20 30 40 50 60 70 80 90 100
Removed Middle Node: 50 ? true
20 30 40 60 70 80 90 100
Removed Last Node: 100 ? true
20 30 40 60 70 80 90
Nonexistent Node: 120 ? false
20 30 40 60 70 80 90
```

### Part 9 Analysis

1. ***Why does deleting the head require special handling?*** If the head is only deleted, the rest of the list will remain in memory which means they cannot be freed from memory. So before the head is deleted, we preserve the link to the first node so we can delete the entire list.
2. ***Why must access to the node be preserved before it is deleted?*** When the pointer to the next node is deleted, there is no way to access the node or any node after that. It's lost to memory. If it is preserved, we will be able to access the data after the preserved node.
3. ***What is a memory leak?*** if the node connection isn't preserved, the rest of the nodes are inaccessible but still present in memory. They cannot be deleted, access or be released. These nodes will gather in memory and grow as time goes. At a certain point they can end up swallowing the entire memory. This memory cannot be used. It is wasted. Nothing can use it.
4. ***Why is accessing a node after `delete` unsafe?*** Accessing a node after deleting it is like burning a book and then trying to read it. There's nothing. You are trying to find the book and searching frantically for something that no longer exists. For memory, we are trying to access information that no longer exists. We are trying to read info from a specific address that no longer exists.

## Part 10 — Test the Complete Linked List

### Class `LinkedList`

The completed `class LinkedList` is below

```c++

// LinkedList Node
struct Node {  
    int data;  
    Node *next;  
};  

// LinkedList
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
            return;  
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
            current = current->next;  
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
  
        // check if the list has a single node  
        if (head->next == nullptr) {  
            head->next = node;  
            return;  
        }  
  
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
            targetNode = targetNode->next;  
        }  
  
        if (targetNode == nullptr) return false;  
  
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
            if (current->data != value) {  
                previous = current; // current node is now previous node  
                current = current->next; // the next node is the current node  
                continue;  
            }  
  
            // the node that has the value is not connected to the list anymore  
            if (previous == nullptr) {  
                head = current->next;  
            } else {  
                previous->next = current->next;  
            }  
  
            // delete current  
            delete current;  
            return true;  
        }  
  
        return false;  
    }  
  
    ~LinkedList() {  
        // get start of the node  
        Node *current = head;  
  
        // loop through list  
        while (current != nullptr) {  
            // get next node  
            Node *next = current->next;  
  
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

### Test

Write a `main()` function that demonstrates the major operations. Your output should make it possible to verify that the list remains correctly connected after every structural modification. Your test should include:

1. [x] Create an empty list
2. [x] Verify that it is empty
3. [x] Insert several values at the front
4. [x] Insert several values at the back
5. [x] Display the list
6. [x] Search for existing and missing values
7. [x] Insert after a value in the middle
8. [x] Attempt insertion after a nonexistent value
9. [x] Remove the first node
10. [x] Remove a middle node
11. [x] Remove the last node
12. [x] Attempt to remove a nonexistent value
13. [x] Display the final list

```c++
// 1. Create an empty list  
LinkedList list = LinkedList();  
  
// 2. Verify that it is empty  
list.display();  
  
// 3. Insert several values at the front  
for (int i = 1; i < 6; i++) {  
    list.insertFront(i * 10 * 3 / 2);  
}  
  
// 4. Insert several values at the back  
for (int i = 1; i < 6; i++) {  
    list.insertBack(i * 10 * 5 / 2);  
}  
  
// 5. Display the list  
list.display();  
  
// 6. Search for existing and missing values  
std::cout << "Item Found: 45 ? " << (list.search(45) ? "true" : "false") << "\n";  
std::cout << "Item Found: 10 ? " << (list.search(10) ? "true" : "false") << "\n";  
  
// 7. Insert after a value in the middle  
std::cout << "Inserted Value: 15 -> 230 ? " << (list.insertAfter(15, 230) ? "true" : "false") << "\n";  
  
// 8. Attempt insertion after a nonexistent value  
std::cout << "Inserted Value: 120 -> 40 ? " << (list.insertAfter(120, 40) ? "true" : "false") << "\n";  
  
// 9. Remove the first node  
std::cout << "Removed Value: 75 ? " << (list.remove(75) ? "true" : "false") << "\n";  
  
// 10. Remove a middle node  
std::cout << "Removed Value: 230 ? " << (list.remove(230) ? "true" : "false") << "\n";  
  
// 11. Remove the last node  
std::cout << "Removed Value: 125 ? " << (list.remove(125) ? "true" : "false") << "\n";  
  
// 12. Attempt to remove a nonexistent value  
std::cout << "Removed Value: 1192 ? " << (list.remove(1192) ? "true" : "false") << "\n";  
  
// 13. Display the final list  
list.display();
```

### Output

```terminalOutput
Linked List is Empty
75 60 45 30 15 25 50 75 100 125
Item Found: 45 ? true
Item Found: 10 ? false
Inserted Value: 15 -> 230 ? true
Inserted Value: 120 -> 40 ? false
Removed Value: 75 ? true
Removed Value: 230 ? true
Removed Value: 125 ? true
Removed Value: 1192 ? false
60 45 30 15 25 50 75 100
```

## Part 11 — Memory Management

Your linked list dynamically allocates nodes using `new` Therefore, the class must release the allocated memory. Implement `~LinkedList();`, the destructor, it should traverse the list and delete every remaining node.

```c++
~LinkedList() {  
    // get start of the node  
    Node *current = head;  
  
    // loop through list  
    while (current != nullptr) {  
        // get next node  
        Node *next = current->next;  
  
        // delete current node  
        delete current;  
  
        // current node is next node  
        current = next;  
    }  
  
    // make head point to nothing  
    head = nullptr;  
}
```

### Part 11 Analysis

Suppose a program repeatedly creates nodes but never calls `delete`. Explain:

1. ***What happens to the allocated memory?*** The data in in memory that is not freed. It will continue to accumulate and stare the computer from it's memory.
2. ***Why is this considered a memory leak?*** The data goes in memory but is not freed, aka unused data is not leaving memory. Like I said in the previous question, it will eat up all the memory.
3. ***Why is memory management especially important when implementing linked structures with raw pointers?*** It is easy to forget to free memory. When using it in memory tight places, the inaccessible data can remain in the already little memory. Data not needed removed from memory can save this from happening.

## Part 12 — Complexity Analysis

Complete the table for your implementation. Assume the list maintains a `head` pointer but **no tail pointer**. Do not provide only the Big-O notation. Explain what traversal or pointer manipulation causes each result.

| Operation                      | Big-O  | Explanation                                                                                                                                                                                        |
| ------------------------------ | ------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Access element at position `i` | $O(N)$ | The item can be anywhere in the list which means we have to traverse the list. If it is long, it will take longer.                                                                                 |
| Search                         | $O(N)$ | We have to search for the number through the entire list. If there are $N$ values, we have to search all of them.                                                                                  |
| Insert at beginning            | $O(1)$ | We add a new node and change what the pointers are pointing at. we are not moving or traversing data. We can use the `head` to get the first element and then insert the new node in between them. |
| Insert at end                  | $O(N)$ | We are adding the value at the end of the list. But because we do not have a `tail`, we have to traverse the entire list to be able to get the last node and append it.                            |
| Insert after a specified value | $O(N)$ | Like traversing the end, we have to traverse the list to find the specific item and add the new value after that.                                                                                  |
| Delete first node              | $O(1)$ | We get the `head` and we delete the node. Simple.                                                                                                                                                  |
| Delete specified value         | $O(N)$ | We have to traverse the list in order to find the value then get the previous node and next node and connect them.                                                                                 |
| Traverse entire list           | $O(N)$ | We are going through every single item in the list which means $N$ items will take time. If $N$ is bigger, it will take longer to travel.                                                          |

## Part 13 — Linked List vs. Array

Consider an array and a singly linked list, each containing `N` elements. Compare them for:
1. **Accessing the element at index `N/2`.** An array will be faster because it has direct access to all the indices. It can directly get the value. The list has to go through every item using pointers to get the middle value.
2. **Inserting at the beginning.** Adding a new value at the front is faster in the list because we change where the pointers are pointing but in an array, we have to shift the value to the right so we have space for the new value.
3. **Removing the first element.** Removing a value from an array will be faster because we can do $\text{array.length} - 1$ to get the last item and remove it but in a list, we have to go through the list and then get to the last list before we can delete it.
4. **Searching for a particular value.** Searching for a value will be faster in a n array because we have access to the array where it can order to make it faster for searching. The list will take longer to find it because the items could be anywhere in the list.
5. **Memory layout.** An array is faster because all the items are next to each other in memory while the items in a list are all over memory and need to get the pointers to find the next item in the list.
6. **Ability to grow dynamically.** Lists can grow easily because the pointers can just point to the new node and not have to worry about changing or shifting values. For an array, we have to create a larger list and then copy the old values to the new extended list and only then can we add the new value.
7. **Additional memory required per element.** For an array because the items are right next to each other, we do not need pointers which will take up more space in memory. Linked lists other than storing data will have the pointers.

### Part 13 Analysis

***Question:*** Explain why linked lists can perform some insertion and deletion operations efficiently but cannot provide O(1) random access.

***Answer:*** :Linked Lists can easily do insertions and deletions efficiently because they can add or delete a new node and do not have to shifts the values in the list. After the item is inserted or deleted, the pointers point to a new node instead. This makes inserting and deleting nodes very fast.

## Part 14 — Reasoning About a Tail Pointer

Your current implementation maintains `Node* head` and remember that a singly linked list does not store a pointer from a node to its predecessor. Suppose you modify it to maintain:

```
Node* head;
Node* tail;
```

Answer:
1. ***Which operation from your implementation becomes significantly faster?*** The operation that I think would benefit from this is `insertBack()` because we do not have to traverse the entire list to add an item to the end of the list.
2. ***What is its new Big-O complexity?*** With this addition, `insertBack()` will take $O(N)$ instead of $O(1)$.
3. ***Does maintaining `tail` make searching O(1)?*** No, We would still have to traverse the entire list.
4. ***Does maintaining `tail` make deleting the final node O(1) in a singly linked list?*** No, it would not make a difference.
5. ***Explain your answer to Question 4.*** Deleting a node from a list with one item means both the `head` and `tail` would point to the same thing. So there would be no difference. We can use either to remove the item.

## Part 15 — Singly vs. Doubly Linked Lists

You do **not** need to implement a complete doubly linked list for this part. A doubly linked-list node contains:

```
struct Node {
    int data;
    Node* prev;
    Node* next;
};
```

Answer:
1. **What additional information does `prev` provide?** `prev` is `next` but for the opposite direction. `next` is a pointer to a node next in line in the list while `prev` is a pointer to the node that is before the current node.
2. **Why can a doubly linked list traverse in both directions?** Because we have access to the front and back, moving through the list will be the same. One goes to the right, and the other left.
3. **How does the additional pointer affect memory usage?** Memory will increase for each node because it is carrying an additional pointer.
4. **If you already have a pointer directly to a node, why can deletion be easier in a doubly linked list?** deletion will become faster because we can find the `targetNode` and get it's previous and next nodes and then link them both. then we can delete the `targetNode`. It will make linking easier.

## Part 16 — Circular Linked Lists

You do **not** need to implement a complete circular linked list. Consider:

```
head
 ↓
10 → 20 → 30 → 40
↑              |
|______________|
```

In a circular singly linked list: `last->next == head` rather than `last->next == nullptr`. Answer:
1. ***Why would a normal `while (temp != nullptr)` traversal fail?*** This is like circular indexing in the HashTable except here, the last item on the list will be linked to the first item on the list.
2. ***What condition could determine when one complete traversal has finished?*** A count variable can be useful to keep track of the no of items int he list. It can help us traverse the list without endlessly traversing through.
3. ***Why are circular linked lists suitable for repeated cyclic processing?*** In circular linking, the last item is linked to the first item, this means we would go in circles instead of a row.  Anything that needs to go forever can have something like this.
4. ***Give one application where circular behavior would be useful.*** The only useful application I can think of using Circular Linked Lists would be for performing some tasks that have to happen in order for a very long time, like a scheduler in a microcontroller, or something that is trying to pull information from the internet so it can be up to date.

## Analysis and Reflection

Connect your answers to your implementation and observations rather than providing only definitions. Briefly discuss:
1. ***Why linked lists do not require contiguous memory.*** The nodes have pointers to the next or previous node in the list so because of this, the nodes can be anywhere in memory.
2. ***The role of the `head` pointer.*** The role of the pointer is to have a visible starting point to the list and also to make sure the nodes don't end up leaking memory.
3. ***Why traversal is O(N).*** We are going through every single node in the list.
4. ***Why insertion at the beginning is O(1).*** We are moving the head to point at the new node where it's own pointer will point to the old first node.
5. ***Why insertion at the end is O(N) without a tail pointer.*** We have to go through the entire list to be able to add the new node.
6. ***Why deletion requires careful pointer manipulation.*** If we forget to point the values to the right nodes, we might lose data. If some of the ndoes are not deleted after removing, we have a memory leak.
7. ***Why dynamically allocated nodes must eventually be deallocated.*** We can have many nodes in memory that do not need to be there. This will in turn increase the memory used by the program. These nodes, cannot be accessed and the only way to destroy them is to terminate the program.
8. ***Why a linked list cannot perform binary search efficiently like an indexed array.*** Pointers will take longer than indexing. So sorting the list will take longer. Another thing is if the list is a singly linked list, we do not have a `tail` to give the end of the list. Even if we have a `tail`, we can only travel one way, left. So in order to be able traverse both directions, we would need a `prev` pointer. This will increase the size of the node which makes it taking more space.
9. ***When a linked list may be preferable to an array or vector.*** A linked list is most preferable for when we are doing many insertion and deletion operations. Arrays and vectors have to move data in order to insert or delete data.
10. ***When an array or vector may be preferable to a linked list.*** Arrays and vectors are preferable when we are doing more searches and sorting than inserting and deleting items. Because they are a block in memory, it is faster to find values.
