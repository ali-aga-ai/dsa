//incomplete
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph;
unordered_set<int> visited;
unordered_set<int> unvisited;
vector<int> distances;
vector<int> previous;
int n;

int extractMin(){
    int min =0;
    for(int i=0; i<2*n; i++){
        if(distances[i]<distances[min]){
            min = i;
        }
    }
    
    unvisited.erase(min);
    return min;
}

void dijkstara(int x){
    
    distances.resize(2*n);
    
    for(int i=0; i<2*n; i++){
        distances[i] = MAX;//distance at tinfinity
        previous[i] =i;
        unvisited.insert(i);
    }
    distance[x] =0;

    
    while(!unvisited.empty()){
         u = extractMin();
         visited.insert(u);
         
         for(int i=0; i<2*n; i++){
             if(graph[u][i]!=0){
                 
             }
             
         }
    }

}



int main() {
    int a,b,w;
    
    cin>>n;
    
    graph.resize(2*n, vector<int> (2*n,0));
    
    for(int i=0; i<n; i++){
        cin>>a>>b>>w;
        graph[a][b] =w;
        graph[b][a] =w;//undirected graph because road
    }
    
    

    return 0;
}