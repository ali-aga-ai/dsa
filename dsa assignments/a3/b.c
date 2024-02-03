#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char str[n];
    scanf("%s", str);
    
    int count = 0;
    int start = 0;
    int max = 0;
    
    int charIndex[26];  // Assuming only lowercase English alphabet, initialize to -1
    
    for (int i = 0; i < 26; i++) {
        charIndex[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        if (charIndex[str[i] - 'a'] == -1 || charIndex[str[i] - 'a'] < start) {
            // Character not encountered or encountered after the current sequence
            charIndex[str[i] - 'a'] = i;
            count++;
        } else {
            // Character encountered again, update start position
            start = charIndex[str[i] - 'a'] + 1;
            charIndex[str[i] - 'a'] = i;
            count = i - start + 1;
        }
        
        max = count > max ? count : max;
    }
    
    printf("%d", max);
    
    return 0;
}
