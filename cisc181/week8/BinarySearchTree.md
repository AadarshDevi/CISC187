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
