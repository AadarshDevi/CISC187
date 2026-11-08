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
1. ***Why does each undirected edge appear twice in an adjacency-list representation?*** In an undirected graph, each node is connected to another node as a bidirectional edge. This means each node is connected to another node. Both the nodes need to create a connection to the other node. This is why there are duplicate edges. 
2. ***Why is the total storage for an adjacency list commonly described as O(V + E)?*** $O(V)$ is the space needed for $N$ nodes. Next are the edges. $O(E)$ is the space needed for directed edges. It is also the same space needed for the undirected edges because $O(2E) = O(E)$. $2E$ is 2 edges between 2 nodes for an undirected edge. So if we add the sum for the total storage needed it boils down to $O(V) + O(E) = O(V+E)$.
3. ***Why are adjacency lists especially useful for sparse graphs?*** In an adjunct list, the graph has undirected edges. This means the number of edges in the graph is less than the theoretical total number of edges in the graph.

## Part 8 — Directed Graphs

```
A -> B
A -> C
B -> D
C -> B
D -> C
D -> E
```

***Questions:*** Consider the directed edges above.
1. ***Which vertices are adjacent from `A`?*** `B, C`
2. ***Is `A` adjacent from `B`? Explain.*** Yes, `A` is adjacent to `B` because there is an edge going from `A` to `B`. This is because in a directed graph, the edge points one way. If I go from A to B, I cannot go back from B to A because then i would need a new edge for it. 
3. ***Give one directed path from `A` to `E`.*** $A\rightarrow B\rightarrow D\rightarrow E$
4. ***Identify whether a directed cycle exists.*** Yes, there is a cycle in the graph: $B\rightarrow D\rightarrow C\rightarrow B$
5. ***Explain why adding an edge to a directed adjacency list differs from adding an undirected edge.*** Adding an undirected edge allows us to traverse between 2 nodes back and forth. But adding a directed edge allows traversal in one direction, there is no going back. Think of an undirected edge as a two way road and a directed edge as a one way road.

## Part 9 — Weighted Graphs

Consider the weighted graph below, Calculate the total cost of:
1. $A \rightarrow B \rightarrow E=4+3=7$
2. $A \rightarrow C \rightarrow B \rightarrow E=2+1+3=6$
3. $A \rightarrow C \rightarrow D \rightarrow E=2+8+2=12$

```
A --4--> B
A --2--> C
B --5--> D
C --1--> B
C --8--> D
B --3--> E
D --2--> E
```

***Question:*** Which of these paths has the lowest total weight? 
***Answer:*** Path $A \rightarrow C \rightarrow B \rightarrow E$ has the lowest weight of $6$.

***Question:*** Explain why the path with the fewest edges is not necessarily the path with the lowest cost.
***Answer:*** Some paths can have a lot of edges, but their weights can be lower, or a short path can have larger weights. Some paths can have a combo of large and small weighted edges. So path length does not equal lowest cost.
## Part 10 — Dijkstra's Shortest Path Algorithm

Use the weighted graph and run Dijkstra's algorithm starting from `A`. But before doing so, initialize:
1. Distance of `A` to `0`.
2. All other distances to infinity.
3. All predecessors to null.

Original Graph:

```
A --4--> B
A --2--> C
B --5--> D
C --1--> B
C --8--> D
B --3--> E
D --2--> E
```

Initialized Graph:

```
--code-block-empty
```

Complete a table showing the important updates.

|Current Vertex|Adjacent Vertex|Current Distance|Alternative Distance|Update?|Predecessor|
|---|---|---|---|---|---|
|||||||
|||||||
|||||||
|||||||
|||||||
***Question:*** After the algorithm finishes:
1. ***Give the shortest distance from `A` to every vertex.***
2. ***Use predecessor information to reconstruct the shortest path from `A` to `E`.***
3. ***Explain why predecessor values are needed if you want the actual path rather than only its total cost.***