#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ci = 1, ri = 0, cd = 0, rd = 0;
    int a[n][n];

    // Initialize the matrix to zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    int r = 0, c = 0;
    int p = 1;

    while (p <= n * n) {
        if (ci) {
            if (c < n && a[r][c] == 0) {
                a[r][c++] = p++;
            } else {
                c--; r++; // Adjust back and move down
                ci = 0; ri = 1;
            }
        } else if (ri) {
            if (r < n && a[r][c] == 0) {
                a[r++][c] = p++;
            } else {
                r--; c--; // Adjust back and move left
                ri = 0; cd = 1;
            }
        } else if (cd) {
            if (c >= 0 && a[r][c] == 0) {
                a[r][c--] = p++;
            } else {
                c++; r--; // Adjust back and move up
                cd = 0; rd = 1;
            }
        } else if (rd) {
            if (r >= 0 && a[r][c] == 0) {
                a[r--][c] = p++;
            } else {
                r++; c++; // Adjust back and move right
                rd = 0; ci = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
