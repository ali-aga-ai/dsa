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

    int idx[n+1];// contains idx
    
    
    int c[n+1];//c initially contains num frequency, then it contains cf

    for(int i=0; i<n+1; i++){
        c[i] = 0;
    }
    for(int i=0; i<n+1; i++){
        b[i] = -1;
    }
    for(int i=1; i<n+1; i++){
        c[a[i]]++;
    }
    
    for(int i=1; i<n+1; i++){
        c[i]+= c[i-1];
    }    
    //c now has cf
    printf("\n");

    int i=1;
    while(i<n+1){
        int p=0;
        
        while((a[i]==0 && c[a[i]]>1) || c[a[i]]>c[a[i]-1]+1 && b[c[a[i]]]==-1){
            c[a[i]]--;
            p++;
        }
        if(b[c[a[i]]]==-1){
            b[c[a[i]]] = a[i];
            idx[c[a[i]]] = i;
            c[a[i]]+=p;
        }
        else{
            
            while(b[c[a[i]]]!=-1){
                c[a[i]]++;
                p--;
            }
            
            b[c[a[i]]] = a[i];
            idx[c[a[i]]] = i;
            c[a[i]]+=p;
        }
        
        i++;
            
    }
    
    for(int i=1;i<n+1;i++){
            printf("%d ",b[i]);
    }
    
    printf("\n");
    
    for(int i=1;i<n+1;i++){
                printf("%d ",idx[i]);
        }
     
    return 0;
}