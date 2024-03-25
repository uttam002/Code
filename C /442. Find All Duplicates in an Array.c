int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* duplicates = malloc(numsSize * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) duplicates[(*returnSize)++] = abs(nums[i]);
        else nums[index] *= -1;
    }
    return duplicates;
}
