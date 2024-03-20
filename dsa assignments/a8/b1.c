// bad for large values of k cuz O(nk)
#include <stdio.h>
#include<limits.h> // this is useful in defining int_min


int main() {
    // Write C code here
    int n,k;
    
    scanf("%d",&n);
    scanf("%d",&k);
    
    int a[n];
    
    for(int i =0; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    int j=0; 
    
    while(j+k<=n){
        int max =INT_MIN;

        for(int i=0; i<k; i++){
            if(a[j+i]>max){
                max = a[j+i];
            }
        }
        printf("%d ",max);
        j++;
        
        
    }

    return 0;
}