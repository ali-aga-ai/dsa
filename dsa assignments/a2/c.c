// CHECK THIS FOR MORE TESTCASES AND ANNOTATE

#include <stdio.h>

int main() {
    
    
    int n;
    
    scanf("%d",&n);
    int a[n];
    
    int left =0;
    int right = n-1;
    int mid;
    
    for(int i=0;i<n-1;i++){
        scanf("%d", &a[i]);
        if(a[i]<a[i-1]){
            mid =i-1;
            
        }
        // printf("%d",i);
    }
    
    // printf("%d \n",mid);
    if(a[mid] ==7){
        printf("%d",mid);
        return 0;
    }
    else if(a[mid]>7 && a[0]<7){
        right = mid;
    }
    else if(a[mid]>7 && a[0]>7){
        right =mid+1;
    }
    else if(a[mid]<7){
        right =mid+1;
    }
    
    while(left<=right){
            int mid = left + (right - left) / 2;
            if(a[mid] ==7){
                printf("%d",mid);
                return 0;}
            else if(a[mid]>7){
                right = mid-1;
            }
            else if(a[mid]<7){
                left = mid+1;
            }
            
    }
    printf("%d",-1);


    return 0;
}