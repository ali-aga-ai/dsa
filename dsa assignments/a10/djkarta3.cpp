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
    
    cin>>m;

    graph.resize(2*m,vector<int>(2*m,0));

    for(int i=0; i<m; i++){
        cin>>a>>b;
        cin>>c;
        
        graph[a][b] = c;//directed graph
        graph[b][a] =c;
        
    }
cout<<"bitvh";
    sourceDistances(1,2*m);//setting sourceDistances to 0 and infinity

    dijkstra(1,2*m);

    for(int i=1; i<2*m; i++){
        if(sourceDistance[i]!=MAX)
        cout<<sourceDistance[i]<<" ";
    }
    return 0;
}