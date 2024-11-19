class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long maxSum = 0, currentSum = 0;
        int left = 0;
        Set<Integer> uniqueElements = new HashSet<>();

        for (int right = 0; right < nums.length; right++) {
            while (uniqueElements.contains(nums[right]) || uniqueElements.size() >= k) {
                uniqueElements.remove(nums[left]);
                currentSum -= nums[left++];
            }
            uniqueElements.add(nums[right]);
            currentSum += nums[right];
            if (uniqueElements.size() == k) {
                maxSum = Math.max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
}
