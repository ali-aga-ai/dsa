
#include <stdio.h>

int a, b, A, B, C, D;

int f(double x) {
    return (A * x * x * x) + (B * x * x) + (C * x) + D;
}

int main() {
    // Input values for range (a, b) and coefficients (A, B, C, D)
    scanf("%d %d %d %d %d %d", &a, &b, &A, &B, &C, &D);

    int left = a;
    int right = b;
    int mid = left + (right - left) / 2; // Initialize mid-point
    int c = 0; // Flag for maximum found

    // Binary search to find local maximum
    while (left <= right) {
        mid = left + (right - left) / 2; // Update mid-point
        
        // Check if mid is a local maximum
        if (f(mid) >= f(mid + 1) && f(mid) >= f(mid - 1)) {
            c = 1; // Set flag for maximum found
            break; // Exit loop if maximum found
        } else if (f(mid) > f(mid + 1) && f(mid) < f(mid - 1)) {
            right = mid - 1; // Adjust right boundary
        } else if (f(mid) < f(mid + 1) && f(mid) > f(mid - 1)) {
            left = mid + 1; // Adjust left boundary
        }
    }
    
    // If no maximum found, print message and exit
    if (!c) {
        printf("No maximum found\n");
        return 0;
    }
    
    // Print current maximum
    printf("Current max: %d\n", mid);
    
    float newMid = mid; // Convert mid to float for refining
    float precision = 0.1; // Initialize precision
    
    // Refine maximum with increasing precision
    for (int i = 0; i < 6; i++) {
        while (f(newMid) <= f(newMid + precision)) {
            newMid += precision; // Increase newMid until maximum found
        }
        precision /= 10; // Decrease precision for next iteration
    }
    
    // Print refined maximum
    printf("Refined max: %.6f\n", newMid);

    return 0;
}
