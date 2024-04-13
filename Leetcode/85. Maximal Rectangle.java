class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        
        int m = matrix.length;
        int n = matrix[0].length;
        int[] heights = new int[n];
        int[] left = new int[n]; // Store left boundary index for each height
        int[] right = new int[n]; // Store right boundary index for each height
        Arrays.fill(right, n); // Initialize right boundary to the end
        
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            int currLeft = 0;
            // Update heights array dynamically and left boundary
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
                if (matrix[i][j] == '1') {
                    left[j] = Math.max(left[j], currLeft);
                } else {
                    left[j] = 0;
                    currLeft = j + 1;
                }
            }
            
            int currRight = n;
            // Update right boundary
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = Math.min(right[j], currRight);
                } else {
                    right[j] = n;
                    currRight = j;
                }
            }
            
            // Calculate max area for the current row
            for (int j = 0; j < n; j++) {
                maxArea = Math.max(maxArea, heights[j] * (right[j] - left[j]));
            }
        }
        
        return maxArea;
    }
}
