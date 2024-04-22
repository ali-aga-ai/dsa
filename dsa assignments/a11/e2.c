#include <stdio.h>
#include <limits.h>

// Function to find the minimum removals
// to make the bitwise AND of range non-zero
void solve_queries(int queries[][2], int num_queries) {
    for (int i = 0; i < num_queries; i++) {
        int l = queries[i][0];
        int r = queries[i][1];

        // Initialize the max_set to check
        // what count of set bit majority of
        // numbers in the range was set
        int max_set = 0;
        for (int bit = 0; bit < sizeof(int) * CHAR_BIT; bit++) {
            int cnt = 0;
            for (int j = l; j <= r; j++) {

                // Check if bit is set
                if ((1 << bit) & j) {
                    cnt++;
                }
            }
            max_set = (cnt > max_set) ? cnt : max_set;
        }

        // Total length of range - count of
        // max numbers having 1 bit set in range
        printf("%d ", (r - l + 1) - max_set);
    }
}

// Driver Code
int main() {
    // Initialize the queries
    int queries[][2] = {{2, 8}, {4, 5}, {5, 6}, {100000, 200000}};
    int num_queries = sizeof(queries) / sizeof(queries[0]);

    solve_queries(queries, num_queries);
    return 0;
}
