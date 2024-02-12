// an edge case could be the long int issue
#include <stdio.h>

char *below_twen[20] = {"0", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen","nineteen"};
char *tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


void hundred(int n){
    if(n>20){
        if(n>=100){
            printf("%s hundred ",below_twen[n/100]);
            n%=100;
            if(n!=0){
            if(n>20){
                printf("%s %s ",tens[n/10], below_twen[n%10]);
            }
            else{
                printf("%s ",below_twen[n]);
            }}
            
        }
        else{
            
            printf("%s %s",tens[n/10], below_twen[n%10]);
            
        }
    }
    
    
}




void into_words(int n){
    
    while(n>0){
        
        hundred(n%1000);
        
        n/=1000;
    }
    
    
}


int main() {
    int n;
    scanf("%d",&n);
    into_words(n);
    
    return 0;
}