#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the maximum of two integers
int Max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum cherries collected
int cherryPickup(int **grid, int gridSize, int* gridColSize) {
    int C = *gridColSize;
    int dp[gridSize][C][C];

    memset(dp, -1, sizeof(dp)); // Initializing dp array with -1

    // Setting base case
    dp[0][0][C - 1] = grid[0][0] + grid[0][C - 1];

    for (int r = 1; r < gridSize; r++) {
        for (int c1 = 0; c1 < C; c1++) {
            for (int c2 = 0; c2 < C; c2++) {
                int max = -1;
                for (int i = c1 - 1; i <= c1 + 1; i++) {
                    for (int j = c2 - 1; j <= c2 + 1; j++) {
                        if (i >= 0 && i < C && j >= 0 && j < C && i <= j) {
                            if (dp[r - 1][i][j] != -1) {
                                max = Max(max, dp[r - 1][i][j]);
                            }
                        }
                    }
                }
                if (max != -1) {
                    dp[r][c1][c2] = Max(dp[r][c1][c2], max + grid[r][c1] + (c1 == c2 ? 0 : grid[r][c2]));
                }
            }
        }
    }

    int maxCherries = -1;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            maxCherries = Max(maxCherries, dp[gridSize - 1][i][j]);
        }
    }
    return maxCherries;
}
