//two ways..create an array find kth largest elemnt
// or create a bst, from max find the predecessor k-1 times
// DOESNT WORK
#include <stdio.h>
#include <stdlib.h>

int n;

struct Node {
    int val;
    struct Node *right;
    struct Node *left;
    struct Node *parent;
};

struct Node* createNode(int* arr, int i){
    if(i<n+1){
    struct Node* newNode = malloc(sizeof(struct Node));
    
    if(i==1) newNode->parent =NULL;
    
    if(arr[i]!= -1){
    newNode->val = arr[i];
    newNode->left = createNode(arr,2*i);
    if(newNode->left!=NULL)
    newNode->left->parent = newNode;
    
    newNode->right = createNode(arr,2*i+1);
    
    
    if(newNode->right!=NULL)
    newNode->right->parent = newNode;
    }
    else {newNode =NULL;}
    
    return newNode;
    }
    
    else{
        return NULL;
        }
}

struct Node* findMax(struct Node* root){
    struct Node *temp = root;
    while(temp->right!=NULL)temp = temp->right;
    
    return temp;
}

struct Node* predecessor(struct Node* temp) {
    if (temp->left != NULL) {
        temp = temp->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    } else {
        while (temp != NULL && temp->parent->right != temp) {
            temp = temp->parent;
        }
        return temp->parent;
    }
}


int main() {
    
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    int a[n+1];
    
    for(int i=1; i<n+1; i++){
        scanf("%d",&a[i]);
    }
    
    struct Node* root = malloc(sizeof(struct Node));

    root = createNode(a,1);
    
    struct Node *temp = findMax(root);
    
      for(int i=0; i<k-1; i++){
          temp = predecessor(temp);
          printf("Pred %d\n",temp->val);
      }
    
     printf("Value %d\n",temp->val);
     

    return 0;
}