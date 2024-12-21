#include <stdio.h>

void multiply(int n, int a[][n], int b[][n]){
    int result[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            result[i][j] = 0;
            for(int k=0; k<n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // Copy the elements of the result matrix back to array a
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = result[i][j];
        }
    }
}

void matrix_exponentiation(int n, int a[][n], int p) {
    int result[n][n];


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                result[i][j] = 1; // Initialize result matrix as identity matrix
            else
                result[i][j] = 0;
        }
    }

    
    while(p > 0) {
        if(p % 2 != 0) {
            multiply(n, result, a);//multiply multiplies two n*n matrices
        }
        multiply(n, a, a);
        p /= 2;
    }


    // Copy the elements of the result matrix back to array a
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = result[i][j];
        }
    }
}

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    int a[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    matrix_exponentiation(n, a, p);

    // Print the resulting matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
