class Solution {
    public int missingNumber(int[] nums) {
     int left=0,right=nums.length-1;
    int sum=0;
      while (left <= right) 
            sum += nums[left++] + nums[right--];
        
        if (nums.length % 2 != 0) 
            sum += nums[nums.length / 2];
        
        return nums.length*(nums.length+1)/2 - sum;  
    }
}
