class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        long sum=0;
        for(int x:nums) sum+=x;
        for(int i=nums.length - 1;i>=0;i--){
            sum-=nums[i];
            if(nums[i]<sum)return sum+=nums[i];
        }

        return -1;
    }
}
