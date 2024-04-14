//lets first implement a DFS algorithm with an adjacency list (doesnt work for cycles)
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
    
    dfs(start);//x being last entered 
    

    return 0;
}




//changes need to be made for better readablity using for(int neighbour: ) instead of while loop
//use unordered set cuz easier to fins if exists or not, no need to assign 1 to visited