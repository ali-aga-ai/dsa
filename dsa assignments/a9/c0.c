// Online C compiler to run C program online
#include <stdio.h>
#include<stdbool.h>

bool leafNode(int* arr, int i){
    if(arr[2*i] || arr[2*i+1]){
        if(arr[2*i]!=-1){
            return false;
        }
        if(arr[2*i+1] !=-1){
            return false;
        }
    }
    else{
        return true;
    }
}


void remove(int* arr, int k){
    //k index is to be deleted
    
    if(arr[k]){
        arr[k] =-1;
        remove(arr, 2*k+1);
        remove(arr, 2*k);
    }
    
}

int height(int* arr, int i){
    
    if(arr[i] == -1){
        return 0;
    }
    
    else if(leafNode(arr,i)){
        return 1;
    }
    
    else{
        int x=0;
        int y=0;
        
        if(arr[2*i]){
            x = height(arr, 2*i);
        }
        if(arr[2*i+1]){
            y = height(arr, 2*i+1);
        }  
        
        return max(x,y)+1;
    }
    
}

int main() {
    
    int n,k,j;
    int a[n+1];
    
    scanf("%d",&n);
    scanf("%d",&k);
    
    a[0] =-1;//root is a[1]
    for(int i=1; i<n+1; i++){
        scanf("%d",&a[i]);
        if(a[i]==k){
            j=i;
        }
    }
    
    
    remove(a, j);
    
    height(a,1);
    
    return 0;
}