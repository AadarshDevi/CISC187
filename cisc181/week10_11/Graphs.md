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
7. ***Explain the difference between a path's length and the distance between two vertices.*** The path length is the
   number of edges between the starting and ending vertices in the path. Distance is the shortest path from starting and
   ending vertices.

## Part 2 — Graphs vs. Trees

***Question:*** Explain why every tree is a graph, but not every graph is a tree. Your response should discuss: Cycles,
Connectivity, and Disconnected vertices. Then determine whether each structure below could be considered a tree.

***Answer:*** A tree is a graph because it comprises nodes and branches which are also used in graphs. They are the same
building blocks used to build graphs. In a tree, a node connects to other nodes, so does a graph. But not all graphs can
be trees in some situations.

When a graph is not a tree, it is because there is cycle in the graph. In a tree, 1 node can only connect to the nodes
below itself. In a graph, any node can connect any other node. In a tree a node can only have 1 parent node, but a graph
can have 0 to $\infty$.

Another reason some graphs can't be trees, is that in a graph, some nodes can be disconnected from the graph even though
it is still part of it. In a tree, all nodes will always be connected to other nodes, sometimes the path is long, but
they are connected. A node in a tree has to be connected to another node, but in a graph, it can just exist.

| Structure                                       | Tree? | Reason                                                                                                             |
|-------------------------------------------------|-------|--------------------------------------------------------------------------------------------------------------------|
| Connected graph with no cycles                  | Yes   | The branches will branch out and not mix with other branches. Nodes will have 1 parent node only.                  |
| Connected graph containing a cycle              | No    | The branches can merge into another node making it not a tree. A node in a tree cannot have multiple parent nodes. |
| A cyclic graph with two disconnected components | No    | Nodes cannot be alone, they must be connected to another node.                                                     |
## Part 3 — Adjacency List Representation

I redrew the question as a graph

```
	A
  /   \
 v     v
B ----> C
|	    |
v       v
D ----> E
  \   /
	V
	F
```

***Question:*** Using the graph from Part 1, create its adjacency list.

| Vertex | Adjacent Vertices |
| ------ | ----------------- |
| A      | B, C              |
| B      | A, C, D           |
| C      | A, B, E           |
| D      | B, E, F           |
| E      | C, D, F           |
| F      | D, E              |
***Questions:***
1. ***Why does each undirected edge appear twice in an adjacency-list representation?***
2. ***Why is the total storage for an adjacency list commonly described as O(V + E)?***
3. ***Why are adjacency lists especially useful for sparse graphs?***