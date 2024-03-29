long long countSubarrays(int* nums, int numsSize, int k) {
    int min = INT_MAX, max = INT_MIN,j = 0;
     for (int i = 0; i < numsSize; i++) {
        max = nums[i] > max ? nums[i] : max;
    }
    long long res = 0;
    for (int i=0;i < numsSize;i++) {
        k-=(max==nums[i]);
        while (k==0)
            k+=(max==nums[j++]);
       res+=j;
    }
    return res;
}
