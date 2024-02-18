//v easy reversing a doiubly linked list

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->prev != NULL) {
            printf(" ");
        }
        current = current->prev;
    }
    printf("\n");
}

// Function to add a new element to the end of the linked list
void add(struct Node** head, int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev =NULL;

    if (*head == NULL) {
        *head = new_node; // If the list is empty, make the new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = new_node; // Add the new node at the end
        new_node->prev = temp;
    }
}

int main() {
    struct Node* head1 = NULL; // Head of the first linked list
    struct Node* head2 = NULL; // head 2 being the last element head

    int n, m, val;
    scanf("%d", &n);
    //scanf("%d", &m);

    
    // Input values and create the linked list for head1
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        add(&head1, val);
    }
    
    head2 = head1;
    
    while(head2->next!=NULL){
        head2 = head2->next;
    }
    
    
    
    printList(head2);
    
    return 0;
}
