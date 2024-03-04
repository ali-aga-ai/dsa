//copied

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float val;
    struct Node* next;
};

void insertionSort(struct Node** bucket, int n) {
    if (*bucket == NULL || (*bucket)->next == NULL) {
        return;  // If empty bucket or only one element, return
    }

    float a[n];
    struct Node* current = *bucket;

    // Store values in array
    for (int i = 0; i < n; i++) {
        a[i] = current->val;
        current = current->next;
    }

    // Perform Insertion Sort on array
    for (int i = 1; i < n; i++) {
        float key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    current = *bucket;

    // Update linked list with sorted values
    for (int i = 0; i < n; i++) {
        current->val = a[i];
        current = current->next;
    }
}

void bucketSort(float arr[], int n) {
    struct Node* buckets[n];
    int count[n];
    
    //all buckets are independant entities and not connected together
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
        count[i] = 0;
    }//creating n buckets 0...n-1 and setting their count to 0, a bucket is a singly linked list

    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);//same as arr[i]*n/1
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = arr[i];
        newNode->next = buckets[index];//the first num in the bucket points to null, but the second one points to the one which was inserted before it
        buckets[index] = newNode;
        count[index]++;
    }

    for (int i = 0; i < n; i++) {
        insertionSort(&buckets[i],count[i]);
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            printf("%.6f ", current->val);
            current = current->next;
        }
    }

    printf("\n");

    // Print the number of elements in each bucket
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    return 0;
}
