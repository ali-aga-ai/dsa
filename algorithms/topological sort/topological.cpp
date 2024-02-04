#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortUtil(int vertex, vector<vector<int>>& graph, vector<int>& visited, stack<int>& s) {
    visited[vertex] = 1;
    for (int i : graph[vertex]) {
        if (!visited[i]) {
            topologicalSortUtil(i, graph, visited, s);
        }
    }
    s.push(vertex);
}

void topologicalSort(vector<vector<int>>& graph, int vertices) {
    vector<int> visited(vertices, 0);
    stack<int> s;

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, graph, visited, s);
        }
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    // Example usage:
    int vertices = 6;
    vector<vector<int>> graph = { //u can create an adjacency matrix as well
        {1, 2},
        {2, 3},
        {4},
        {5},
        {},
        {}
    };

    topologicalSort(graph, vertices);

    return 0;
}
