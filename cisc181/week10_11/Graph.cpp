//
// Created by CryosArtic on 11/8/2026.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    vector<vector<int> > adjacencyList;

public:
    Graph(int vertices) {
        adjacencyList.resize(vertices);
    }

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

    /*
    BFS(startV) {
   Enqueue startV in frontierQueue
   Add startV to discoveredSet

   while ( frontierQueue is not empty ) {
      currentV = Dequeue from frontierQueue
      "Visit" currentV
      for each vertex adjV adjacent to currentV {
         if ( adjV is not in discoveredSet ) {
            Enqueue adjV in frontierQueue
            Add adjV to discoveredSet
         }
      }
   }
}
     */

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
    }

    void dfs(int start) const;
};

int main() {
    constexpr int vertices = 5;
    Graph graph(vertices);
    graph.addEdge(0, 1);
    graph.addEdge(2, 3);
    graph.addEdge(4, 2);
    graph.addEdge(4, 3);
    graph.display();
}
