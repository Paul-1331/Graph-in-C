#include <stdio.h>
#include "graph.h"

int main() {
    // Create an undirected graph with 5 vertices
    Graph* g = createGraph(5, 0);// number of vertices, and second argument is 0 for undirected and 1 for directed

    // Add some edges
    addEdge(g, 0, 1, 10);
    addEdge(g, 0, 4, 20);
    addEdge(g, 1, 2, 30);
    addEdge(g, 1, 3, 40);
    addEdge(g, 2, 3, 50);
    addEdge(g, 3, 4, 60);

    // Print graph
    printf("Graph adjacency list:\n");
    printGraph(g);

    // Test edge existence
    printf("\nDoes edge (0 -> 4) exist? %s\n", hasEdge(g, 0, 4) ? "Yes" : "No");
    printf("Does edge (2 -> 0) exist? %s\n", hasEdge(g, 2, 0) ? "Yes" : "No");

    // Remove an edge
    printf("\nRemoving edge (1 -> 3)...\n");
    removeEdge(g, 1, 3);
    printGraph(g);

    // Free memory
    freeGraph(g);

    return 0;
}

