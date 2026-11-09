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

            // loop through each edge in adjacentList
            for (int vertex: adjacencyList[currentVertex]) {
                // node already not found
                if (!discoveredSet[vertex]) {
                    frontierQueue.push(vertex); // add node
                    discoveredSet[vertex] = true; // set visited=true
                    //cout << "New Vertex Discovered: " << vertex << " - " << visited(discoveredSet[vertex]) << "\n";
                }
            }
        }
        cout << "\n";
    }

    inline std::string visited(bool visited) const {
        return visited ? "true" : "false";
    }

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

        // loop through each item when stack is not empty
        while (!vertex_stack.empty()) {
            int currentVertex = vertex_stack.top();
            vertex_stack.pop();

            if (!discoveredSet[currentVertex]) {
                vertex_stack.push(currentVertex);
                discoveredSet[currentVertex] = true;

                // all adj vertices of node are added to stack
                for (int vertex: adjacencyList[currentVertex]) {
                    vertex_stack.push(vertex);
                }

            }
        }
    }
};

int main() {
    constexpr int vertices = 6; // indices 0-5, no unused slot
    Graph graph(vertices);

    graph.addEdge(0, 1); // A-B
    graph.addEdge(0, 3); // A-D
    graph.addEdge(1, 2); // B-C
    graph.addEdge(1, 4); // B-E
    graph.addEdge(3, 4); // D-E
    graph.addEdge(4, 5); // E-F
    graph.addEdge(2, 5); // C-F

    graph.display();
    cout << "\n";
    graph.bfs(0); // start at A
}
