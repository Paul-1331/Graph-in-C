#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>  // for NULL
#include <stdbool.h>

typedef struct Edge {
    int to;             
    int weight; // for unweighted graphs, put weight = 1         
    struct Edge* next;  
} Edge;

typedef struct Graph {
    int numVertices;    
    int directed;       // 0 = undirected, 1 = directed
    Edge** adjList;     
} Graph;

// Create a graph with n vertices
Graph* createGraph(int numVertices, int directed);

// Free the graph
void freeGraph(Graph* g);

// Add an edge from 'from' to 'to' with weight
void addEdge(Graph* g, int from, int to, int weight);

// Remove an edge
void removeEdge(Graph* g, int from, int to);

// Check if an edge exists
bool hasEdge(const Graph* g, int from, int to);

// Print the graph
void printGraph(const Graph* g);

#endif