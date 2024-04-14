
//lets first implement a BFS algorithm with an adjacency list (doesnt work for cycles)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;//keeping this global because otherwise will have to pass as argument again and again
vector<int> visited;
queue<int> toVisit; //gray


void pushEdge(int x, int y){ //creates adjacency list (not weighted adjacency matrix)
    graph[x].push_back(y);
    graph[y].push_back(x);
}

// an elemenr being 'white' is the same as bfs not being done on it
void bfs(int x){
    cout<<x<<" ";
    visited[x] = 1;
    
    int p =0;
    
    while(p<graph[x].size()){
        // a problem of recolouring something gray might arise
        if(visited[graph[x][p]]!=1){
            int element = graph[x][p];
            toVisit.push(element);
        }
        p++;
    }
    
    if(!toVisit.empty()){
        int next = toVisit.front();
        toVisit.pop();
        bfs(next);
    }
    
}


int main() {
    
    int n,x,y;//n is edges x and y are nodes input for edge
    
    cin>>n;
    graph.resize(2*n, vector<int>()); //2*n(2n cuz vertices cant be more than 2 times edges) (also assuming consecutive numbering for nodes) rows, unspecified columns
    
    visited.resize(2*n);
    for(int i=0; i<n; i++){
        cin>>x>>y;
        pushEdge(x,y);
    }
    
    int start;
    
    cout<<"Root for BFS?";
    cin>>start;
    
    bfs(start);//x being last entered 
    

    return 0;
}