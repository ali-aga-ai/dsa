// Online C compiler to run C program online
#include <stdio.h>
#include<stdbool.h>

bool binary_search(int array[], int target, int len){//returns target index
    
    int left =0;
    int right = len-1;
    
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(array[mid] ==target){
            return true;}
        else if(array[mid]>target){
            right = mid-1;
        }
        else if(array[mid]<target){
            left = mid+1;
        }
        
}
return false;}



int main() {
    
    int n,h;
    
    printf("enter the integers: ");
    scanf("%d %d",&n,&h);
    
    int n_sq = n*n;
    int arr[n_sq];
    
    printf("enter array: ");
    for(int i =  0 ; i< n_sq ;i++){
        scanf("%d",&arr[i]);
    }
    if(binary_search(arr,h,n_sq)){
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}