import java.util.*;

class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] res = new int[nums.length];
        int l = 0, r = nums.length - 1;
        
        for (int i = nums.length - 1; i >= 0; i--) {
            if (Math.abs(nums[r]) > Math.abs(nums[l])) {
                res[i] = nums[r] * nums[r];
                r--;
            } else {
                res[i] = nums[l] * nums[l];
                l++;
            }
        }
        
        return res;
    }
}
