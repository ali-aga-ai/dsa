//some issue with .8 and 9 input


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int bucket;
    float val;
    struct Node* next;
};

void insertionSort(struct Node* root) {
    int n = 1;
    struct Node* temp = root;
    temp = temp->next;

    // Count the number of elements in the linked list
    while (temp->next != NULL) {
        n++;
        temp = temp->next;
    }

    // Allocate an array to store the values
    float a[n];

    temp = root;
    temp = temp->next;
    int i = 0;

    // Copy values from the linked list to the array
    while (temp->next != NULL) {
        a[i++] = temp->val;
        temp = temp->next;
    }

    temp = root->next;
    // Apply insertion sort on the array
    for (int i = 1; i < n; i++) {
        float key = a[i];
        int j = i - 1;

        // Move elements of a[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = key;
    }

    temp = root;
    temp = temp->next;
    i = 0;

    // Copy values from the sorted array back to the linked list
    while (temp->next != NULL) {
        temp->val = a[i++];
        temp = temp->next;
    }
}

void addBucket(float val, int bucket, struct Node* root) {
    struct Node* temp = root;

    while (temp != NULL && temp->bucket != bucket) {
        temp = temp->next;
    }  // now you point to the bucket

    if (temp != NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->val = val;
        new_node->bucket = bucket;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int main() {
    int n;

    scanf("%d", &n);  // n is size of array and num of buckets

    float a[n];

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->bucket = 0;  // root is bucket 0
    root->val = -1;    // Initialize val to some default value
    root->next = NULL;
    struct Node* temp = root;

    for (int i = 1; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->bucket = i;
        new_node->val = -1;  // Initialize val to some default value
        new_node->next = NULL;
        temp->next = new_node;
        temp = new_node;
    }

    // all buckets have been created

    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
        
        int p = a[i] * (n)/1;
        addBucket(a[i], p, root);
    }
    
    temp = root;

    for (int i = 0; i < n; i++) {
        insertionSort(root);
        temp = temp->next;
    }
    
    

    // Print the sorted values
    temp = root;
    while (temp != NULL) {
        if (temp->val != -1) {
            printf("%.6f ", temp->val);
        }
        temp = temp->next;
    }

    temp = root; 
    
    printf("\n");
    for(int i= 0; i<n && temp!=NULL; i++){
        int count =0;
        temp = temp->next;
        while(temp!=NULL && temp->bucket==i){
            temp = temp->next;
            count++;
        }
        printf("Bucket %d Count %d \n",i,count);
    }


    // Free the allocated memory
    while (root != NULL) {
        struct Node* current = root;
        root = root->next;
        free(current);
    }

    return 0;
}
