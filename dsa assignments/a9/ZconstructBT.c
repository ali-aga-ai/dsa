#include <stdio.h>
#include <stdlib.h>

//goal: scan an array such that 2i and 2i+1 indicate left and right nodes respectively
int n;

struct Node{
    int val;
    
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};


struct Node* constructBT(int* array, int i, struct Node* father){
    //we have array and the index whose value we wanna use
    
    struct Node* root= malloc(sizeof(struct Node));
    if(i<n+1){
        root->val = array[i];
        root->left = constructBT(array,2*i,root);
        root->right = constructBT(array,2*i+1,root);
        root->parent = father;
        return root;
    }
    else{return NULL;}
    
}


int main() {
    
    
    scanf("%d",&n);
    
    int a[n+1];
    
    a[0] =-1;
    
    for(int i=1; i<n+1; i++){
        scanf("%d",&a[i]);
    }
    
    struct Node* root = constructBT(a,1,NULL);
    
    
    return 0;
}