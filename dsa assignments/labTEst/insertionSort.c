// insertion sort is a stable sorting algo with on2
#include <stdio.h>

int main() {
    
    //attempt insert sort
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];//elements associated with a
    
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    for(int i=0; i<n; i++)scanf("%d",&b[i]);
    
    for(int i=1; i <n; i++){
        int j = i;
        while(j>0 && a[j]<a[j-1]){
            int temp = a[j];
            a[j] =a[j-1];
            a[j-1] = temp;
            temp = b[j];
            b[j] = b[j-1];
            b[j-1] =temp;
            j--;
        }
    }
    for(int i=0; i<n; i++)printf("%d ",a[i]);
    printf("\n");
    for(int i=0; i<n; i++)printf("%d ",b[i]);

    return 0;
}