//fucking basic ass two pointer Q

#include <stdio.h>

int main() {
    
    int n;
    
    scanf("%d",&n);
    
    char str[n];
    int spaces[n];
    int j=1,i =0;
    scanf(" %c",&str[0]);
    spaces[0] =0;
    for(i=1; i<n; i++){
        
        scanf("%c",&str[i]);
        
        if(str[i]==' '){
            spaces[j] = i;
            j++;
        }

        
    }
    
    spaces[j] =n-1;
    while(j<n){
        spaces[j++] = -1;
    }
    

    
    i=0;j=1;
    char temp;
    
    int p = spaces[j]-1;
    
    while(i<n){
        
        if(i<p){
            temp =str[i];
            str[i++] = str[p];
            str[p--] =temp;
        }
        
        else{
            if(spaces[j]==-1){
                i=n;
            }
            else{
            i = spaces[j]+1;
            }
            if(spaces[j+1]==-1){
                p=n-1;
                j++;
            }
            else{
                j++;
                p = spaces[j]-1;}
        }
        
        
    }
for(int i=0;i<n;i++){
    printf("%c",str[i]);
}
    return 0;
}