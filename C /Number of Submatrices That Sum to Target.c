int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target) {
  
    // Allocate memory for an auxiliary 2D array 'list'
  
    int** list = malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        list[i] = calloc((*matrixColSize), sizeof(int));
    }

    // Calculate prefix sums for each row in the original matrix
  
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 1; j < *matrixColSize; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    int ans = 0;  // Count of submatrices with the target sum
    int count = 0;

    // Iterate through all possible submatrix heights (count)
  
    while (count < matrixSize) {
        // Update 'list' with accumulated sums for current submatrix height
        for (int i = 0; i + count < matrixSize; i++) {
            for (int j = 0; j < *matrixColSize; j++) {
                list[i][j] += matrix[i + count][j];
            }
        }

        // Check for single-row submatrices with the target sum
      
        for (int i = 0; i + count < matrixSize; i++) {
            for (int j = 0; j < *matrixColSize; j++) {
                if (list[i][j] == target) {
                    ans++;
                }
            }
        }
      
        // Check for multi-row submatrices with the target sum
      
        for (int i = 0; i + count < matrixSize; i++) {
            for (int k = 0; k < *matrixColSize; k++) {
                for (int j = k + 1; j < *matrixColSize; j++) {
                    if (list[i][j] - list[i][k] == target) {
                        ans++;
                    }
                }
            }
        }

        count++;  // Move to the next submatrix height
    }

    // Free the allocated memory
    for (int i = 0; i < matrixSize; i++) {
        free(list[i]);
    }
    free(list);

    return ans;
}
