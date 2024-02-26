#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc


int* merge(int* a,int n, int* b,int m){
    
    int* arr = malloc((n+m)*sizeof(int));
    
    int i =0;int j=0;int p= 0;
    
    while(i<n && j<m){
        if(a[i]<=b[j]){
            arr[p++] = a[i++];
        }
        else{
            arr[p++]= b[j++];

        }
    }
    
    if(i==n){
        while(p<m+n){
            arr[p++] =b[j++];
           
        }
    }
    else if(j==n){
        while(p<m+n){
            arr[p++] = a[i++];

        }
    }
    
    return arr;
    
}


int* mergeSort(int* beg, int* end, int n) {
    if (n == 1) {
        int* result = malloc(sizeof(int));
        *result = *beg;
        return result;
    }

    int mid = n / 2;

    int* arrayOne = malloc(mid * sizeof(int));
    int* arrayTwo = malloc((n - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        arrayOne[i] = beg[i];
    }

    for (int i = 0; i < n - mid; i++) {
        arrayTwo[i] = beg[mid + i];
    }

    int* sortedArrayOne = mergeSort(arrayOne, arrayOne + mid, mid);
    int* sortedArrayTwo = mergeSort(arrayTwo, arrayTwo + (n - mid), n - mid);

    free(arrayOne);
    free(arrayTwo);

    return merge(sortedArrayOne, mid, sortedArrayTwo, n - mid);
}

int main() {
    int n;

    scanf("%d", &n);

    int* a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int* sortedArray = mergeSort(a, a + n, n);//notice how it isnt a+n-1

    for (int i = 0; i < n; i++) {
        printf("%d \n", sortedArray[i]);  // Add a space after each element
    }

    free(sortedArray);

    return 0;
}|
