

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int i;
    *returnSize = numsSize;
    int *result = (int *)malloc(sizeof(int)*numsSize);
    result[0] = 1;
    for(i=1; i<numsSize; i++) {
        result[i] = nums[i-1] * result[i-1];
    }
    int t = 1;
    for(i=numsSize-1; i>=0; i--) {
        result[i] *= t;
        t *= nums[i];
    }
    return result;
}
