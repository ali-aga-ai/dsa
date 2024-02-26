//not fluent/ half copied
//find time complexity of this

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int max;

int Partition(int* a, int low, int high) {
    int leftwall = low + 1;
    int pivot = low;

    for (int i = low + 1; i <= high; i++) {
        if (a[i] <= a[pivot]) {
            int temp = a[i];
            a[i] = a[leftwall];
            a[leftwall] = temp;
            leftwall++;
        }
    }

    pivot = leftwall - 1;
    int temp = a[low];
    a[low] = a[pivot];
    a[pivot] = temp;

    return pivot;
}

int* merge(int* a, int n, int* b, int m) {
    int* arr = malloc((n + m) * sizeof(int));

    int i = 0, j = 0, p = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            arr[p++] = a[i++];
        } else {
            arr[p++] = b[j++];
        }
    }

    while (i < n) {
        arr[p++] = a[i++];
    }

    while (j < m) {
        arr[p++] = b[j++];
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

void quickSort(int* a, int low, int high, int left) {
    
        if (left <= 0) {
            int* merged = mergeSort(a + low, a + high, high - low + 1);
            for (int i = 0; i < high - low + 1; i++) {
                a[low + i] = merged[i];//LOW+I IS IMP
        }
        free(merged);    
     
 } 
        else {
        if (low < high) {
            int pivot = Partition(a, low, high);
            quickSort(a, low, pivot, left - 1);
            quickSort(a, pivot + 1, high, left - 1);
        }
    }
}





int main() {

    int n;
    
    scanf("%d",&n);
    
    int* a = malloc(n*sizeof(int));
    
    for(int i= 0; i<n ;i++){
        scanf("%d",&a[i]);
    }
    max = 2*log2(n);
    
    quickSort(a,0, n-1,max);
    
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}