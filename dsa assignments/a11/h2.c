#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100005

int graph[MAX_NODES][2]; // Assuming each node has at most 2 children
int visited[MAX_NODES];

void dfs(int node, int k, int x, int distance, int *count) {
    visited[node] = 1;
    if (distance == x) {
        (*count)++;
    }
    if (distance >= x) {
        return;
    }
    if (graph[node][0] != -1 && !visited[graph[node][0]]) {
        dfs(graph[node][0], k, x, distance + 1, count); // Explore left child
    }
    if (graph[node][1] != -1 && !visited[graph[node][1]]) {
        dfs(graph[node][1], k, x, distance + 1, count); // Explore right child
    }
    int parent = node / 2;
    if (parent > 0 && !visited[parent]) {
        dfs(parent, k, x, distance + 1, count); // Explore parent node
    }
}

int count_nodes_at_distance(int n, int k, int x) {
    int count = 0;
    dfs(k, k, x, 0, &count);
    return count;
}

int main() {
    int N, k, x;
    scanf("%d %d %d", &N, &k, &x);

    // Initialize graph
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
        graph[i][0] = -1;
        graph[i][1] = -1;
    }

    // Build graph
    for (int i = 1; i <= N; i++) {
        int label;
        scanf("%d", &label);
        //no need for label values
        //adjacency list where graph[i][0] and graph[i][1] store the left and right children of node i, respectively.
        if (2 * i <= N) {
            graph[i][0] = 2 * i;
        }
        if (2 * i + 1 <= N) {
            graph[i][1] = 2 * i + 1;
        }
    }

    printf("%d\n", count_nodes_at_distance(N, k, x));

    return 0;
}
