// works for the mosgt part with 2i and 2i+1 as left and right vchildren
#include <stdio.h>

int main() {
    
    int n,a,b;
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    
    int a_idx,b_idx;
    //idx where a and b are found
    
    int tree[n+1];
    tree[0] =-1;//1-indexed
    
    for(int i=1; i<n+1; i++){
        
        scanf("%d",&tree[i]);
        
        if(tree[i] == a){
            a_idx =i;
        }
        else if(tree[i] == b){
            b_idx = i;
        }
        
    }
    
    int a_parents[n+1];
    for(int i=0; i<n+1; i++){
        a_parents[i] = -1;
    }
    
    int p =0;
    while(a_idx!=0){
        a_idx/=2;
        a_parents[p++] = tree[a_idx];
    }
    
    p=0;
    
    while(b_idx!=0 && a_parents[p]!=-1 ){
        
        b_idx/=2;
        if(tree[b_idx]==a_parents[p++]){
            printf("%d ",tree[b_idx]);
            return 0;
        }
        
    }
    printf("-1");
    
    return 0;
}