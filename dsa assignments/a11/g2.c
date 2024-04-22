#include <stdio.h>

float a, b, A, B, C, D;

double f(double x) {
    return (A * x * x * x) + (B * x * x) + (C * x) + D;
}

int main() {
    // Input values for range (a, b) and coefficients (A, B, C, D)
    scanf("%f %f %f %f %f %f", &a, &b, &A, &B, &C, &D);

    float left = a;
    float right = b;
    float mid = left + (right - left) / 2; // Initialize mid-point
    float precision = 0.000001;
    int p = 0;
    // Binary search to find local maximum
    while (p<10000) {
        mid = left + (right - left) / 2; // Update mid-point
        
        // Check if mid is a local maximum
        if (f(mid) > f(mid + precision) && f(mid) > f(mid - precision)) {
            break; // Exit loop if maximum found
        } else if (f(mid) > f(mid + precision) && f(mid) <= f(mid - precision)) {
            right = mid; // Adjust right boundary
        } else if (f(mid) <= f(mid + precision) && f(mid) > f(mid - precision)) {
            left = mid; // Adjust left boundary
        }
        p++;
    }
            printf("%f",f(mid));


    return 0;
}
