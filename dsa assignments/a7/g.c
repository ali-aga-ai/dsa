// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int* sorted(int* a, int n) {
    // Create a new array to store the sorted elements
    int* sortedArray = (int*)malloc(n * sizeof(int));
    
    // Copy the original array to the new array
    for (int i = 0; i < n; i++) {
        sortedArray[i] = a[i];
    }

    // Bubble sort on the new array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (sortedArray[j] > sortedArray[j + 1]) {
                int temp = sortedArray[j];
                sortedArray[j] = sortedArray[j + 1];
                sortedArray[j + 1] = temp;
            }
        }
    }

    return sortedArray;
}

int main() {
    
    int n,k,x;
    
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&x);
    
    int a[n];
    int b[n]; //b has a-x mod
    int* c = malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }    
    
    for(int i=0; i<n; i++){
        b[i] = a[i]-x;
        
        if(b[i]<0){
            b[i]*=-1;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ",b[i]);
    }    
    printf("\n");
    c = sorted(b,n);
      for(int i=0; i<n; i++){
        printf("%d ",c[i]);
    }  printf("\n");
    int p=0;
    
    for(int i=0;i<n;i++){
        if(p==k){
            break;
        }
        for(int j=0;j<n;j++){
            
           if(c[i]==b[j]){
               printf("%d ",a[j]);
               p++;
               break;
           } 
           
        }
    }
    
    return 0;
}