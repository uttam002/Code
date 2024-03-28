class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
       int ans = 0;
    HashMap<Integer, Integer> freqMap = new HashMap<>();
    int left = 0;

    for (int right = 0; right < nums.length; right++) {
        freqMap.put(nums[right], freqMap.getOrDefault(nums[right], 0) + 1);

        while (freqMap.get(nums[right]) > k) {
            freqMap.put(nums[left], freqMap.get(nums[left]) - 1);
            if (freqMap.get(nums[left]) == 0) {
                freqMap.remove(nums[left]);
            }
            left++;
        }

        ans = Math.max(ans, right - left + 1);
    }

    return ans;
    }
}
