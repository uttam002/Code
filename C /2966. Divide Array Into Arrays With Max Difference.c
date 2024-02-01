// Comparison function for qsort
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Function to divide array into subarrays of size 3
int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    // Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), cmp);

    // Calculate the number of subarrays needed
    *returnSize = numsSize / 3;

    // Allocate memory for storing subarrays and their sizes
    int **arr = (int **)malloc(sizeof(int *) * (*returnSize));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));

    // Iterate through the sorted array and create subarrays
    for (int i = 0, arrIdx = 0; i < numsSize; i += 3) {
        // Check if the conditions are satisfied
        if (nums[i + 2] - nums[i] > k) {
            *returnSize = 0; // Set returnSize to 0 indicating failure
            return NULL;
        } else {
            // Store the subarray and its size
            (*returnColumnSizes)[arrIdx] = 3;
            arr[arrIdx] = (int *)malloc(sizeof(int) * 3);
            arr[arrIdx][0] = nums[i];
            arr[arrIdx][1] = nums[i + 1];
            arr[arrIdx][2] = nums[i + 2];
            arrIdx++;
        }
    }

    return arr;
}
