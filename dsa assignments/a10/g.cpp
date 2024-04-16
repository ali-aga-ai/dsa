#include<bits/stdc++.h>
using namespace std;
#define MAX 100

vector<int> distances;
unordered_set<int> visited;
unordered_set<int> unvisited;
vector<vector<int>> graph;
int n;

void initialise(int x){//initialise distances to be infinity
    distances.resize(n+1,MAX);
    distances[x] = 0;
    for(int i=1; i<n+1; i++){
        unvisited.insert(i);
    }
}

int findMin() {//find minimum distance element from source
    int minIndex = -1;
    for (int i = 1; i <= n; ++i) {
        if (distances[i] != MAX && visited.find(i) == visited.end()) {
            if (minIndex == -1 || distances[i] < distances[minIndex]) {
                minIndex = i;
            }
        }
    }
    return minIndex;
}

void daka(int x){//from a node do dijkstra (update neighbour distance if it makes it closer to source. and do dijkistra for next closest element)
    
    unvisited.erase(x);
    visited.insert(x);
    
    for(int neighbour = 1; neighbour <= n; neighbour++){
        if (graph[x][neighbour] != 0 && visited.find(neighbour) == visited.end()) {
            if (distances[neighbour] > distances[x] + graph[x][neighbour]) {
                distances[neighbour] = distances[x] + graph[x][neighbour];
            }
        }
    }
    
    int y = findMin();
    if (y != -1) {
        daka(y);
    }
}

int main() {
    
    int m,a,b,w;
    cin>>n>>m;
    
    graph.resize(n+1,vector<int>(n+1,0));
    for(int i=0; i<m; i++){
        cin>>a>>b>>w;
        graph[a][b] = w;
    }
    initialise(1);

    daka(1);
    
    for(int i=1; i<=n; i++){
        if(distances[i] != MAX)
            cout<<distances[i]<<" ";
    }
    return 0;
}
