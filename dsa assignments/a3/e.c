//merging two sorted arrays
#include <stdio.h>

int main() {
    
    int n,m;
    
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter m: ");
    scanf("%d",&m);
    
    int arr1[n];
    int arr2[m];
    
    printf("enter arr1: ");
    for(int i=0; i<n; i++){
        
        scanf("%d",&arr1[i]);
    }
    printf("enter arr2: ");
    
    for(int i=0; i<m; i++){
        
        scanf("%d",&arr2[i]);

    }    
    
    int ans[n+m];
    
    int i=0;
    int p=0, q=0;
    
    while(i<n+m ){
        
        if(arr1[p]>arr2[q]){
            ans[i] = arr2[q++];
        }
        else if ( arr1[p]<=arr2[q]){
            ans[i] = arr1[p++];
        }
        i++;
        
    }
    printf("Ans: ");
    for(int j= 0; j<n+m ; j++){
        
        printf("%d ",ans[j]);
        
    }
    return 0;
}