/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
      int* result = (int*)malloc(numsSize * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL; // Memory allocation failed
    }
      int x=-2,y=-1;
      for(int i=0;i<numsSize;i++){
          if(nums[i]>0)result[x+=2]=nums[i];
          else result[y+=2]=nums[i];
      }
      *returnSize=numsSize;
      return result;
}
