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
