//incomplete

#include <stdio.h>

int main() {
    
    int n;
    
    scanf("%d",&n);
    
    char str[n];
    int spaces[n];
    int j=0,i =0;
    scanf(" %c",&str[0]);
    for(i=1; i<n; i++){
        
        scanf("%c",&str[i]);//using space skips whitespace chars including newline
        
        if(str[i]==' '){
            spaces[j] = i;
            j++;
        }

        
    }
    
    spaces[j] =n-1;
    while(j<n){
        spaces[j++] = -1;
    }
    
    
    for(int p=0; p<n; p++){
        printf("%d  ", spaces[p]);
    }
    
    
    i=0,j=0;
    char temp;
    
    while(i<n){
        
        if(i<(spaces[j])/2){
            temp =str[i];
            str[i] = str[spaces[j]-i-1];
            str[spaces[j]-i-1] = temp;
            i++;
        }
        else{
            i = spaces[j]+1;
            j++;
        }
        
        
    }
for(int i=0;i<n;i++){
    printf("%c",str[i]);
}
    return 0;
}