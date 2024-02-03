// Online C compiler to run C program online
#include <stdio.h>

int add(int l, int r, int arr[]){
    
    int sum =0;
    for(int i = l ; i<=r;i++){
        sum+=arr[i-1]; //i-1 because 1 indexed
    }
    return sum;
}

int main() {
    int n,q,l,r;
    scanf("%d %d",&n, &q);
    
    int a[n];
    
    for(int i = 0; i<n;i++){
        scanf("%d",&a[i]);    
    }
    
    for(int i = 0; i<q ; i++){
        scanf("%d %d",&l, &r);
        printf("%d \n", add(l,r,a));
    }
    

    return 0;
}