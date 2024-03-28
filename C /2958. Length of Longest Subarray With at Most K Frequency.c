int maxSubarrayLength(int* nums, int numsSize, int k) {
   
    int min = INT_MAX, max = INT_MIN,j = 0, res = 0;
     for (int i = 0; i < numsSize; i++) {
        min = nums[i] < min ? nums[i] : min;
        max = nums[i] > max ? nums[i] : max;
    }

    int* count = (int*)calloc(max - min + 1, sizeof(int));
    for (int i=0;i < numsSize;i++) {
        count[nums[i]-min]++;
        while (count[nums[i]-min] > k)
            count[nums[j++]-min]--;
        res = res > i - j + 1 ? res : i - j + 1;
    }
    return res;
}
