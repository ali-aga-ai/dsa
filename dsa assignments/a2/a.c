// Online C compiler to run C program online
#include <stdio.h>

int binary_search(int array[], int target, int len){//returns target index
    
    int left =0;
    int right = len-1;
    
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(array[mid] ==target){
            return mid;}
        else if(array[mid]>target){
            right = mid-1;
        }
        else if(array[mid]<target){
            left = mid+1;
        }
        
}
return -1;}



int main() {
    
    int n,h;
    
    printf("enter the integers: ");
    scanf("%d %d",&n,&h);
    
    int arr[n];
    
    printf("enter array: ");
    for(int i =  0 ; i< n ;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n %d", binary_search(arr,h,n));
    

    return 0;
}