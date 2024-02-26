#include <stdio.h>
#include <stdlib.h>

// Function to maintain min-heap property
void Heapify(int* a, int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int min = i;

    if (left < n && a[left] < a[min]) {
        min = left;
    }

    if (right < n && a[right] < a[min]) {
        min = right;
    }

    if (i != min) {
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        Heapify(a, min, n);
    }
}

void buildMinHeap(int* a, int n) {
    for (int i = n / 2; i >= 1; i--) {  // Start from n/2 to 1
        Heapify(a, i, n);
    }
}

// Heap Sort function
void heapSort(int* a, int n) {
    int p = n;

    while (p > 1) {
        int temp = a[1];
        a[1] = a[p - 1];
        a[p - 1] = temp;

        p--;

        Heapify(a, 1, p);  // Corrected index
    }
}

void add(int* a, int val, int n) {
    if (n == 2) {
        a[1] = val;
    } else {
        a[n - 1] = val;
        int i = n - 1;
        int parent = i / 2;

        while (i > 1 && parent != 0 && a[parent] > a[i]) {
            int temp = a[parent];
            a[parent] = a[i];
            a[i] = temp;

            i = parent;
            parent /= 2;
        }
    }
}

int main() {
    int n=2; //1 indexed array a. we will assign a[n-1] =fdsfds, so a[1] = fdsfds 
    
    int q,val,num;
    
    scanf("%d",&q);
    
    int* a = malloc((q+1)*sizeof(int));

    for(int i = 0;i<q ; i++){
        scanf("%d",&num);
        
        if(num==1){//add element to heap
            
            scanf("%d",&val);
            add(a,val,n++);
            
        }
        //no issues in adding a new element
        
        if(num==2){
            printf("Pre min heap: ");
            for(int i=1;i<n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
            heapSort(a+1,n-1);
            
            printf("Post sort: ");
            for(int i=1;i<n;i++){
                printf("%d ",a[i]);
            }
            buildMinHeap(a+1,n-1);//cuz sorting changes format
            
        }
    }

    return 0;
}