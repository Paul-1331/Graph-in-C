#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "dfs.h"

/*This gives the basic standard implementation of dfs, we have pre post arrays along with clock can be used
to find valuable information regarding the graph such as presence of cycle.
Other valuable information such as parent array can also be added if necessary.
Any dfs problem can be solved by slight modifications to this code*/

void dfs(Graph* g, int u, bool* visited,int*pre,int*post,int*clock) {
    visited[u] = true;
    pre[u] = ++(*clock);

    Edge* e = g->adjList[u];
    while (e) {
        int v = e->to;
        if (!visited[v]){
            dfs(g, v, visited,pre,post,clock);
        }
        e = e->next;
    }
    post[u] = ++(*clock);
}

/* user this driver function in main for dfs
    bool*visited = calloc(g->numVertices,sizeof(bool));
    int clock = 0;
    int*pre = malloc(g->numVertices*sizeof(int));
    int*post = malloc(g->numVertices*sizeof(int));
    for(int i = 0;i<g->numVertices;i++){
        if(!visited[i]){
            dfs(g,i,visited,pre,post,&clock);
        }
    }
*/
