class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        // Set to store the positions of walls
        Set<String> wallSet = new HashSet<>();
        for (int[] wall : walls) {
            wallSet.add(wall[0] + "," + wall[1]);
        }

        // Set to store the positions of guards
        Set<String> guardSet = new HashSet<>();
        for (int[] guard : guards) {
            guardSet.add(guard[0] + "," + guard[1]);
        }

        // Directions for movement: north, east, south, west
        int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Set to keep track of all guarded positions
        Set<String> guarded = new HashSet<>();

        // Function to mark all cells visible to a guard in all four directions
        for (int[] guard : guards) {
            for (int[] dir : directions) {
                int r = guard[0], c = guard[1];
                while (true) {
                    r += dir[0];
                    c += dir[1];
                    if (r < 0 || r >= m || c < 0 || c >= n || wallSet.contains(r + "," + c) || guardSet.contains(r + "," + c)) {
                        break; // Stop if we hit a wall or another guard
                    }
                    guarded.add(r + "," + c); // Mark the cell as guarded
                }
            }
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!wallSet.contains(r + "," + c) && !guardSet.contains(r + "," + c) && !guarded.contains(r + "," + c)) {
                    unguardedCount++;
                }
            }
        }

        return unguardedCount;
    }
}
