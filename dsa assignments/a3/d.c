//double pointer
#include <stdio.h>
#include<stdbool.h>

bool isLowerCaseVowel(char c) {
    // Check if the character is a lowercase vowel (a, e, i, o, u)
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    
    int n;
    
    scanf("%d",&n);
    
    char str[n+1];
    
    scanf(" %[^\n]", str); // scan string till u find the first \n, not till u encounter first whitespace
    
    int left=0,right=n-1;
    

    while (left < right) {
        if (!isLowerCaseVowel(str[left])) {
            left++;
        }

        if (!isLowerCaseVowel(str[right])) {
            right--;
        }

        if (isLowerCaseVowel(str[left]) && isLowerCaseVowel(str[right])) {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            right--;
            left++;
        }
    }

    printf("%s",str);
    
    return 0;
}