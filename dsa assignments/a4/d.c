//COPIED

#include <stdio.h>

#define N 9

int isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not present in the current row and column
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return 0;
        }
    }

    // Check if the number is not present in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == -1) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;

                        if (solveSudoku(grid)) {
                            return 1;
                        }

                        grid[row][col] = -1; // Backtrack if the current assignment doesn't lead to a solution
                    }
                }
                return 0; // If no number can be placed, backtrack
            }
        }
    }

    return 1; // Sudoku solved
}

void printSudoku(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N];

    // Input Sudoku
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solveSudoku(grid)) {
        printSudoku(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
