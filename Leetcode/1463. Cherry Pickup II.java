public class Solution {
    public int cherryPickup(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        
        // Create a DP array to store the maximum cherries collected
        int[][][] dp = new int[rows][cols][cols];
        
        // Initialize the DP array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        
        // Start from the bottom row and iterate upwards
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                for (int j2 = 0; j2 < cols; j2++) {
                    // Calculate cherries collected from cell (i, j) to bottom row
                    int cherries = grid[i][j];
                    if (j != j2) {
                        cherries += grid[i][j2];
                    }
                    if (i != rows - 1) {
                        int max = 0;
                        // Try all possible moves for both robots
                        for (int k = j - 1; k <= j + 1; k++) {
                            for (int k2 = j2 - 1; k2 <= j2 + 1; k2++) {
                                if (k >= 0 && k < cols && k2 >= 0 && k2 < cols) {
                                    max = Math.max(max, dp[i + 1][k][k2]);
                                }
                            }
                        }
                        cherries += max;
                    }
                    dp[i][j][j2] = cherries;
                }
            }
        }
        
        // Return maximum cherries collected from the top row
        return dp[0][0][cols - 1];
    }
}
