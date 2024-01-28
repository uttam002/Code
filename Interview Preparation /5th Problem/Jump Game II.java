class Solution {
    public boolean canJump(int[] nums) {
        int index = nums.length-1;
        for(int i = nums.length - 1;i >= 0;i--){
            int j = nums[i] + i;
            if(j >= index) index = i;
    }
    return index == 0;
    }
}
