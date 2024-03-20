//my logic with gpt help to append zeros
//mem is generally dest src size
//
#include <stdio.h>
#include <string.h>

//add append zeroes part as well 
void radixSort(int n, char a[n][11], int k) {
    // k implies the k'th column sort

    int c[16];

    for (int i = 0; i < 16; i++) {
        c[i] = 0;
    }

    char b[n][11];

    for (int i = 0; i < n; i++) {
        char current_char = a[i][k];
        if (current_char >= 'A' && current_char <= 'F') {
            c[current_char - 'A' + 10]++;  // Count uppercase hex characters (A-F)
        } else {
            c[current_char - '0']++;  // Count numeric hex characters (0-9)
        }
    } // count of hex add one

    for (int i = 1; i < 16; i++) {
        c[i] = c[i] + c[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        char current_char = a[i][k];
        int index = (current_char >= 'A') ? (current_char - 'A' + 10) : (current_char - '0');
        c[index]--;
        memcpy(b[c[index]], a[i], 11);//this is the countSort part
    }

    for (int i = 0; i < n; i++) {
        memcpy(a[i], b[i], 11);
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    scanf("%d", &k); // k is the number of columns to filter through

    char a[n][11];  // Assuming a buffer of size 11 to accommodate 10 characters and the null terminator

    for (int i = 0; i < n; i++) {
    scanf("%10s", a[i]);  // Ensure that at most 10 characters are read
    int len = strlen(a[i]);

    if (len < 10) {
        // If the length is less than 10, pad with zeroes at the beginning
        memmove(a[i] + 10 - len, a[i], len + 1);  // +1 to include the null terminator
        //memmove(void* dest, const void* src, size_t n);
        memset(a[i], '0', 10 - len);// memset(void* ptr, int value, size_t num);
    }
}


    int p = 9;

    while (k > 0) {
        radixSort(n, a, p);
        p--;
        k--;
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}
