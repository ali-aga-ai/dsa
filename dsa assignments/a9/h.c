//need to make more readable
// Online C compiler to run C program online
#include <stdio.h>

int main() {

    int n;
    
    scanf("%d",&n);
    
    int a[n];
    
    for(int i=1; i<n+1; i++)
    {
        scanf("%d",&a[i]);
        
    }

    int i=1;
    
    int sum =0;
    
    int p=2;
    int count =0;
    
    while(i<n+1){
        
        while(i<p){
            if(i<n+1 && a[i]!=-1){
                sum+=count;

            }
            i++;
        }
        p*=2;
        count++;
    }
    
    printf("%d ",sum);
    return 0;
}