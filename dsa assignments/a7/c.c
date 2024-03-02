// countSort is generally for distinct elements so repetitive elements can cause issues
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int n;

    scanf("%d",&n);

    int a[n+1];
    a[0]=0;
    
    for(int i=1; i<n+1; i++){
        scanf("%d",&a[i]);
    }
    //a[1] to a[n] contain all elements, a[0] is irrelevant

    int b[n+1];
    int idx[n+1];
    
    
    int c[n+1];

    for(int i=0; i<n+1; i++){
        c[i] = 0;
    }
    for(int i=0; i<n+1; i++){
        b[i] = 0;
    }
    for(int i=1; i<n+1; i++){
        c[a[i]]++;
    }
    
    for(int i=1; i<n+1; i++){
        c[i]+= c[i-1];
    }    
     printf("a: ");
    for(int i=0;i<n+1;i++){
        printf("%d ",a[i]);
    }
        printf("\n");

    //c[i] stores cumulative frequency c[0] indicates cf if we add all existing zeroes
    printf("c: ");
    for(int i=0;i<n+1;i++){
        printf("%d ",c[i]);
    }

    
    printf("\n");
        printf("b: ");
    
    for(int i=1;i<n+1;i++){
        
        if(b[c[a[i]]]==0){
            b[c[a[i]]] = a[i];
            idx[c[a[i]]] =i;
        }
        
        else{
            
            int p=0;
            
            
            while(b[c[a[i]]]!=0){
                
                c[a[i]]--;
                p++;
                
            }
            
            b[c[a[i]]] = a[i];
            idx[c[a[i]]] =i;
            c[a[i]]+=p;
            
            
        }
        }
 
    for(int i=1;i<n+1;i++){
            printf("%d ",b[i]);
    }
    
    printf("\nidx: ");
    
    for(int i=1;i<n+1;i++){
                printf("%d ",idx[i]);
        }
     
    return 0;
}