//consider only the main funciton, the DFS needs altering
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set> // To store visited nodes

using namespace std;

vector<vector<int>> graph;//keeping this global because otherwise will have to pass as argument again and again
vector<int> visited;
stack<int> toVisit; //gray


void pushEdge(int x, int y){ //creates adjacency list (not weighted adjacency matrix)
    graph[x].push_back(y);
    graph[y].push_back(x);
}

// an elemenr being 'white' is the same as bfs not being done on it
void dfs(int x){
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
        int next = toVisit.top();
        toVisit.pop();
        dfs(next);
    }
    
}


int main() {
    
    int n,m,x,y;//n is edges x and y are nodes input for edge
    
    cin>>n>>m;
    graph.resize(n+1, vector<int>()); //2*n(2n cuz vertices cant be more than 2 times edges) (also assuming consecutive numbering for nodes) rows, unspecified columns
    visited.resize(n+1,0);
    
    for(int i=0; i<m; i++){
        cin>>x>>y;
        pushEdge(x,y);
    }
    cout<<"bitch";
    int count =0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
    
    cout<<"Count: "<<count;
    return 0;
}
