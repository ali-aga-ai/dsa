// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<int> completed;//black
unordered_set<int> onTrial;//grey
vector<vector<int>> graph;

bool check(int x){
    
    onTrial.insert(x);
    
    if (graph[x].size()==0){
        onTrial.erase(x);
        completed.insert(x);
        return true;
    }
    
    else{
        for(int child: graph[x]){
            if(onTrial.find(child)!=onTrial.end()){
                return false;
            }
            else if(!check(child)){
                return false;
            }
        }
    }
    //if u dont find a cycle in x's children
    onTrial.erase(x);
    completed.insert(x);
    return true;
}

void pushEdge(int x,int y){
    graph[x].push_back(y);//x depends on y
}
int main() {
    
    int n,m;
    
    cin>>n>>m;
    
    int a,b;
    
    graph.resize(n+1,vector<int>());
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        pushEdge(a,b);//b depends on a
    }
    
    for(int i=1; i<=n; i++){
        if(!completed.count(i)){ // Check if node is already completed
            if(!check(i)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
        
    for(int node : completed) {
        cout << node << " ";
    }
    return 0;
}