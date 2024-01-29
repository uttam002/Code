class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int count = 0;

        // Calculate the prefix sum for each row
        for (int row = 0; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        // Iterate over all possible submatrices
        for (int col1 = 0; col1 < cols; col1++) {
            for (int col2 = col1; col2 < cols; col2++) {
                int[] prefixSumCount = new int[rows + 1];
                prefixSumCount[0] = 1; // Initialize with one element for the zero prefix sum
                int currentSum = 0;

                // Iterate over all rows
                for (int row = 0; row < rows; row++) {
                    // Calculate the sum of the submatrix using prefix sum
                    int submatrixSum = matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                    currentSum += submatrixSum;

                    // Check if there exists a submatrix with the target sum
                    count += prefixSumCount[currentSum - target];

                    // Update the prefix sum count
                    prefixSumCount[currentSum]++;
                }
            }
        }

        return count;
    }
}
