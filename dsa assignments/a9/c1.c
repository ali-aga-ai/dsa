// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int n;

struct Node {
    int val;
    struct Node *right;
    struct Node *left;
};

struct Node* createNode(int* arr, int i){
    if(i<n+1){
    struct Node* newNode = malloc(sizeof(struct Node));
    if(arr[i]!= -1){
    newNode->val = arr[i];
    newNode->left = createNode(arr,2*i);
    newNode->right = createNode(arr,2*i+1);}
    else {newNode =NULL;}
    
    return newNode;
    }
    else{return NULL;}
}

void removeChild(struct Node* root, int val){
    if(root!=NULL){
    if(root->left->val == val){
        root->left = NULL;
    }
    else if(root->right->val == val){
        root->right =NULL;
    }
    else{
        removeChild(root->left,val);
        removeChild(root->right,val);
    }
    }
}

int height(struct Node* root){
    if(root == NULL) return 0;
    
    int count = height(root->left)>height(root->right)? height(root->left) +1 :height(root->right) +1;
    return count;
    
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
    
    removeChild(root,k);
    
    printf("%d",height(root));

    return 0;
}