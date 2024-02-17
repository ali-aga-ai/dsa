#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;  // Head of the linked list
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int n, m,val;
    scanf("%d", &n);
    scanf("%d", &m);

    // Input values and create the linked list for head1
    struct Node* temp = NULL;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->next = NULL;

        if (head1 == NULL) {
            head1 = new_node;
            temp = head1;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
    }



    // Input values and create the linked list for head2
    temp = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->next = NULL;

        if (head2 == NULL) {
            head2 = new_node;
            temp = head2;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
    }
    
    
    
    
    
    

    // Merge the two linked lists
    if (head1->data <= head2->data) {
        head = head1;
        temp = head1;
        head1 = head1->next;
} 
    else {
        head = head2;
        temp = head2;
        head2 = head2->next;
    }

int i = 1;


    while (i < n + m) {
        
        if (head1!= NULL && head2!=NULL && head1->data <= head2->data) {
            temp->next = head1;
            temp = head1;
            
            head1 = head1->next;
            
            i++;
        }
    else if (head1!= NULL && head2!=NULL && head1->data > head2->data) {
            temp->next = head2;
            temp = head2;
            
            head2 = head2->next;
            i++;
        }
        
        
    else if (head1== NULL && head2!=NULL) {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
            i++;
        }

    else if (head1!= NULL && head2==NULL ) {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
            i++;
        }        
    }





    // Print the final combined linked list
    printf("Combined Linked List: ");
    printList(head);

    return 0;
}