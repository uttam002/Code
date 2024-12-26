public class Solution {
     public int FindTargetSumWays(int[] nums, int target) => Helper(nums, 0, target, 0);
    private int Helper(int[] nums, int index, int target, int count) => index == nums.Length ? count + (target == 0 ? 1 : 0) : Helper(nums, index + 1, target - nums[index], count) + Helper(nums, index + 1, target + nums[index], count);
}
