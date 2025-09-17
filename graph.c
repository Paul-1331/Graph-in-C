#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

/* Create a graph with n vertices */
Graph* createGraph(int numVertices, int directed) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    if (!g) return NULL;

    g->numVertices = numVertices;
    g->directed = directed;
    g->adjList = (Edge**)malloc(numVertices * sizeof(Edge*));

    if (!g->adjList) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < numVertices; i++) {
        g->adjList[i] = NULL;
    }

    return g;
}

/* Free the graph */
void freeGraph(Graph* g) {
    if (!g) return;
    for (int i = 0; i < g->numVertices; i++) {
        Edge* curr = g->adjList[i];
        while (curr) {
            Edge* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(g->adjList);
    free(g);
}

/* Add edge */
void addEdge(Graph* g, int from, int to, int weight) {
    if (!g || from >= g->numVertices || to >= g->numVertices) return;

    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = to;
    newEdge->weight = weight;
    newEdge->next = g->adjList[from];
    g->adjList[from] = newEdge;

    if (!g->directed) {
        Edge* revEdge = (Edge*)malloc(sizeof(Edge));
        revEdge->to = from;
        revEdge->weight = weight;
        revEdge->next = g->adjList[to];
        g->adjList[to] = revEdge;
    }
}

/* Remove edge */
void removeEdge(Graph* g, int from, int to) {
    if (!g || from >= g->numVertices || to >= g->numVertices) return;

    Edge** curr = &g->adjList[from];
    while (*curr) {
        if ((*curr)->to == to) {
            Edge* temp = *curr;
            *curr = (*curr)->next;
            free(temp);
            break;
        }
        curr = &((*curr)->next);
    }

    if (!g->directed) {
        curr = &g->adjList[to];
        while (*curr) {
            if ((*curr)->to == from) {
                Edge* temp = *curr;
                *curr = (*curr)->next;
                free(temp);
                break;
            }
            curr = &((*curr)->next);
        }
    }
}

/* Check if edge exists */
bool hasEdge(const Graph* g, int from, int to) {
    if (!g || from >= g->numVertices || to >= g->numVertices) return false;

    Edge* curr = g->adjList[from];
    while (curr) {
        if (curr->to == to) return true;
        curr = curr->next;
    }
    return false;
}

/* Print graph */
void printGraph(const Graph* g) {
    if (!g) return;
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        Edge* curr = g->adjList[i];
        while (curr) {
            printf("-> %d (w=%d) ", curr->to, curr->weight);
            curr = curr->next;
        }
        printf("\n");
    }
}