public class Solution {
    public char[][] RotateTheBox(char[][] box) {
        int m = box.Length, n = box[0].Length;
        char[][] result = new char[n][];
        for (int i = 0; i < n; i++) {
            result[i] = new char[m];
            for (int j = 0; j < m; j++) {
                result[i][j] = '.'; // Initialize to empty
            }
        }

        for (int i = 0; i < m; i++) {
            int emptySpot = n - 1; // Position for the next stone to fall
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    // Obstacle: Reset the empty spot
                    result[j][m - i - 1] = '*';
                    emptySpot = j - 1;
                } else if (box[i][j] == '#') {
                    // Stone: Move it to the empty spot
                    result[emptySpot--][m - i - 1] = '#';
                }
            }
        }

        return result;
    }
}
