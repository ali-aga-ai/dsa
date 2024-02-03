//Grow from the center method
#include <stdio.h>


int grow_from_centre(char a[], int left, int right, int n){
    
    while(left>=0 && right<n && a[left] == a[right]){
        
        left--;
        right++;
        
    }
    right-=1;
    left+=1;
    return right - left+1; // +1 cuz 0 indexed based
}



int main() {
    
    int n;
    
    scanf("%d",&n);
    
    char str[n];
    
    int max =0;
    
    scanf("%s",str);
    
    if(n%2==0){
        for(int i=0 ; i<n ; i++){
            max = grow_from_centre(str,i, i+1,n)>max? grow_from_centre(str,i, i+1,n): max;
        }
    }
    
    
    if(n%2==1){
        for(int i=0 ; i<n ; i++){
            max = grow_from_centre(str,i, i,n)>max? grow_from_centre(str,i, i,n): max;
        }
    }    
    
    printf("%d",max);

    return 0;
}