// Online C compiler to run C program online
#include <stdio.h>

int buy_sell(int l, int r, int arr[]){
    //buys on l sells on r, so profit = price on r -price on l
    return arr[r] - arr[l];
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
            max = buy_sell(i, j ,a)>max? buy_sell(i,j,a): max;
        }
    }

    printf("%d",max);

    return 0;
}