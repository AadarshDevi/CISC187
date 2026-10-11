# Week 7: Linked List

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
5. ***What would happen to your ability to access the list if `head` were lost?*** We would not be able access the data at all. The address of `Node first` is lost which subsequently means the rest of the Nodes' address are lost.
## Part 2 — Trace a Linked List
## Part 3

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
| :-------: | :----------: | :----------: |
|     1     |      10      | Second Node  |
|     2     |      20      |  Third Node  |
|     3     |      30      | Fourth Node  |
|     4     |      40      |   nothing    |
***Question: Explain why the traversal stops.*** The traversal stops because the last Node, `fourth` does not have a pointer to a valid Node. There is no node, so it points to nothing.
### Part 2 Complexity
***Question:*** If the list contains `N` nodes, determine the Big-O complexity of traversing the entire list and explain your reasoning.

***Answer:*** $N$ Nodes contain $N-1$ pointers. So for each node, the iterator has to go from the front to the back. if it misses it, it has to go to the start and then iterate. It cannot just go back a `Node`. So based on this information,
1. Best Case: $O(1)$ - The data needed is in the front
2. Worst Case: $O(N)$ - The data is at the end of the list.
## Part 4
## Part 5
## Part 6
## Part 7
## Part 8
## Part 9
## Part 10
## Part 11
## Part 12
## Part 13
## Part 14
## Part 15
## Part 16
## Analysis and Reflection