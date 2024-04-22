// find the max number. add it to the  rest. do this recursively... we add max number because
//  at every iteration the number which wass added previously will be added again. and if we add max in 1st 
//  iter it will be added n-1 times


#include <stdio.h>

int main() {
    
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    
    for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - 1 - i; j++) { // Corrected the inner loop termination condition
        if(a[j] < a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }
}

    
    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("Sum: %d",a[i]);
            break;
        }
        int x = a[i];
        for(int j=i+1;j<n;j++){
            a[j]+=a[i];
        }
        
    }

    return 0;
}