
// Comparator function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort the input array
    qsort(nums, numsSize, sizeof(int), cmp);

    // Dynamic programming to find the largest subset
    int** dp = (int**)malloc(numsSize * sizeof(int*));
    int* dp_sizes = (int*)malloc(numsSize * sizeof(int));
    int maxIdx = 0;

    for (int i = 0; i < numsSize; i++) {
        dp[i] = (int*)malloc(sizeof(int));
        dp[i][0] = nums[i];
        dp_sizes[i] = 1;

        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && 1 + dp_sizes[j] > dp_sizes[i]) {
                dp[i] = (int*)realloc(dp[i], (1 + dp_sizes[j]) * sizeof(int));
                dp[i][dp_sizes[j]] = nums[i];
                dp_sizes[i] = 1 + dp_sizes[j];
            }
        }

        if (dp_sizes[i] > dp_sizes[maxIdx]) {
            maxIdx = i;
        }
    }

    *returnSize = dp_sizes[maxIdx];
    free(dp_sizes);
    return dp[maxIdx];
}
