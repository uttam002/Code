int subarraysWithKDistinct(int* nums, int numsSize, int k) {
    
    int freq[numsSize+1]; 
    for(int i=0;i<=numsSize;i++)freq[i]=0;
    int left = 0, start = 0, count = 0;
    
    for (int end = 0; end < numsSize; end++) {
        if (freq[nums[end]]++ == 0) {
            if (--k < 0) {
                freq[nums[start++]] = 0;
                left = start;
            }
        }
        if (k <= 0) {
            while (freq[nums[start]] > 1) freq[nums[start++]]--;
            count += start - left + 1;
        }
    }
    
    return count;
}
