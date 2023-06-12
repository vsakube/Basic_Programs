#include <iostream>
#include <vector>

// Function to convert adjacency matrix to adjacency list
std::vector<std::vector<int>> adjacencyMatrixToList(const std::vector<std::vector<int>>& adjMatrix) {
    int n = adjMatrix.size(); // Number of vertices in the graph

    std::vector<std::vector<int>> adjList(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjMatrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    return adjList;
}

// Function to print the adjacency list
void printAdjacencyList(const std::vector<std::vector<int>>& adjList) {
    int n = adjList.size(); // Number of vertices in the graph

    for (int i = 0; i < n; ++i) {
        std::cout << "Vertex " << i << ": ";
        for (int j : adjList[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example adjacency matrix
    std::vector<std::vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    // Convert adjacency matrix to adjacency list
    std::vector<std::vector<int>> adjList = adjacencyMatrixToList(adjMatrix);

    // Print the adjacency list
    printAdjacencyList(adjList);

    return 0;
}

