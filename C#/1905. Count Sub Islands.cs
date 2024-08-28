public class Solution {
    public int CountSubIslands(int[][] grid1, int[][] grid2) {
        int rows = grid2.Length;
        int cols = grid2[0].Length;
        int subIslandCount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Start a DFS if we find a land cell in grid2
                if (grid2[i][j] == 1) {
                    // Check if the current island in grid2 is a sub-island
                    if (IsSubIsland(grid1, grid2, i, j, rows, cols)) {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }

    private bool IsSubIsland(int[][] grid1, int[][] grid2, int i, int j, int rows, int cols) {
        // If out of bounds or water in grid2, return true (it's part of a sub-island by default)
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid2[i][j] == 0) {
            return true;
        }

        // If grid2 has land but grid1 does not, this cannot be a sub-island
        if (grid1[i][j] == 0) {
            return false;
        }

        // Mark the cell as visited in grid2
        grid2[i][j] = 0;

        // Continue DFS in all 4 directions
        bool left = IsSubIsland(grid1, grid2, i, j - 1, rows, cols);
        bool right = IsSubIsland(grid1, grid2, i, j + 1, rows, cols);
        bool up = IsSubIsland(grid1, grid2, i - 1, j, rows, cols);
        bool down = IsSubIsland(grid1, grid2, i + 1, j, rows, cols);

        // Return true only if all parts of this island are sub-islands
        return left && right && up && down;
    }
}
