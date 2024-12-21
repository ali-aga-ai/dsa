///only half working
#include <stdio.h>
#include <math.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);

    int n = log2(r);  
    int maxOnes = 0; // Initialize minZeroes to a value greater than the maximum possible count of zeroes

    for (int j = 0; j <= n; j++) {
        int countOnes = 0; // Initialize count of zeroes for the current bit position
        for (int i = l; i <= r; i++) {
            if ((i & (1 << j))) { // Check if bit at position j is zero
                countOnes++; // Increment count of zeroes
            }
        }
        if (countOnes> maxOnes) { // Update minZeroes if a smaller count of zeroes is found
            maxOnes = countOnes;
        }
    }

    printf("%d\n", maxOnes);
    return 0;
}
