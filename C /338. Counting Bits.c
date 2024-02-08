/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n + 1;
    int* result = (int*) malloc(*returnSize * sizeof(int));
    result[0] = 0;
    for (int i = 1; i < *returnSize; i++) 
        result[i] = (i & 1) + result[i >> 1];
    return result;
}
