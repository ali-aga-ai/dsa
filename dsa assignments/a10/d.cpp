#include <iostream>
#include <vector>

using namespace std;

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
    for(int i=0; i<n+1; i++){//if any node is waiting to be visited
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
    
    int n,m,a,b,c;// n is v m is e 
    int s,d;
    
    cin>>n>>m>>s>>d;

    graph.resize(n+1,vector<int>(n+1,0));

    for(int i=0; i<m; i++){
        cin>>a>>b;
        
        graph[a][b] = 1;
        graph[b][a] =1;
        
    }
    sourceDistances(s,n);//setting sourceDistances to 0 and infinity    
    dijkstra(1,n);

    cout<<d<<" ";
    while(d!=s){
        cout<<previous[d]<<" ";
        d= previous[d];
    }
    return 0;
}