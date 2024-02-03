// this is the sliding window technique
#include <stdio.h>

int main() {
    
    int n,k,x;
    printf("Enter n: ");
    scanf("%d",&n);
        printf("Enter k: ");

    scanf("%d",&k);
        printf("Enter x: ");

    scanf("%d",&x);
    
    int a[n];
    
    printf("enter array");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    // now comes sliding window, analysing sum of every group of k elements
    int sum=0;
    int count =0;
    for(int i = 0; i <k; i++){
        
        sum+=a[i];
        
    }
    
    if(sum>=x){
        count++;
    }
    
    for(int i = k; i<n;i++){
        
        sum = sum -a[i-k]+ a[i]; //removing first element adding a new element which would be the last element
        
        if(sum>=x){count++;}
    }
    
    printf("%d",count);
    
    return 0;
}