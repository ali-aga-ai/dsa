// incomplete
#include <stdio.h>
#include<stdlib.h>

struct Pair{
    int first;
    int second;
};


int main() {
    
    int n;

    scanf("%d",&n);

    struct Pair a[n];
    
    
    for(int i=0; i<n; i++){
        scanf("%d",&a[i].first);
    }
    
    for(int i=0; i<n; i++){
        scanf("%d",&a[i].second);
    }

    int b_up[n];
    int b_down[n];
 
    int c_up[n];
    int c_down[n];
    
    for(int i=0; i<n; i++){
        c_up[i] = 0;
        c_down[i] = 0;
    }
    
    for(int i=0; i<n; i++){
        c_up[a[i].first]++;
        c_down[a[i].second]++;
    }
    
    for(int i=0; i<n; i++){
        c_up[i]+= c_up[i-1];
        c_down[i]+=c_down[i-1];
    }    
    
    for(int i=n;i>0;i++){
        b_up
    }
 
 
    return 0;
}