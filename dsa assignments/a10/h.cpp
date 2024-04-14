// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
stack<int> visit;

void pushEdge(int x, int y, int weight){
    graph[x][y] = weight;//directed graph
}

bool dfs(int i, int initial){//cycle detection via dfs

    visit.push_back(i);
    for(int p=1; p<=n; p++){
        if(graph[i][p]!=0){//if there exists an edge between i and p
            
            if(p==initial){//if the node is the root node
                return true;
            }
            
            if(visited[p]==0){//if p hasnt been visited
                dfs(p,initial);
            }
        }
    }
    visited.push_back(i);
    
    
}

void empty(){
    while(visited){
        visited.pop();//empty visited
    }
}

int main() {
    
    int n,m;
    
    cin<<n<<m;
    
    graph.resize(m,vector<int>(m));
    visited.resize(m);
    
    graph = {{0}};
    
    for(int i=0; i<m; i++){
        
        int x,y,w;
        cin<<x<<y<<w;
        pushEdge(x,y,w);
        
    }
    
    for(int i=1; i<=n; i++){
        dfs(i)//do dfs for each node, add weights and check if cycle or not, if not cycle just return 0
        empty();
    }
    
    return 0;
}