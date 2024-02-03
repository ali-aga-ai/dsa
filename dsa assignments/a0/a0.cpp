#include <stdio.h>

int main() {
    char str1[1000];
    char str2[1000];
    char ans[1001];
    int i, j,len1,len2;
    int carry = 0;

    printf("hello");

    for (i = 999; i >= 0; i--) {
        scanf("%c", &str1[i]);
        if (str1[i] == '\n') {
            len1 = i;
            while (i >= 0) {
                str1[i] = '0';
                i--;
            }
        }
    }
    int k =0;
    while(999-k>len1+k){
        char temp = str1[999-k];
        str1[999-k] = str1[len1+k];
        str1[len1+k] = temp;
        k++;
    }

    for (j = 999; j >= 0; j--) {
        scanf("%c", &str2[j]);
        if (str2[j] == '\n') {
            len2 =j;
            while (j >= 0) {
                str2[j] = '0';
                j--;
            }
        }
    }
    
    k =0;
    while(999-k>len2+k){
        char temp = str2[999-k];
        str2[999-k] = str2[len2+k];
        str2[len2+k] = temp;
        k++;
    }

    for (int k = 1000; k >= 0; k--) {
        int num1 = str1[k] - '0';
        int num2 = str2[k] - '0';

        int sum = num1 + num2 + carry;
        ans[k + 1] = (sum % 10) + '0'; // Store the result as a character

        carry = sum / 10; // Update the carry for the next iteration
    }

    if (carry == 1) {
        ans[0] = '1';
    } else {
        ans[0] = '0';
    }

    i = 0;
    while (ans[i] == '0') {
        i++;
    }

    for (int k = i; k < 1000; k++) { // Corrected loop condition
        printf("%c", ans[k]);
    }
    printf("\n"); // Add a newline character to separate the output

    return 0;
}