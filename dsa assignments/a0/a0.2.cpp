// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // we will scan twwo 1000 digit numbers and add them
    
    char str1[1000];
    char str2[1000];
    char sum[1002];
    int len1 =-1,len2=-1;
    int carry =0;
    int sum2;
    
    scanf("%s",str1); //NO NEED FOR &str1
    scanf("%s",str2);
    
    for(int i = 0 ; i< 999 ; i++){
        if(str1[i]!='\0'){len1++;} // DO NOT USE " " FOR CHARS RATHER USE ' '
        else{break;}
    }
    
    for(int i = 0 ; i< 999 ; i++){
        if(str2[i]!='\0'){len2++;}
        else{break;}
    }

    int max = len1<len2? len2:len1;
    
for (int i = max+1; i > 0; i--) {
    int sum2 = 0;

    if (len1 >= 0 && len2 >= 0)
        sum2 = str1[len1--] + str2[len2--] + carry - '0' - '0';
    else if (len1 < 0 && len2 >= 0)
        sum2 = str2[len2--] + carry - '0';
    else if (len1 >= 0 && len2 < 0)
        sum2 = str1[len1--] + carry - '0';

    if (sum2 >= 10) {
        carry = 1;
        sum[i] = sum2 % 10 + '0';
    } else {
        sum[i] = sum2 + '0';
        carry = 0;
    }
}
    
    if(carry == 1){
        sum[0] = '1';
        printf("%c", sum[0]);
    }
    else{
        sum[0]='0';
    }
    for(int i =1 ;i <=max+1;i++){
        printf("%c",sum[i]);
    }

    return 0;
}