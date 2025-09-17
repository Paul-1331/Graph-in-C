#ifndef DFS_H
#define DFS_H

#include <stdbool.h>
#include "graph.h"

void dfs(Graph* g, int u, bool*visited, int*pre, int*post, int*clock);

#endif