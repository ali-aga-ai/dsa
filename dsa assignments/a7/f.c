//INCOMPLETE
#include <stdio.h>

struct Pair{
    int count;
    int idx;
};


void countSort(struct Pair a, int n ){
    
    
    
    
}

int main() {
    
    int n;
    
    scanf("%d",&n);
    
    struct Pair a[n+1];
    
    for(int i=0; i<n+1; i++){
        a[i].count=0;
        a[i].idx = -1;
    }
    
    int val;
    
    for(int i=0; i<n; i++){
        scanf("%d",&val);
        
        a[val].count++; //count of an element
        
        if(a[val].idx==-1){
            a[val].idx =i; //first occurence of element
        }
    }
    
    
    countSort(a,n+1);
    return 0;
}