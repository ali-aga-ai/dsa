// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>

using namespace std;

int m,n;
vector<vector<int>> a;

void eat(int i, int j){
    if(a[i][j]){
        
        a[i][j] =0;
    
        if(i<m-1){
            eat(i+1,j);
        }
        if(i>0){
            eat(i-1,j);
        }
        if(j<n-1){
            eat(i,j+1);
        }
        if(j>0){
            eat(i,j-1);
        }
        
    }
}

int main() {

    cin>>m>>n;
    
    a.resize(m,vector<int>(n));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    
    int count=0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]==1){
                eat(i,j);
                count++;
            }
        }
    }
    
    cout<<"Count: "<<count;
    

    return 0;
}