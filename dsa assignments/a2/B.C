// Online C compiler to run C program online
#include <stdio.h>

int binary_search(int array[], int len){//returns target index
    
    int left =0;
    int right = len-1;
    
    while(left<=right){
        int mid = left + (right - left) / 2;
        
        if(array[mid]>array[mid-1] && array[mid]>array[mid+1]){
            printf("hello\n");
            return mid+1; //mid +1 cuz 1 indexed
            
        }
        else if(array[mid]<array[mid-1]){
            right = mid;
            printf("haa\n");
        }
        else if(array[mid]<array[mid+1] ){
            left = mid;
            printf("ehllo\n");
        }
        
}
return -1;}



int main() {
    
    int n;
    
    printf("enter the integers: ");
    scanf("%d",&n);
    
    int arr[n];
    
    printf("enter array: ");
    for(int i =  0 ; i< n ;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n %d", binary_search(arr,n));
    

    return 0;
}