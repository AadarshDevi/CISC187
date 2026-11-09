# Week 10/11 - Graphs
## Table of Contents

1. [Part 1 — Graph Terminology](#part-1--graph-terminology)
2. [Part 2 — Graphs vs. Trees](#part-2--graphs-vs-trees)
3. [Part 3 — Adjacency List Representation](#part-3--adjacency-list-representation)
4. [Part 4 — Adjacency Matrix Representation](#part-4--adjacency-matrix-representation)
5. [Part 5 — Implement an Adjacency-List Graph](#part-5--implement-an-adjacency-list-graph)
6. [Part 6 — Breadth-First Search](#part-6--breadth-first-search)
7. Part 7
8. [Part 8 — Directed Graphs](#part-8--directed-graphs)
9. [Part 9 — Weighted Graphs](#part-9--weighted-graphs)
10. [Part 10 — Dijkstra's Shortest Path Algorithm](#part-10--dijkstras-shortest-path-algorithm)
11. [Part 11 — When Should Dijkstra's Algorithm Be Used?](#part-11--when-should-dijkstras-algorithm-be-used))
12. // Part 12
13. Part 13
14. // [Analysis & Reflection](#analysis-and-reflection)
15. [Extra](#extra)
	   - [Part 10](#part-10)

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
        |
	    v
		F
```

***Question:*** Using the graph from Part 1, create its adjacency list.

| Vertex | Adjacent Vertices |
| ------ | ----------------- |
| A      | B, C              |
| B      | A, C, D           |
| C      | A, B, E           |
| D      | B, E              |
| E      | C, D, F           |
| F      | D, E              |

***Questions:***
1. ***Why does each undirected edge appear twice in an adjacency-list representation?*** In an undirected graph, each node is connected to another node as a bidirectional edge. This means each node is connected to another node. Both the nodes need to create a connection to the other node. This is why there are duplicate edges. 
2. ***Why is the total storage for an adjacency list commonly described as O(V + E)?*** $O(V)$ is the space needed for $N$ nodes. Next are the edges. $O(E)$ is the space needed for directed edges. It is also the same space needed for the undirected edges because $O(2E) = O(E)$. $2E$ is 2 edges between 2 nodes for an undirected edge. So if we add the sum for the total storage needed it boils down to $O(V) + O(E) = O(V+E)$.
3. ***Why are adjacency lists especially useful for sparse graphs?*** In an adjunct list, the graph has undirected edges. This means the number of edges in the graph is less than the theoretical total number of edges in the graph.

## Part 4 — Adjacency Matrix Representation

Create the adjacency matrix for the same graph.

|     |  A  |  B  |  C  |  D  |  E  |  F  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  A  |     |  1  |  1  |     |     |     |
|  B  |  1  |     |  1  |  1  |     |     |
|  C  |  1  |  1  |     |     |  1  |     |
|  D  |     |  1  |     |     |  1  |     |
|  E  |     |     |  1  |  1  |     |  1  |
|  F  |     |     |     |  1  |  1  |     |

***Question:***
1. ***Why is the matrix symmetric for this graph?*** The graph uses undirected edges which means the two nodes can traverse to each other easily. This is y the graph is symmetric. Node B can traverse to Node C and vice versa. The nodes each have a edge to the other node. There are 2 edges between the two nodes.
2. ***How quickly can an adjacency matrix determine whether two vertices are adjacent?*** It will take $O(1)$ because we are using a matrix (2D array). We do not have to traverse the entire 2D array because we know the row and col of the nodes. We can just point access the item and check if it is 1 (for adjacent) or 0 (not adjacent).
3. ***Why does the matrix require $O(V^2)$ space?*** It will take $O(V^2)$ space because we are using a matrix (2D array) of $V\times V$ elements. 
4. ***Why may this representation be wasteful for sparse graphs?*** In a graph, not all nodes are connected to other nodes. There could be nodes that do not connect to other nodes. In this case, there are less edges between all of the nodes. Most of the items in the matrix will be empty. There is no point in storing a lot of 0s.

## Part 5 — Implement an Adjacency-List Graph

Implement an undirected graph in C++ using an adjacency list. For this lab, vertices may be represented using integer indices. You may use a structure similar to:

Given Template:

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyList;

public:
    Graph(int vertices);

    void addEdge(int source, int destination);
    void display() const;

    void bfs(int start) const;
    void dfs(int start) const;
};
```

### Implement `addEdge()`

Because the graph is undirected, adding the edge must update the adjacency lists of both vertices.

```c++
void addEdge(int source, int destination) {  
    // src and dest same  
    if (source == destination) {  
        cout << "Source and destination vertices are he same.\n";  
        return;  
    }  
  
    if (source > adjacencyList.size() || source < 0) {  
        cout << "Source vertex out of bounds!\n";  
        return;  
    }  
  
    if (destination > adjacencyList.size() || destination < 0) {  
        cout << "Destination vertex out of bounds!\n";  
        return;  
    }  
  
    // checking if there is an edge between vertices  
    for (int i: adjacencyList[source])  
        if (i == destination) {  
            cout << "Source and Destination have an edge.\n";  
            return;  
        }  
  
    // no edge, add it  
    adjacencyList[source].push_back(destination);  
    adjacencyList[destination].push_back(source);  
}
```

### Implement `display()`

Display every vertex followed by its adjacent vertices.

```c++
void display() const {  
    int iterator = 0;  
    cout << "Vertices:\n";
    
    for (vector<int> vec: adjacencyList) {  
        cout << "\t" << iterator << " --> ";
        
        for (int vert: adjacencyList[iterator])  
            cout << vert << " ";  
		
        cout << "\n";  
        iterator++;  
    }  
}
```

#### Output

```terminalOutput
Vertices:
        0 --> 1
        1 --> 0
        2 --> 3 4
        3 --> 2 4
        4 --> 2 3
```

## Part 6 — Breadth-First Search

Breadth-First Search visits vertices by increasing distance from the starting vertex. BFS uses a **queue** to maintain the frontier. Implement `void bfs(int start) const;`. Your BFS should:
1. Enqueue the starting vertex.
2. Mark the starting vertex as discovered.
3. Repeatedly dequeue a vertex.
4. Visit that vertex.
5. Examine its adjacent vertices.
6. Enqueue only vertices that have not already been discovered.
7. Continue until the queue is empty.

### Code: `bfs()`

```c++
void bfs(int start) const {  
    // valid num: start  
    if (start < 0 || start >= adjacencyList.size()) {  
        cout << "Source vertex out of bounds!\n";  
        return;  
    }  
  
    // create lists to store child nodes  
    queue<int> frontierQueue;  
  
    // creates a list to track if the node was visited/discovered; setting default val to false  
    vector<bool> discoveredSet(adjacencyList.size(), false);  
  
    // push starting vertex  
    frontierQueue.push(start);  
  
    cout << "Visited Vertex Order: ";  
  
    // int current vertex  
    while (!frontierQueue.empty()) {  
        // get the oldest item in the list  
        int currentVertex = frontierQueue.front();  
        frontierQueue.pop();  
        //std::cout << "Current Vertex: " << currentVertex << " - ";  
        cout << currentVertex << " ";  
  
        // we discovered the vertex  
        discoveredSet[currentVertex] = true;  
        //cout << "Visited ? " << visited(discoveredSet[currentVertex]) << "\n";  
  
        // loop through each edge in adjacentList        for (int vertex: adjacencyList[currentVertex]) {  
            // node already not found  
            if (!discoveredSet[vertex]) {  
                frontierQueue.push(vertex); // add node  
                discoveredSet[vertex] = true; // set visited=true  
                //cout << "New Vertex Discovered: " << vertex << " - " << visited(discoveredSet[vertex]) << "\n";            }  
        }  
    }  
    cout << "\n";  
}  
  
inline std::string visited(bool visited) const {  
    return visited ? "true" : "false";  
}
```

### BFS Trace

Use the graph below. Assume adjacent vertices are processed alphabetically.

```
A-B
A-D
B-C
B-E
D-E
E-F
C-F
```

***Question:*** Starting from `A`, complete a trace showing the queue and discovered set.

| Step | Visited Vertex | Queue          | Discovered Vertices |
| ---- | -------------- | -------------- | ------------------- |
| 0    | $\text{Empty}$ | $A$            | $A$                 |
| 1    | $A$            | $B,D$          | $A,B,D$             |
| 2    | $B$            | $D,C,E$        | $A,B,C,D,E$         |
| 3    | $D$            | $C,E$          | $A,B,C,D,E$         |
| 4    | $C$            | $E,F$          | $A,B,C,D,E,F$       |
| 5    | $E$            | $F$            | $A,B,C,D,E,F$       |
| 6    | $F$            | $\text{Empty}$ | $A,B,C,D,E,F$       |

***Question:*** Identify the distance from `A` to every reachable vertex.
***Answer:*** Because the graph is not weighted, we will assume each edge has a weight of 1.

| Vertex | Distance from $A$ | Path                                       |
| ------ | ----------------- | ------------------------------------------ |
| $A$    | 0                 | $A$                                        |
| $B$    | 1                 | $A\rightarrow B$                           |
| $C$    | 2                 | $A\rightarrow B\rightarrow C$              |
| $D$    | 1                 | $A\rightarrow D$                           |
| $E$    | 2                 | $A\rightarrow B\rightarrow E$              |
| $F$    | 4                 | $A\rightarrow B\rightarrow C\rightarrow F$ |

## Part 7 — Depth-First Search

Depth-First Search follows a path as deeply as possible before backtracking. The lecture presents an iterative version using a **stack**. Implement `void dfs(int start) const;`. Your DFS should:

1. ***Push the starting vertex onto the stack.***
2. ***Pop the top vertex.***
3. ***If it has not already been visited, visit it.***
4. ***Add it to the visited set.***
5. ***Push its adjacent vertices onto the stack.***
6. ***Continue until the stack is empty.***

### Code `dfs()`

```c++
void dfs(int start) const {  
    // valid num: start  
    if (start < 0 || start >= adjacencyList.size()) {  
        cout << "Source vertex out of bounds!\n";  
        return;  
    }  
  
    // stack to hold vertices  
    stack<int> vertex_stack;  
  
    // list for nodes visited  
    vector<bool> discoveredSet(adjacencyList.size(), false);  
  
    // add start to stack  
    vertex_stack.push(start);  
  
    cout << "Visited Vertex Order (DFS): ";  
  
    // loop through each item when stack is not empty  
    while (!vertex_stack.empty()) {  
        int currentVertex = vertex_stack.top();  
        vertex_stack.pop();  
  
        if (!discoveredSet[currentVertex]) {  
            discoveredSet[currentVertex] = true;  
  
            cout << currentVertex << " ";  
  
            // all adj vertices of node are added to stack  
            for (int vertex: adjacencyList.at(currentVertex)) {  
                vertex_stack.push(vertex);  
            }  
        }  
    }  
    cout << "\n";  
}
```

### DFS Trace

Use the graph below. Assume adjacent vertices are considered alphabetically, but remember that stack behavior affects the actual pop order.

```
A-B
A-D
B-C
B-E
D-E
E-F
C-F
```

I am using the following letters and their corresponding numbers

| A   | B   | C   | D   | E   | F   |
| --- | --- | --- | --- | --- | --- |
| 0   | 1   | 2   | 3   | 4   | 5   |

The table as letters:

| Step | Popped Vertex | Stack (Bottom --> Top) | Visited Vertices |
| ---- | ------------- | ---------------------- | ---------------- |
| 0    | $Empty$       | $A$                    | $Empty$          |
| 1    | $A$           | $B,D$                  | $A$              |
| 2    | $D$           | $B,A,E$                | $A,D$            |
| 3    | $E$           | $B,A,D,F$              | $A,D,E$          |
| 4    | $F$           | $B,A,D,C,E$            | $A,D,E,F$        |
| 5    | $E$           | $B,A,D,C$              | $A,D,E,F$        |
| 6    | $C$           | $B,A,D,B,F$            | $A,D,E,F,C$      |
| 7    | $F$           | $B,A,D,B$              | $A,D,E,F,C$      |
| 8    | $B$           | $B,A,D,A,C,E$          | $A,D,E,F,C,B$    |
| 9    | $E$           | $B,A,D,A,C$            | $A,D,E,F,C,B$    |
| 10   | $C$           | $B,A,D,A$              | $A,D,E,F,C,B$    |
| 11   | $A$           | $B,A,D$                | $A,D,E,F,C,B$    |
| 12   | $D$           | $B,A$                  | $A,D,E,F,C,B$    |
| 13   | $A$           | $B$                    | $A,D,E,F,C,B$    |
| 14   | $B$           | $Empty$                | $A,D,E,F,C,B$    |

The table as numbers

| Step | Popped Vertex | Stack (Bottom --> Top) | Visited Vertices |
| ---- | ------------- | ---------------------- | ---------------- |
| 0    | Empty         | 0                      | Empty            |
| 1    | 0             | 1, 3                   | 0                |
| 2    | 3             | 1, 0, 4                | 0, 3             |
| 3    | 4             | 1, 0, 3, 5             | 0, 3, 4          |
| 4    | 5             | 1, 0, 3, 2, 4          | 0, 3, 4, 5       |
| 5    | 4             | 1, 0, 3, 2             | 0, 3, 4, 5       |
| 6    | 2             | 1, 0, 3, 1, 5          | 0, 3, 4, 5, 2    |
| 7    | 5             | 1, 0, 3, 1             | 0, 3, 4, 5, 2    |
| 8    | 1             | 1, 0, 3, 0, 2, 4       | 0, 3, 4, 5, 2, 1 |
| 9    | 4             | 1, 0, 3, 0, 2          | 0, 3, 4, 5, 2, 1 |
| 10   | 2             | 1, 0, 3, 0             | 0, 3, 4, 5, 2, 1 |
| 11   | 0             | 1, 0, 3                | 0, 3, 4, 5, 2, 1 |
| 12   | 3             | 1, 0                   | 0, 3, 4, 5, 2, 1 |
| 13   | 0             | 1                      | 0, 3, 4, 5, 2, 1 |
| 14   | 1             | 1                      | 0, 3, 4, 5, 2, 1 |

Explain why BFS and DFS can visit the same vertices in different orders.

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
A --4-- B
A --2-- C
B --5-- D
C --1-- B
C --8-- D
B --3-- E
D --2-- E
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

| Starting Node | Next Node | Weight |
| ------------- | --------- | ------ |
| A             | B         | 4      |
| A             | C         | 2      |
| B             | D         | 5      |
| C             | B         | 1      |
| C             | D         | 8      |
| B             | E         | 3      |
| D             | E         | 2      |

Initialization:

| Starting Node | Distance |
| ------------- | -------- |
| A             | $0$      |
| B             | $\infty$ |
| C             | $\infty$ |
| D             | $\infty$ |
| E             | $\infty$ |

Complete a table showing the important updates.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| A              | C               | $\infty$         | $0+2=2$              | Yes     | A           |
| B              | E               | $\infty$         | $3+3=6$              | Yes     | B           |
| C              | B               | 4                | $2+1=3$              | Yes     | C           |
| B              | D               | 10               | $3+5=8$              | Yes     | B           |
| B              | E               | $\infty$         | $3+3=6$              | Yes     | B           |

Check [extra](#extra) for the entire calculations.

***Question:*** After the algorithm finishes:
1. ***Give the shortest distance from `A` to every vertex.***

| Node              | B   | C   | D   | E   |
| ----------------- | --- | --- | --- | --- |
| Distance from $A$ | 3   | 2   | 8   | 6   |

2. ***Use predecessor information to reconstruct the shortest path from `A` to `E`.*** $A\rightarrow C\rightarrow B\rightarrow E$.
3. ***Explain why predecessor values are needed if you want the actual path rather than only its total cost.*** The total cost to get from `A` to `E` is only the distance. It does not say what path to take to get the least distance, that's what ***Dijkstra's Shortest Path Algorithm*** gives. We use predecessors to get the path that has the least distance.
## Part 11 — When Should Dijkstra's Algorithm Be Used?

For each graph below, state whether Dijkstra's algorithm is appropriate and explain why.

| Graph                                                 | Use Dijkstra? | Reason                                                                                                                                                                                                                     |
| ----------------------------------------------------- | ------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Weighted graph with only non-negative edge weights    | Yes           | Weights are not negative so the algorithm can go through vertices and edges to return a shortest path and the algorithm cannot go wrong.                                                                                   |
| Unweighted graph treated as all edges having weight 1 | Yes           | Because each edge is unweighted, we can assume each edge has a weight of `1`, this would give use many more options to find the shortest path. It will still work, it might take longer because each edge's weight is `1`. |
| Directed graph containing a negative edge weight      | no            | When having negative weights, the algorithm might not be able to give the right shortest path, it could give a long path.                                                                                                  |

## Part 12 — Complexity Analysis

Complete the following table. Do not provide only final Big-O values. Explain why each complexity occurs.

| Operation / Representation               | Big-O    | Explanation                                                                                                                                                                                                  |
| ---------------------------------------- | -------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Adjacency-list storage                   | $O(V+E)$ | Each vertex has a list, meaning it is a list of lists. Each list holds the edges to other nodes. An edge would be repeated twice if the edges are undirected. So $O(V) + O(2E \text{ or}\space E) = O(V+E)$. |
| Adjacency-matrix storage                 | $O(V^2)$ | Each vertex has a row and col of its own. If we have $V$ vertices, then we will store $V\times V$ items. Each item is a boolean, 1 for has edges and 0 for no edges between it and another node.             |
| Matrix adjacency check                   | $O(1)$   | We have information, the indices of both vertices, with that we can point access the correct index and check for edges between them.                                                                         |
| Dijkstra with list-based unvisited queue |          |                                                                                                                                                                                                              |
| Dijkstra with binary-heap priority queue |          |                                                                                                                                                                                                              |

## Analysis and Reflection

***Questions:***
1. ***Why adjacency lists are often preferred for sparse graphs.*** In an adjacent list, the only data stored is the adjacent edges. It does not store all the edges like a matrix. We can access the list for the node, and traverse it. We check it if the node we have is connected to the node.
2. ***Why adjacency matrices provide fast adjacency checking.*** Unlike the list, the matrix has all combos of all the edges, so we can get the nodes indices and we can point access the edge.
3. ***Why BFS uses a queue.***
4. ***Why DFS uses a stack.***
5. ***Why already-discovered or visited vertices must be tracked.***
6. ***Why BFS can determine shortest distance in an unweighted graph.***
7. ***Why BFS does not automatically solve weighted shortest-path problems.***
8. ***Why directed edges must not automatically be treated as bidirectional.*** A directed edge is an arrow from one vertex to another. We do not know if the other vertex has an edge to the vertex. If there is no edge, we will not be able to traverse the opposite way.
9. ***Why Dijkstra's algorithm stores predecessors.*** The algorithm stores predecessors so we can build the path with the least weights. Without the path, we will only have the least weights which i not useful when alone.
10. ***Why Dijkstra's algorithm should not be used when negative edge weights are present.*** If the weights are negative, the algorithm might not be able to get the shortest path.

## Extra

### Part 6

With the graph give:

```
A-B
A-D
B-C
B-E
D-E
E-F
C-F
```

We start with $A$.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| A              | ?               | 0                | ?                    | No      | null        |
| A              | B               | $\infty$         | $0+1=1$              | Yes     | A           |
| A              | D               | $\infty$         | $0+1=1$              | Yes     | A           |

Because $B$ and $D$ have the same distance, we'll take the first one, $B$.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| B              | ?               | 1                | ?                    | No      | A           |
| B              | C               | $\infty$         | $1+1=2$              | Yes     | B           |
| B              | E               | $\infty$         | $1+1=2$              | Yes     | B           |

Like $B$, $C$ and $E$ have the same distance, we'll take $C$.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| A              | ?               | 0                | ?                    | No      | null        |
| A              | B               | $\infty$         | $0+1=1$              | Yes     | A           |
| A              | D               | $\infty$         | $0+1=1$              | Yes     | A           |


| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| A              | ?               | 0                | ?                    | No      | null        |
| A              | B               | $\infty$         | $0+1=1$              | Yes     | A           |
| A              | D               | $\infty$         | $0+1=1$              | Yes     | A           |


### Part 10

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| A              | null            | 0                | 0                    | N/A     | null        |

Now we check adjacent vertices of $A$.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| A              | B               | $\infty$         | $0+4=4$              | Yes     | A           |
| A              | C               | $\infty$         | $0+2=2$              | Yes     | A           |

From all the edges of $A$, C has the least distance.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| C              | ?               | 2                | ?                    | N/A     | A           |

We check check the edges of $C$.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| C              | B               | 4                | $2+1=3$              | Yes     | C           |
| C              | D               | $\infty$         | $2+8=10$             | Yes     | C           |

From this, B has the least distance.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| B              | ?               | 3                | ?                    | N/A     | C           |

Checking adjacent vertices of $B$.

| Current Vertex | Adjacent Vertex | Current Distance | Alternative Distance | Update? | Predecessor |
| -------------- | --------------- | ---------------- | -------------------- | ------- | ----------- |
| B              | D               | 10               | $3+5=8$              | Yes     | B           |
| B              | E               | $\infty$         | $3+3=6$              | Yes     | B           |

Now we have reached $E$.