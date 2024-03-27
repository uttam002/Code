int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int count = 0,product = 1,left = 0;

    for (int right = 0; right < numsSize; right++) {
        product *= nums[right];
        while (product >= k && left <= right) {
            product /= nums[left];
            left++;
       }
        count += right - left + 1;
    }
    return count;
}
