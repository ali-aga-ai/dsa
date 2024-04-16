#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
unordered_set<int> visited;
stack<int> toVisit;

int n;

void pushEdge(int x, int y){
    graph[x].push_back(y);
    graph[y].push_back(x);
}

void dfs(int x){
    if(visited.find(x)== visited.end()){
        visited.insert(x);
        
        for(int neighbour: graph[x]){//can do this cuz adj list NOT adj matrix
            if(visited.find(neighbour)== visited.end())
            toVisit.push(neighbour);
        }
        
        if(!toVisit.empty()){
            int y = toVisit.top();
            toVisit.pop();
            dfs(y);
        }
    }
    
}


int main() {
    
    int n,m,a,b;
    
    cin>>n>>m;
    
    graph.resize(n+1,vector<int>());
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        pushEdge(a,b);
    }
    
    int count = 0;
    
    for(int i=1; i<n+1; i++){
        if(visited.find(i)==visited.end()){
            dfs(i);
            count++;
        }
    }
    cout<<count;
    return 0;
}