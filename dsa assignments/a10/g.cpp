// NEED TO OPTIMIZE
#include <iostream>
#include <vector>

using namespace std;//sdt has a keyword called distance hence can create ambiguity

#define MAX 1000


vector<vector<int>> graph;
vector<int> unvisited;
vector<int> visited;
vector<int> previous;
vector<int> sourceDistance;

void sourceDistances(int x, int n){
    
    sourceDistance.resize(n+1,MAX);
    sourceDistance[x] = 0;
    
    previous.resize(n+1);
    visited.resize(n+1);
    unvisited.resize(n+1);
    for(int i= 0; i<n+1; i++){
        unvisited[i] =i;
        previous[i] =0;
    }
}


void dijkstra(int x,int n){//x is source
    
    int c=0;
    for(int i=0; i<n+1; i++){
        if(unvisited[i]!=-1){
            c=1;
        }
    }
    if(!c){return;}
    
    for(int i=1; i<n+1; i++){
        //for unvisited neghbours of x with index i
        if(graph[x][i]!=0 && unvisited[i]==i){
        
            int p = sourceDistance[x]+graph[x][i];
            
            if(p<sourceDistance[i]){
                sourceDistance[i] = p;
                previous[i] = x; //can cause problems here
            }
        }
    }
    
    visited.push_back(x);
    unvisited[x] =-1;
    int min;
    //change this too long
    for(int i=0; i<n+1; i++){
        if(unvisited[i]!=-1){
             min = i; 
            break;
        }
    }
    
    for(int i=0; i<n+1; i++){
        if(unvisited[i]!=-1){
            if(sourceDistance[i]<sourceDistance[min]){
                min = i;
            }
        }
    }
    
    dijkstra(min,n);//issue can be here
    
}


int main() {
    
    int n,m,a,b,c;
    
    cin>>n>>m;

    graph.resize(n+1,vector<int>(n+1,0));

    for(int i=0; i<m; i++){
        cin>>a>>b;
        cin>>c;
        if(graph[a][b]==0)
        graph[a][b] = c;//directed graph
        else{
            if(graph[a][b]>c){
                        graph[a][b] = c;//directed graph

            }
        }
    }

    sourceDistances(1,n);//setting sourceDistances to 0 and infinity

    dijkstra(1,n);

    for(int i=1; i<n+1; i++){
        cout<<sourceDistance[i]<<" ";
    }
    return 0;
}