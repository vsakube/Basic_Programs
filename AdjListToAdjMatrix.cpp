#include <iostream>
#include <vector>

// Function to convert adjacency list to adjacency matrix
std::vector<std::vector<int>> adjacencyListToMatrix(const std::vector<std::vector<int>>& adjList) {
    int n = adjList.size(); // Number of vertices in the graph

    // Initialize the adjacency matrix with all zeros
    std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j : adjList[i]) {
            adjMatrix[i][j] = 1;
        }
    }

    return adjMatrix;
}

// Function to print the adjacency matrix
void printAdjacencyMatrix(const std::vector<std::vector<int>>& adjMatrix) {
    int n = adjMatrix.size(); // Number of vertices in the graph

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example adjacency list
    std::vector<std::vector<int>> adjList = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1, 4},
        {1, 2, 3}
    };

    // Convert adjacency list to adjacency matrix
    std::vector<std::vector<int>> adjMatrix = adjacencyListToMatrix(adjList);

    // Print the adjacency matrix
    printAdjacencyMatrix(adjMatrix);

    return 0;
}

