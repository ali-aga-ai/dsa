// there is no concept of indices in unordere3d set
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> temp;
vector<int> visited;
queue<int> toVisit; 
int n;

void pushEdge(int x, int y){
    graph[x].push_back(y);
    graph[y].push_back(x);
}

// an elemenr being 'white' is the same as bfs not being done on it
int bfs(int x, int count){
    count++;
    visited[x] = 1;
    
    int p =0;
    
    while(p<graph[x].size()){

        if(visited[graph[x][p]]!=1){
            int element = graph[x][p];
            toVisit.push(element);
        }
        p++;
    }
    
    if(!toVisit.empty()){
        int next = toVisit.front();
        toVisit.pop();
        count = bfs(next,count);
    }
    
    return count;
}

void reEstablish() {
    temp = graph;
    visited.assign(n + 1, 0);
    // Clear toVisit
    while (!toVisit.empty()) {
        toVisit.pop();
    }
}

void clear(int x){
    for(int i=0; i<n+1; i++){
        int p=0;
        while(p<graph[i].size()){
            if(graph[i][p] == x){
                    graph[x].erase(graph[x].begin() + p);
                    break;
            }
            p++;
        }
    }
}

bool useAsRoot(int x){
    int c=0;
    clear(x);
    int num;
    
    for(int i=1; i<n+1; i++){
        if(i!=x &&visited[i]!=1){
 
            num = bfs(i,0);//where x is num of elements in bfs search
            if(num>n/2){
                c=1;
                break;
            }
        }
    }

    reEstablish();
    
    if(c!=1){
        return true;
    }
    else{return false;}
}


int main() {

    int a,b;
    
    cin>>n;
    
    graph.resize(n+1, vector<int>());   

    for(int i=1; i<n; i++){
        cin>>a>>b;
        pushEdge(a,b);
    }


    reEstablish();

    for(int i=1; i<=n; i++){
        if(useAsRoot(i)){
            cout<<"Ans: "<<i<<endl;
            break;
        }
    }

    return 0;
}