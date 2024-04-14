//copied and i dont understand

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> subtreeSize;
int n;

void pushEdge(int x, int y) {
    graph[x].push_back(y);
    graph[y].push_back(x);
}

void dfs(int node, int parent) {
    subtreeSize[node] = 1;
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            subtreeSize[node] += subtreeSize[neighbor];
        }
    }
    if (subtreeSize[node] > n / 2) {
        cout << "Node: " << node << " has more than half of the nodes in its subtree." << endl;
        // You can return the node here or store it in a variable for further processing
    }
}

int main() {
    int a, b;

    cin >> n;

    graph.resize(n + 1, vector<int>());
    subtreeSize.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        pushEdge(a, b);
    }

    dfs(1, -1); // Start DFS from node 1 with no parent (-1)

    return 0;
}
// Perform a depth-first search (DFS) starting from any node to calculate the size of each subtree.
// While traversing the tree, at each node, calculate the size of its subtree including itself.
// If at any point, the size of the subtree (including the current node) is greater than 

// n is the total number of nodes in the graph, then this subtree contains more than half of the nodes. You can stop the traversal and output the current node as the result.