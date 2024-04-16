// copied approach of findingdiameter of graph...from a find farthest point calll it b, from b find the farthest point from b, call it c. distance between b and c is diameter
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 1000
using namespace std;

vector<vector<int>> graph;
vector<int> distanceVector;
stack<int> toVisit;
vector<int> visited;

void pushEdge(int x, int y){
    graph[x].push_back(y);
    graph[y].push_back(x);
}

void dfs(int x, int dist){
    
    
    for(int neighbour: graph[x]){
        if(find(visited.begin(),visited.end(),neighbour) == visited.end()){
        toVisit.push(neighbour);
        distanceVector[neighbour] = dist+1;}
    }
    visited.push_back(x);

    if(!toVisit.empty()){
        int y = toVisit.top();
        toVisit.pop();
        dfs(y, distanceVector[y]);
    }
    
    
}

int summation(int x){
    int sum =0;
    
    for(int i=1;i<=x; i++){sum+=i;}
    
    return sum;
}
int main() {
    int n,a,b;
    
    cin>>n;
    graph.resize(2*n,vector<int>());
    distanceVector.resize(2*n,MAX);
    
    for(int i=0;i<n;i++){
        cin>>a>>b;
        pushEdge(a,b);
    }
    
    dfs(1,0);
    int sum =0;
    
    
    for(int i=0; i<2*n; i++){
        if(distanceVector[i]!=MAX)
        sum +=summation(distanceVector[i]);
    }
    
    cout<<"ans "<<sum;
    
    return 0;
}