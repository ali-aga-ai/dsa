// maximise synergy + dps of max k elements out of n elements and find sum
#include <stdio.h>
#include<stdlib.h>

void Heapify(int* a, int i, int n){
    
    int left =2*i + 1;
    int right = 2*i +2;
    
    int max = i;
    
    if(left<n && a[left]>a[max]){
        max= left;
    }
    
    if(right<n && a[right]>a[max]){
        max= right;
    }    
    
    if(i!=max){
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        Heapify(a,max,n);
    }
    
}

void buildMaxHeap(int* a, int n) {
    for (int i = n / 2; i >= 0; i--) {
        Heapify(a, i, n);
    }
}


int main() {
    
    int n,k;

    scanf("%d",&n);
    scanf("%d",&k);

    int a[n];
    
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    int synergy;
    
    for(int i=0; i<n; i++){
        scanf("%d",&synergy);
        a[i]+=synergy;
    }
    
    
    buildMaxHeap(a,n);//build a heap out of it. choose top k max elements
    
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    
    int sum1=0;
    int sum2 =0;
     
    while(k>0){
        
        sum1+=a[0];//
        
        if(sum1>sum2){//this is because we want at max k elements, it is poosible that one element is negative and adding it causes issues
            int temp = a[0];
            a[0] = a[n-1];
            a[n-1] = temp;
            n--;
            sum2 = sum1;
            Heapify(a,0,n);
            k--;
        }
        
        else{
            break;
        }
        
        
    }
    
    printf("%d",sum2);
    
    return 0;
}