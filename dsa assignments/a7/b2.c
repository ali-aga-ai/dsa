//copied

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float val;
    struct Node* next;
};

void insertionSort(struct Node** bucket) {
    if (*bucket == NULL || (*bucket)->next == NULL) {
        return;
    }

    struct Node* sorted = NULL;
    struct Node* current = *bucket;

    while (current != NULL) {
        struct Node* next = current->next;

        if (sorted == NULL || sorted->val >= current->val) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->val < current->val) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *bucket = sorted;
}

void bucketSort(float arr[], int n) {
    struct Node* buckets[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = arr[i];
        newNode->next = buckets[index];
        buckets[index] = newNode;
        count[index]++;
    }

    for (int i = 0; i < n; i++) {
        insertionSort(&buckets[i]);
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
