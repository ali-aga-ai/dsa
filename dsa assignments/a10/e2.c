#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<unordered_set<int>> graph;
unordered_set<int> visited;

void pushEdge(int x, int y) {
    graph[x].insert(y);
}

void remove(int independent){// remove element from all other rows
    for(int i=1; i<n+1; i++){
        if(graph[i].find(independent)!= graph[i].end()){
            graph[i].erase(independent);
        }
    }
}

bool topo(int count) {
    if(count==n){return true;}//this means that all nodes have been visited so done
    
    int independent = -1;//the element which depends on no other element is calle dindependant
    for (int i = 1; i <= n; i++) {
        if (graph[i].empty() && visited.find(i)==visited.end()) {//an element is set indep only if it is not dep on others(empty graph) or it isnt visited already
            independent = i;
        }
    }
    if(independent==-1) return false;//if no independant element

    
        remove(independent);
        visited.insert(independent);
        count++;
        topo(count);
        
    return true;
    
    
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1, unordered_set<int>());
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        pushEdge(a, b); // b depends on a
    }
    if (!topo(0)) {
        cout << "IMPOSSIBLE";
    }
    else{
        for(int element: visited){cout<<element<<" ";}
    }
    return 0;
}
