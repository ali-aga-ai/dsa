// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    int n,k;
    
    scanf("%d",&n);
    scanf("%d",&k);
    
    int a[n];
    
    int count[n+1];
    
    int missing[n];
    
    for(int i=0;i<n;i++){
        missing[i] =-1;
    }    
    count[0]=1;
    for(int i=1;i<n+1;i++){
        count[i] =0;
    }
    
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        count[a[i]]++;
    }
    
    int p=0;
    
    for(int i =1;i<n+1;i++){
        if(count[i]==0)
        {
            missing[p++] = i; 
        }
    }
    
    for(int i=0;i<p;i++){
        for(int j =i+1;j<p;j++){
            if(missing[i]+missing[j]==k){
                printf("yes %d %d",missing[i],missing[j]);
                return 0;
            }
        }
    }
    
    printf("no");
    
    return 0;
}