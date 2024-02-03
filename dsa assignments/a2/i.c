// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n ;
    
    scanf("%d",&n);
    
    int a[n];
    
    for(int i=0 ; i<n ;i++){
        scanf("%d",&a[i]);
    }
    
    int profit =0;
    
    if(a[0]<a[1]){
        profit-=a[0]; //local minima
    }
    for(int i =1;i<n-1;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            profit+=a[i]; //selling at peak/maxima
        }
        else if(a[i]<a[i-1] && a[i] <a[i+1]){
            profit-=a[i]; //buying at minima
        }
    }
    if(a[n-1]>a[n-2]){
        profit+=a[n-1]; //local maxima
    }
    printf("%d",profit);

    return 0;
}