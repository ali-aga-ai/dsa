// NEED TO OPTIMIZE
//find() method in vector to find an element
#include <iostream>
#include <vector>
#include <algorithm>

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

void process(int x){
    if(x==1){return;}
    visited.push_back(x);
    process(previous[x]);
    
}

int main() {
    
    int n,a,b,c;
    
    cin>>n;

    graph.resize(2*n+1,vector<int>(2*n+1,0));

    for(int i=0; i<n; i++){
        cin>>a>>b;
        cin>>c;
        graph[a][b] = c;//directed graph
    }

    sourceDistances(1,2*n);//setting sourceDistances to 0 and infinity

    dijkstra(1,2*n);

    visited.clear();
    
    //now we have distance of every node from 1
    int number_of_nodes=0;
    
    for(int i=0; i<2*n; i++){
        if(sourceDistance[i]!=MAX){
            number_of_nodes++;
        }
    }
    int sum =0;
    
    while(visited.size()<number_of_nodes-1){// -1 cuz we wont visit 1
         int max =1;
    
        for(int i=1;i<2*n;i++){
            if( sourceDistance[i]!=MAX && sourceDistance[i]>sourceDistance[max] ) {//not visited node
                if (find(visited.begin(), visited.end(), i) == visited.end()) {
                    max =i;
            }
        }
            
        }
        process(max);
        sum+=sourceDistance[max];
    }
    
    cout<<sum<<" is sum";
    return 0;
}