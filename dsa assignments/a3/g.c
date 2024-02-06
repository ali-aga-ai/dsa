// sum from left and right
#include <stdio.h>

int main() {
    int n;
    
    scanf("%d",&n);
    
    int a[n];
    
    for(int i=0;i<n;i++){
        
        scanf("%d",&a[i]);    
        
    }
    
    int left =1, right= n-2;
    int sum1=a[0],sum2=a[n-1];
    int ans =0;
    
    for(int j=0; j<n; j++){
        
        if(sum1 > sum2 ){
            sum2+=a[right];
            right--;
        }
        else if(sum1 < sum2 ){
            sum1+=a[left];
            left++;
        }
        
        else if(sum1 == sum2){
            ans =sum1; //storing values every time equal
            if(left!=right){
                sum1+=a[left];
                left++;
            }
        }
        
        if(left ==right){break;}
        
        
    }
    
    printf("%d",ans);

    return 0;
}