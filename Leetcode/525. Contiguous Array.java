import java.util.Arrays;

class Solution {
    public int findMaxLength(int[] nums) {
        int result = 0, sum = 0, maxi = 0;
        int[] mp = new int[nums.length * 2 + 1];
        Arrays.fill(mp, -2);
        
        mp[nums.length] = -1;
        
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (mp[sum + nums.length] != -2) {
                maxi = Math.max(maxi, i - mp[sum + nums.length]);
            } else {
                mp[sum + nums.length] = i;
            }
        }
        
        result = maxi;
        return result;
    }
}
