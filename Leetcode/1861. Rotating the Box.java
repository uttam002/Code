class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length;
        int n = box[0].length;

        // Simulate gravity for each row
        for (int i = 0; i < m; i++) {
            int emptySpot = n - 1; // Start from the rightmost position
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    // Move stone to the lowest possible position
                    box[i][j] = '.';
                    box[i][emptySpot] = '#';
                    emptySpot--;
                } else if (box[i][j] == '*') {
                    // Obstacle resets the empty spot
                    emptySpot = j - 1;
                }
            }
        }

        // Create the rotated box
        char[][] rotatedBox = new char[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }

        return rotatedBox;
    }
}
