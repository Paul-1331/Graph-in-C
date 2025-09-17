#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "bfs.h"

/* This gives the basic standard implementation of bfs, we can replace visited and 
implement it just with the distance array if we want.
Bfs gives the single source shortest path in unweighted graphs*/


void bfs(Graph* g, int start) {
    bool* visited = calloc(g->numVertices, sizeof(bool));
    int* dist = malloc(g->numVertices*sizeof(int));
    for(int i = 0;i<g->numVertices;i++){
        dist[i] = -1;
    }
    dist[start] = 0;
    int queue[2*g->numVertices]; // make size as large as necessary
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        Edge* e = g->adjList[u];
        while (e) {
            int v = e->to;
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u]+1;
                queue[rear++] = v;
            }
            e = e->next;
        }
    }
    free(visited);
}
