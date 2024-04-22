//copied
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100005

// Structure to represent a node in the binary tree
struct TreeNode {
    int label;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to count nodes at distance x from node k
int dfs(struct TreeNode *node, struct TreeNode *parent, int distances[], int x, int distance) {
    if (node == NULL) return 0;

    distances[node->label] = distance;

    int count = 0;
    // Recursive DFS for left child
    count += dfs(node->left, node, distances, x, distance + 1);
    // Recursive DFS for right child
    count += dfs(node->right, node, distances, x, distance + 1);

    // Count nodes at distance x
    if (distances[node->label] == x) count++;

    return count;
}

// Function to create a new node
struct TreeNode *createNode(int label) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->label = label;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Main function
int main() {
    int N, k, x;
    scanf("%d %d %d", &N, &k, &x);

    // Array to store distances of nodes from node k
    int distances[MAX_NODES] = {0};

    // Build the binary tree
    struct TreeNode *nodes[MAX_NODES];
    for (int i = 1; i <= N; i++) {
        int label;
        scanf("%d", &label);
        nodes[i] = createNode(label);
    }
    for (int i = 1; i <= N / 2; i++) {
        nodes[i]->left = nodes[2 * i];
        nodes[i]->right = nodes[2 * i + 1];
    }

    // Perform DFS from node k and count nodes at distance x
    int result = dfs(nodes[k], NULL, distances, x, 0);
    printf("%d\n", result);

    // Free memory
    for (int i = 1; i <= N; i++) {
        free(nodes[i]);
    }

    return 0;
}
