// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    int n,q;
    scanf("%d %d",&n,&q);

    int a[n][n];
    int queries[q][4];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    
    for(int i =0;i<q;i++){
        for(int j=0; j<4; j++){
            scanf("%d",&queries[i][j]);
        }
    }
    
    int p=0;
    
    while(p<q){
        int y1= queries[p][0];
        int x1= queries[p][1];
        int y2= queries[p][2];
        int x2= queries[p][3];
        
        
        int sum =0;
        
        for(int i = y1; i<=y2; i++){
            for(int j = x1; j<=x2; j++){
                sum+=a[i-1][j-1];
            }
        }
        
        printf("Sum: %d ",sum);
        p++;
    }
    
    
    return 0;
}