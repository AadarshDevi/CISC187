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
        if (source == destination) return;

        // checking if there is an edge between vertices
        for (int i: adjacencyList[source])
            if (i == destination)
                return;

        // no edge, add it
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source);
    }

    void display() const {
        int iterator = 0;
        for (vector<int> vec: adjacencyList) {
            cout << "Vertex " << iterator << " --> ";
            for (int vert: adjacencyList[iterator])
                cout << vert << " ";
            cout << "\n";
        }
    }

    void bfs(int start) const;

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
