//this is bad code i wont be using this at all
#include <stdio.h>
#include <stdbool.h>

struct Node{
  
  int val;
  
  struct Node* left;
  struct Node* right;
  struct Node* parent;
  
  bool visited;
};

bool leafNode(struct Node* node){
    if(node->left==NULL && node->right==NULL){
        return true;
    }
}

int max(int x, int y, int z) {
    if (x >= y && x >= z) {
        return x;
    } else if (y >= x && y >= z) {
        return y;
    } else {
        return z;
    }
}

int sum(struct Node* node, int sum){
   int x,y,z;
   x=0;
   y=0;
   z=0;
   
   if(leafNode(node) && !node->visited){
       sum+=node->val;
       return sum;
   }
   
   if(!node->parent->visited){
       x = sum(node->parent,sum);
       node->parent->visited = true;
   }
   if(!node->left->visited){
       y = sum(node->left,sum);
       node->left->visited = true;

   }
   if(!node->right->visited){
       z = sum(node->right,sum);
       node->right->visited = true;
   }
   
   sum+=max(x,y,z);
   
   return sum;
    
}

int main() {
    
    int n;
    
    scanf("%d",&n);
    
    int a[n+1];
    a[0] = -1;
    
    for(int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    
    
    
    
    

    return 0;
}