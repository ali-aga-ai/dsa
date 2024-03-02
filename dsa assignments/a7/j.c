// maximise synergy + dps of max k elements out of n elements and find sum
#include <stdio.h>
#include<stdlib.h>

struct Pair{
    int first;
    int second;
};


void Heapify(struct Pair a[], int i, int n){
    
    int left =2*i + 1;
    int right = 2*i +2;
    
    int max = i;
    
    if(left<n && a[left].first<a[max].first){
        max= left;
    }
    
    if(right<n && a[right].first<a[max].first){
        max= right;
    }    
    
    if(i!=max){
        int temp = a[i].first;
        a[i].first = a[max].first;
        a[max].first = temp;
        
        temp = a[i].second;
        a[i].second = a[max].second;
        a[max].second = temp;
        
        Heapify(a,max,n);
    }
    
}

void buildMaxHeap(struct Pair a[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        Heapify(a, i, n);
    }
}


int main() {
    
    int n,x;

    scanf("%d",&n);
    scanf("%d",&x);

    struct Pair a[n];
    
    
    for(int i=0; i<n; i++){
        scanf("%d",&a[i].first);
       a[i].first-=x;
        a[i].second = i+1;
    }
   buildMaxHeap(a,n);

    int count=0;

    while(a[0].first <0){
        
        count++;
        
        printf("%d ",a[0].second);
        
        int temp = a[0].first;
        a[0].first = a[n-1].first;
        a[n-1].first = temp;
        
        temp = a[0].second;
        a[0].second = a[n-1].second;
        a[n-1].second = temp;
        
        n--;
        
        Heapify(a,0,n);
        
    }  
    
    printf("\n%d",count);
 
 
 
    return 0;
}