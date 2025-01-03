public class Solution {
    public int WaysToSplitArray(int[] nums) {
        long leftSum = 0, rightSum = nums.Select(x => (long)x).Sum(); // Use long for the sum
        int ans = 0;
        for (int i = 0; i < nums.Length - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            if (leftSum >= rightSum) ans++;
        }
        return ans;
    }
}
