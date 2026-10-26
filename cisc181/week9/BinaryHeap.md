# Binary Heap

## Part 1 — Is It a Valid Max-Heap?

| Heap | Max Heap? | Heap Condition                                                           | Complete-Tree?                                                                                                                                                    |
| ---- | --------- | ------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| A    | Yes       | $90 \geq 70 \space\&\space 80, 70 \geq 20 \space\&\space 40, 80 \geq 60$ | Yes, from root to height - 1, all of them are filled up completely from left to right.                                                                            |
| B    | Yes       | $90 \geq 70 \space\&\space 80, 70 \geq 40, 80 \geq 60$                   | No, the nodes have to fill up from left to right on all heights/depths. But on the last level, 70 has 40 in its right node instead of left node. So it is invalid |
| C    | No        | Invalid because $90 \leq 95$                                             | Tree is complete but it is invalid because Heap condition is broken.                                                                                              |
