//HALF COMPLETE
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
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add a new element to the end of the linked list
void add(struct Node** head, int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node; // If the list is empty, make the new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = new_node; // Add the new node at the end
    }
}

int main() {
    struct Node* head1 = NULL; // Head of the first linked list
    struct Node* head2 = NULL; // Head of the second linked list

    int n, m, val;
    scanf("%d", &n);
    scanf("%d", &m);

    
    // Input values and create the linked list for head1
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        add(&head1, val);
    }

    // Input values and create the linked list for head2
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        add(&head2, val);
    }

     struct Node* first = head1;
     struct Node* second = head2;
     int carry=0;
     int sum =0;

    if(n>=m){    
        while((first->next)!=NULL){
            if(second!=NULL){
                sum = first->data +second->data + carry;
                carry = sum/10;
                first->data = sum%10;
                first = first->next;
                second = second->next;
            }
            else{
                sum = first->data +carry;
                first->data = sum%10;
                carry = sum/10;
                first = first->next;
            }
        }
        
        
        
        if(n==m){
        sum = first->data +second->data +carry;}
        else{
            sum = first->data+carry;
            
        }
        carry = sum/10;
        first->data = sum%10;
        
        
        if(carry){
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = carry;
            new_node->next =NULL;
            first->next = new_node;
        }
      printList(head1);  
    }
    else{
      while((second->next)!=NULL){
            if(first!=NULL){
                sum = second->data +first->data + carry;
                carry = sum/10;
                second->data = sum%10;
                second = second->next;
                first = first->next;
            }
            else{
                sum = second->data +carry;
                second->data = sum%10;
                carry = sum/10;
                second = second->next;
            }
        }
        
        
            sum = second->data+carry;
            
       
        carry = sum/10;
        second->data = sum%10;
        
        
        if(carry){
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = carry;
            new_node->next =NULL;
            second->next = new_node;
        }
      printList(head2);  
    }   
    
    
    
    
    
    return 0;
}
