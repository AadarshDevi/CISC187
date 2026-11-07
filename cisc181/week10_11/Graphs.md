# Week 10/11 - Graphs

## Part 1 — Graph Terminology

```
A-B
A-C
B-C
B-D
C-E
D-E
E-F
```

***Questions:***
1. ***List all vertices.*** `A, B, C, D, E, F`
2. ***List every vertex adjacent to `B`.*** `A, C, D`
3. ***List every vertex adjacent to `E`.*** `C, D, F`
4. ***Give one valid path from `A` to `F`.*** $A\rightarrow B\rightarrow D\rightarrow E\rightarrow F$
5. ***What is the length of the path you provided?*** `4`
6. ***Determine the shortest distance from `A` to `F`.*** $A\rightarrow C\rightarrow E\rightarrow F$
7. ***Explain the difference between a path's length and the distance between two vertices.*** The path length is the number of edges between the starting and ending vertices in the path. Distance is the shortest path from starting and ending vertices.
## Part 2 — Graphs vs. Trees

***Question:*** Explain why every tree is a graph, but not every graph is a tree. Your response should discuss: Cycles, Connectivity, and Disconnected vertices. Then determine whether each structure below could be considered a tree.

|Structure|Tree?|Reason|
|---|---|---|
|Connected graph with no cycles|||
|Connected graph containing a cycle|||
|Acyclic graph with two disconnected components|||

## Part 3 — Adjacency List Representation