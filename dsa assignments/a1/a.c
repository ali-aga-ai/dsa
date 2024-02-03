#include <stdio.h>

char str1[1000];
char str2[1000];


int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int mult(char a, char b) {
    return (a - '0') * (b - '0');
}

int main() {
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = stringLength(str1);
    int len2 = stringLength(str2);

    int ans[2000] = {0};

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = mult(str1[i], str2[j]);
            int sum = ans[i + j + 1] + product;

            ans[i + j + 1] = sum % 10;
            ans[i + j] += sum / 10;
        }
    }

    int start = 0;
    while (start < len1 + len2 - 1 && ans[start] == 0) {
        start++;
    }

    for (int i = start; i < len1 + len2; i++) {
        printf("%d", ans[i]);
    }

    printf("\n");
    return 0;
}
