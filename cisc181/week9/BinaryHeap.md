# Binary Heap

## Part 1 — Is It a Valid Max-Heap?

| Heap | Max Heap? | Heap Condition                                                           | Complete-Tree?                                                                                                                                                    |
| ---- | --------- | ------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| A    | Yes       | $90 \geq 70 \space\&\space 80, 70 \geq 20 \space\&\space 40, 80 \geq 60$ | Yes, from root to height - 1, all of them are filled up completely from left to right.                                                                            |
| B    | Yes       | $90 \geq 70 \space\&\space 80, 70 \geq 40, 80 \geq 60$                   | No, the nodes have to fill up from left to right on all heights/depths. But on the last level, 70 has 40 in its right node instead of left node. So it is invalid |
| C    | No        | Invalid because $90 \leq 95$                                             | Tree is complete but it is invalid because Heap condition is broken.                                                                                              |
## Part 2 — Heap vs. Binary Search Tree

```
	100
   /   \
  80    70
 / \    / \
20 60  50 40
```

Answer the following:
1. ***Why is this a valid max-heap?*** Yes, the parent nodes are greater than their child nodes.
2. ***Why is it not necessarily a Binary Search Tree?*** In BST, the values are sorted in a way that the lesser number is in the left and the greater num in the right. This wouldn't be a valid BST.
3. ***If searching for `40`, can you determine from the root whether to search left or right?*** Because each child node cannot be greater than the parent node, the path taken will be: `100, 70, 40`,
4. ***Why is arbitrary searching generally O(N) in a heap?*** Because the parent nodes are  greater than the child nodes, we have to check each child node to see if it is the greater or less than the targeted value.
5. ***Which value can be accessed immediately in a max-heap?*** The root node can be accessed immediately ($O(1)$).
## Part 3 — Represent a Heap Using an Array (Not completed)

Convert the following heap into an array using level-order storage:

```
        90
       /  \
     70    80
    / \    / \
   20 40  60 50
```

Complete the table:

|Index|Value|
|---|---|
|0||
|1||
|2||
|3||
|4||
|5||
|6||

### Index Relationships

For a node stored at index `i`:

```
Left child  = 2 * i + 1
Right child = 2 * i + 2
Parent      = (i - 1) / 2
```

Integer division is used when calculating the parent.

For indices `1`, `2`, `4`, and `5`, determine:

- Parent index
- Left-child index, if it exists
- Right-child index, if it exists