// 2 issues, O(n^2), doesnt use stack or queues, doesnt do mod 10^9 +7
#include <stdio.h>
#include<limits.h> // this is useful in defining int_min


int main() {
    // Write C code here
    int n;
    
    scanf("%d",&n);
    
    int a[n];
    
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    int j=0;
    int sum=0;
    
    while(j<n){
        int min = INT_MAX;

        for(int i= j; i<n; i++){
            
            if(a[i]<min){
                min =a[i];
                sum+=min;
            }
            else{
                sum+=min;
            }
            
        }
        j++;
        
        
    }

    printf("%d",sum);
    return 0;
}