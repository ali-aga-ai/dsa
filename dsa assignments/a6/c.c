#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

// Function to maintain max heap property
void Heapify(int* a, int i, int n) {
    int left = 2 *i + 1;  // Left child index 2i+1 because 0 indexing, if it were 2i and ur first element i=0, left =2i = 0
    int right = 2 * i + 2;  // Right child index
    int max = i;

    // Compare with left child
    if (left < n && a[left] > a[i]) {
        max = left;
    }
    // Compare with right child
    if (right < n && a[right] > a[max]) {
        max = right;
    }

    // Swap if needed and recursively heapify the affected subtree
    if (i != max) {
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        Heapify(a, max, n);  // Recursively heapify the affected subtree
    }
}

// Function to build max heap
void buildMaxHeap(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, i, n);
    }
}

// Heap Sort function
void heapSort(int* a, int n) {
    buildMaxHeap(a, n);

    // Extract elements from the heap one by one, this is the imp part for sorting
    while (n > 1) {
        int temp = a[0];
        a[0] = a[n - 1];
        a[n - 1] = temp;

        n--;

        Heapify(a, 0, n);
    }
}

// Main function
int main() {
    int n;

    scanf("%d", &n);

    int* a = malloc(n*sizeof(int));

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Perform heap sort
    heapSort(a, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    free(a);
    
    return 0;
}
