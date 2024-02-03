// Online C compiler to run C program online
#include <stdio.h>

int add(int l, int r, int arr[]){
    
    int sum =0;
    for(int i = l ; i<=r;i++){
        sum+=arr[i];
    }
    return sum;
}

int main() {
    int n;
    scanf("%d",&n);
    int max =0;
    int a[n];
    
    for(int i = 0; i<n;i++){
        scanf("%d",&a[i]);    
    }
    
    for(int i= 0;i<n-1;i++){
        for(int j=i+1; j<n; j++){
            max = add(i, j ,a)>max? add(i,j,a): max;
        }
    }
    // add edge case when all but one number is postiive
    for(int i = 0;i<n;i++){
        max= a[i]>max?a[i]:max;
    }
    printf("%d",max);

    return 0;
}