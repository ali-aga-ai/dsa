#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

// the partition creates a pivot uske left aur right me makes correct order
int Partition(int* a, int low, int high) {
    int pivot = a[low];
    int leftwall = low;

    for (int i = low + 1; i <= high; i++) {
        if (a[i] <= pivot) {
            // Swap a[i] and a[leftwall + 1]
            int temp = a[i];
            a[i] = a[leftwall + 1];
            a[leftwall + 1] = temp;
            // Move the leftwall to the right
            leftwall++;
        }
    }


    // Swap pivot (a[low]) and the element at leftwall
    int temp = a[low];
    a[low] = a[leftwall];
    a[leftwall] = temp;

    return leftwall;// the last element which was lesser than pivot is now at the beginning and hence leftwall holds pivot and not an element lesser than pivot
}


void QuickSort(int* a,int low,int high){
    if (low < high - 1) { // Ensure there are at least two elements to sort
        int pivot = Partition(a, low, high - 1);
        QuickSort(a, low, pivot);
        QuickSort(a, pivot + 1, high);
    }
}


int main() {
    int n;
    
    scanf("%d",&n);
    
    int* a = malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    QuickSort(a,0,n);
    
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}